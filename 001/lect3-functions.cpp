// Copyright 2021 Casey Cole
#include <iostream>

using std::string;
using std::cout;

// Function prototypes go here
void printHelloWorld();

void printString(const string&);

void printArray(const string[], int);

int add(int, int);
float add(float, float f2 = 10,  float );
// float add(float, float);
// int add(float, float);

int main(int argc, char **argv) {
    add(1.2,3.4);
    // Function calls go here
    // printHelloWorld();

    // More examples
    string hello = "hello";
    // TODO(class): Add function that prints the string
    // printString(hello);
    // cout << hello + "\n";
    // Those were all pass-by-value... changing the variable passed in 
    // does not change it out here in the main. 
    // What if I wanted to have the value reflected here?
    // TODO(class): Add function that fills in a string in the function.

    // What about functions and arrays?
    // Arrays are always call-by-reference
    // You cannot return an array from a function
    string str_arr[5];
    int size = sizeof(str_arr) / sizeof(str_arr[0]);
    for(int i = 0; i < size; i++){
        str_arr[i] = "null";
    }
    // TODO(class): Add function that reads in input from user
    printArray(str_arr, size);
    // const keyword

    // Overloading functions

    // Default values

    return 0;
}

// Function definitions go here
void printHelloWorld() {
    cout << "Hello World!\n";
}

void printString(const string & str) {
    // str = "bye";
    cout << str + "\n";
}

void printArray(const string arr[], int size) {
    //int size = sizeof(arr) / sizeof(arr[0]);
    //cout << sizeof(arr) << "\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << "\n";
    }
}

int add(int n1, int n2){
    cout << "int one\n";
}
float add(float n1, float n2){
    cout << "float one\n";
}