//
//  main.cpp
//  PureVirtualFunction
//
//  Created by bsarvan on 30/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

class Pet {
public:
    virtual void speak() const = 0;
    virtual void eat() const = 0;
    // Inline pure virtual definitions illegal:
    //!  virtual void sleep() const = 0 {}
};
// OK, not defined inline
void Pet::eat() const {
    cout << "Pet::eat()" << endl;
}
void Pet::speak() const {
    cout << "Pet::speak()" << endl;
}
class Dog : public Pet {
public:
    // Use the common Pet code:
    void speak() const { Pet::speak(); }
    void eat() const { Pet::eat(); }
    
};


int main() {

    Dog simba;  // Richard's dog
    simba.speak();
    simba.eat();
} ///:~
