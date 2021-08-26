// Copyright 2021 Casey Cole
#include <iostream>

using std::string;
using std::cout;

// Function prototypes go here
void printHelloWorld();

void printString(const string&);

void printSize(string[]);
void printSize(int[]);
int add(int, int);
float add(float f1 = 10, float f2 = 10);
// int printSize(int[]);

int main(int argc, char **argv) {

    float f;
    f = add(1.2);
    // Function calls go here
    printHelloWorld();

    // More examples
    string hello = "hello";
    // TODO(class): Add function that prints the string
    printString(hello);
    cout << hello << "\n";
    // Those were all pass-by-value... changing the variable passed in 
    // does not change it out here in the main. 
    // What if I wanted to have the value reflected here?
    // TODO(class): Add function that fills in a string in the function.

    // What about functions and arrays?
    // Arrays are always call-by-reference
    // You cannot return an array from a function
    string str_arr[2];
    cout << "Size in main: " << sizeof(str_arr) << "\n";
    printSize(str_arr);
    // TODO(class): Add function that reads in input from user
    // const keyword

    // Overloading functions

    // Default values

    return 0;
}

// Function definitions go here
void printHelloWorld() {
    cout << "Hello World!\n";
}

void printString(const string & in) {
    // in = "bye";
    cout << in << "\n";
}

void printSize(string array[]) {
    cout << "Size in function: " << sizeof(array) << "\n";
}