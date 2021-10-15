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
        numberWheels = 10;
    }
    explicit Vehicle(int nw) {
        numberWheels = nw;
    }
    virtual void print() {
        cout << "Number of Wheels: " << numberWheels << endl;
    }
    // virtual void print() = 0;
 private:
//  protected:
    int numberWheels;
};

class Car : public Vehicle {
 public :
        Car() : Vehicle(4) {
            mpg = 20.0;
        }
        Car(float mpg, int nw) : Vehicle(nw) {
            this->mpg = mpg;
        }
        void print() {
            Vehicle::print();
            cout << "MPG: " << mpg << endl;
        }
 private :
        float mpg;
};

class battery : public Vehicle {

};

class Tesla : public Car, public battery {
 public:
    void print() {
        cout << "Tesla\n";
    }
 private:
    float range;
};

int main(int argc, char** argv) {
    Car c1;
    // c1.print();
    // Tesla t;
    // t.print();
    Vehicle v1 = c1;
    v1.print();

    // Vehicle *v1 = &c1;
    // v1->print();
    return 0;
}
