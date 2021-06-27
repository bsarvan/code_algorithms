//Testing Promise data type

#include <iostream>
#include <vector>
#include <thread>
#include <future>
using namespace std;

/*
	Description of creating a promise object

	A promise is an object that can store a value of type T to be retrieved by a future object (possibly in another thread), offering a synchronization point.

	On construction, promise objects are associated to a new shared state on which they can store either a value of type T or an exception derived from std::exception.

	This shared state can be associated to a future object by calling member get_future. After the call, both objects share the same shared state:
	- The promise object is the asynchronous provider and is expected to set a value for the shared state at some point.
	- The future object is an asynchronous return object that can retrieve the value of the shared state, waiting for it to be ready, if necessary.
*/


void print_int(future<int> &val) {
	int x = val.get();
	cout<<"Value is "<<x<<endl;
}


int main() {
	promise<int> prom;

	future<int> fut = prom.get_future();

	thread th1 (print_int, ref(fut));
	prom.set_value(10);

	th1.join();
	return 0;
}