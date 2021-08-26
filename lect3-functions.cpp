// Copyright 2021 Casey Cole
#include <iostream>

using std::string;
using std::cout;

// Function prototypes go here
void printHelloWorld();

int main(int argc, char **argv) {
    // Function calls go here
    printHelloWorld();

    // More examples
    string hello = "hello";
    // TODO(class): Add function that prints the string

    // Those were all pass-by-value... changing the variable passed in 
    // does not change it out here in the main. 
    // What if I wanted to have the value reflected here?
    // TODO(class): Add function that fills in a string in the function.

    // What about functions and arrays?
    // Arrays are always call-by-reference
    // You cannot return an array from a function
    string str_arr[5];
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