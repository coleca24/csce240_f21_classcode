// Copyright 2021 Casey Cole
// Single level inheritance Vehicle, Car
// Multi-level Vehicle, Car, Tesla
// Multiple inheritance Vehicle, FourWheels, Car
// Multi-Path Graphic, Barchart (graphic), LineChart (graphic),
// HybridChart (bar,line)
//    class scope resolution LineChart::res
//    virtual base class (variables shared between base classes)
//        : virtual public Graphic
// Revisit function overriding... now with polymorphism
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class Vehicle {
 public:
    Vehicle() {
        numberWheels = 4;
    }
    void print() {
        cout << "Number of Wheels: " << numberWheels << endl;
    }
 private:
    int numberWheels;
};

class Car : public Vehicle {
 public :
        Car() {
            mpg = 20.0;
        }
        void print() {
            Vehicle::print();
            cout << "MPG: " << mpg << endl;
        }
 private :
        float mpg;
};

int main(int argc, char** argv) {
    Car c1;
    c1.print();

    // Vehicle v1 = c1;
    // v1.print();

    // Vehicle *v1 = &c1;
    // v1->print();
    return 0;
}
