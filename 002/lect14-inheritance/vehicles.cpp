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
        // cout << "vehicle const\n";
        numberWheels = 0;
    }
    explicit Vehicle(int nw) {
        numberWheels = nw;
    }
    // virtual void print() {
    //     cout << "In Vehicle\n";
    //     cout << "Number of Wheels: " << numberWheels << endl;
    // }
    virtual void print() = 0;
 protected:
    int getNumWheels() {
        return numberWheels;
    }
 private:
    int numberWheels;
};

class Car : public Vehicle {
 public :
        explicit Car(float f) : Vehicle(4) {
            // cout << "car const\n";
            mpg = f;
        }
        void print() {
            // cout << "Number of Wheels: " << getNumWheels() << endl;
            cout << "In Car\n";
            Vehicle::print();
            cout << "MPG: " << mpg << endl;
        }
 private :
        float mpg;
};

class Tesla : public Car /*, public Battery*/ {
 public:
        Tesla() : Car(0.0) {
            mpkv = 60.5;
        }
        void print() {
            cout << "In Tesla\n";
            Car::print();
            cout << "MPKV: "<< mpkv << "\n";
        }
 private:
        float mpkv;
};

int main(int argc, char** argv) {
    Car c1(4);
    // c1.print();
    Tesla t;
    // t.print();
    // c1.numberWheels;
    // Vehicle v1 = Car(20.0);
    // v1.print();
    Car *c2 = &t;
    c2->print();
    // Vehicle *v1 = &c1;
    // v1->print();
    return 0;
}
