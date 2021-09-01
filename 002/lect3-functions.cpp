// Copyright 2021 Casey Cole
#include <iostream>

using std::string;
using std::cout;

// Function prototypes go here
void printHelloWorld();
string printString(const string&);
void initValues(string[], int);

int add(int, int);
float add(float, float f = 1.0, float f3 = 1.0);

int main(int argc, char **argv) {
    // add(1, 3);
    // add(1,1);
    // add(1.2, 1.3);
    // add(1.2, 1.2);
    // Function calls go here
    printHelloWorld();

    // More examples
    string hello = "hello";
    // TODO(class): Add function that prints the string
    string output;
    output = printString(hello);
    cout << hello << "\n";
    // Those were all pass-by-value... changing the variable passed in
    // does not change it out here in the main.
    // What if I wanted to have the value reflected here?
    // TODO(class): Add function that fills in a string in the function.

    // What about functions and arrays?
    // Arrays are always call-by-reference
    // You cannot return an array from a function
    string str_arr[5];
    // TODO(class): Add function that reads in input from user
    int size = sizeof(str_arr) / sizeof(str_arr[0]);
    // initValues(str_arr, size);

    // const keyword

    // Overloading functions

    // Default values

    return 0;
}

// Function definitions go here
void printHelloWorld() {
    cout << "Hello World!\n";
}
string printString(const string & in) {
    // in = "bye";
    cout << in << "\n";
    return in;
}
void initValues(string str_arr[], int size) {
    // int size = sizeof(str_arr) / sizeof(str_arr[0]);
    // cout << "Size: " << sizeof(str_arr);
    for (int i = 0; i < size; i++) {
        cout << "Value:\n";
        std::cin >> str_arr[i];
    }
}

int add(int n1, int n2) {
    cout << "int add" << "\n";
    return n1 + n2;
}
float add(float n1, float n2) {
    cout << "float add" << "\n";
    return n1 + n2;
}
