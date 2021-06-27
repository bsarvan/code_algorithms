#include <iostream>
using namespace std;


class base {
public:
	base() {}
	virtual void printString() = 0;
	virtual void setString(string s) = 0;
};



class derived : public base {
	string firstname;
	base *baseHandler;
public:
	derived():baseHandler(nullptr) {}

	void setHandler(base &handler) {
		baseHandler = &handler;
	}


	base* getHandler() {
		return baseHandler;
	}
	
	void setString(string s) {
		firstname = s;
	}

	void printString() {
		cout<<firstname<<endl;
	}
};


int main() {
	cout<<"Program to test the handling of this pointer"<<endl;

	derived *obj = new derived();
	obj->setString("Bharat");
	obj->printString();
	obj->setHandler(*(base *)obj);


	base *obj2 = obj->getHandler();
	obj2->printString();

	return 0;

}