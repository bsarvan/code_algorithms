//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#include "stdafx.h"

// <toplevel>
#include <speechapi_cxx.h>
#include <fstream>
#include "wav_file_reader.h"

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;
// </toplevel>

void SpeechContinuousRecognitionWithPullStream()
{
    // First, define your own pull audio input stream callback class that implements the
    // PullAudioInputStreamCallback interface. The sample here illustrates how to define such
    // a callback that reads audio data from a wav file.
    // AudioInputFromFileCallback implements PullAudioInputStreamCallback interface, and uses a wav file as source
    class AudioInputFromFileCallback final : public PullAudioInputStreamCallback
    {
    public:
        // Constructor that creates an input stream from a file.
        AudioInputFromFileCallback(const string& audioFileName)
            : m_reader(audioFileName), read_count(0)
        {
        }

        // Implements AudioInputStream::Read() which is called to get data from the audio stream.
        // It copies data available in the stream to 'dataBuffer', but no more than 'size' bytes.
        // If the data available is less than 'size' bytes, it is allowed to just return the amount of data that is currently available.
        // If there is no data, this function must wait until data is available.
        // It returns the number of bytes that have been copied in 'dataBuffer'.
        // It returns 0 to indicate that the stream reaches end or is closed.
        int Read(uint8_t* dataBuffer, uint32_t size) override
        {
            read_count++;
			cout<<"Calling the Read method - "<<read_count<<endl;
            return m_reader.Read(dataBuffer, size);
        }
        // Implements AudioInputStream::Close() which is called when the stream needs to be closed.
        void Close() override
        {
			cout<<"Calling the Close Method"<<endl;
            m_reader.Close();
        }

    private:
        WavFileReader m_reader;
        int read_count;
    };

    // Creates an instance of a speech config with specified subscription key and service region.
    // Replace with your own subscription key and service region (e.g., "westus").
    auto config = SpeechConfig::FromSubscription("47d7bf0722884d02bf3fe4e3ba9c6d95", "westus2");

    // Creates a callback that will read audio data from a WAV file.
    // Currently, the only supported WAV format is mono(single channel), 16 kHZ sample rate, 16 bits per sample.
    // Replace with your own audio file name.
    auto callback = make_shared<AudioInputFromFileCallback>("whatstheweatherlike.wav");
    auto pullStream = AudioInputStream::CreatePullStream(callback);

    // Creates a speech recognizer from stream input;
    auto audioInput = AudioConfig::FromStreamInput(pullStream);
    auto recognizer = SpeechRecognizer::FromConfig(config, audioInput);

    // promise for synchronization of recognition end.
    promise<void> recognitionEnd;

#if 0
	recognizer->SpeechStartDetected.Connect([](const SpeechRecognitionEventArgs& e)
	{
		cout<<"Detected the Speech Start Events"<<std::endl;
	});
#endif
	recognizer->SessionStarted.Connect([&recognitionEnd](const SessionEventArgs& e)
    {
        cout << "Session Started."<<endl;
    });

    // Subscribes to events.
    recognizer->Recognizing.Connect([](const SpeechRecognitionEventArgs& e)
    {
        cout<<"Recognizing:"<<e.Result->Text<<std::endl;
    });

    recognizer->Recognized.Connect([] (const SpeechRecognitionEventArgs& e)
    {
        if (e.Result->Reason == ResultReason::RecognizedSpeech)
        {
            cout << "RECOGNIZED: Text=" << e.Result->Text << std::endl
                 << "  Offset=" << e.Result->Offset() << std::endl
                 << "  Duration=" << e.Result->Duration() << std::endl;
        }
        else if (e.Result->Reason == ResultReason::NoMatch)
        {
            cout << "NOMATCH: Speech could not be recognized." << std::endl;
        }
    });

    recognizer->Canceled.Connect([&recognitionEnd](const SpeechRecognitionCanceledEventArgs& e)
    {
        switch (e.Reason)
        {
        case CancellationReason::EndOfStream:
            cout << "CANCELED: Reach the end of the file." << std::endl;
            break;

        case CancellationReason::Error:
            cout << "CANCELED: ErrorCode=" << (int)e.ErrorCode << std::endl;
            cout << "CANCELED: ErrorDetails=" << e.ErrorDetails << std::endl;
            recognitionEnd.set_value();
            break;

        default:
            cout << "unknown reason ?!" << std::endl;
        }
    });

    recognizer->SessionStopped.Connect([&recognitionEnd](const SessionEventArgs& e)
    {
        cout << "Session stopped."<<endl;
        recognitionEnd.set_value(); // Notify to stop recognition.
    });

    // Starts continuous recognition. Uses StopContinuousRecognitionAsync() to stop recognition.
    recognizer->StartContinuousRecognitionAsync().wait();

    // Waits for recognition end.
    recognitionEnd.get_future().wait();

    // Stops recognition.
    recognizer->StopContinuousRecognitionAsync().wait();
}

