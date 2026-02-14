#include <iostream>

class Base { public: virtual ~Base() {} }; // Virtual destructor makes it polymorphic
class Derived : public Base {};
class Enemy : public Base {};

int main() {
    Base* actualDerived = new Derived();
    Base* actualEnemy = new Enemy();

    // Try to cast the Enemy pointer into a Derived pointer
    // This is valid syntax, but logically wrong. dynamic_cast will catch it.
    Derived* p1 = dynamic_cast<Derived*>(actualEnemy);

    if (p1 == NULL) {
        std::cout << "Caught you! This Base pointer is NOT a Derived class." << std::endl;
    } else {
        std::cout << "Conversion successful." << std::endl;
    }

    delete actualDerived;
    delete actualEnemy;
    return 0;
}