#include <boost/asio.hpp>
#include <iostream>
#include <iomanip>
#include <boost/range/istream_range.hpp>

namespace ip = boost::asio::ip;

int main() {
    boost::asio::io_context io;
    boost::asio::ip::tcp::resolver r(io);

    for (auto q : {
            boost::asio::ip::tcp::resolver::query 
            // these are good:
            {"google.com", ""},              // port 0
            {"google.com", "ftp"},           // port 21
            {"google.com", "80"},            // port 80
            // these ar bad:
            {"google.ggg", ""},              // host not found
            {"google.com", "bogus_service"}, // service not found
            {"google.com", "-1"},            // service not found
            {"", ""},                        // host not found
        })
    {
        try
        {
            for (auto ep : boost::make_iterator_range(r.resolve(q), {}))
                std::cout << std::quoted(q.host_name()) << " -> " << ep.endpoint() << "\n";
        } catch(std::exception const& e) {
            std::cout << std::quoted(q.host_name()) << " " << e.what() << "\n";
        }
    }

    std::cout<<"Hostname of this computer is "<<ip::host_name()<<std::endl;

}