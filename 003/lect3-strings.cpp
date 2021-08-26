// Copyright 2021 Casey Cole
#include <iostream>

using std::string;
using std::cout;
using std::cin;

int main(int argc, char **argv) {
    // Declaring a string
    string hello = "hello world!";
    string bye("bye");
    // cout.operator<<(hello);
    // cout << hello << "\n";

    // How many bytes?
    // cout << sizeof(hello) << "\n";
    // cout << sizeof(bye) << "\n";

    // // Printing the length of the string
    // cout << hello.size() << "\n";
    // cout << hello.length() << "\n"; 
    // // Concatenation of strings
    // cout << hello + bye << "\n";
    // // Remember: you can't mix types

    // // Accessing and modifying strings
    // cout << hello[0] << "\n";
    // hello[0] = 'p';
    // cout << hello << "\n";
    // // User inputted strings
    // // Remember: white space is a terminal character to C++
    // cout << "Give me a string: ";
    // cin >> hello;
    // cout << "New value: "<< hello;
    // // Array of strings
    string str_array[2];
    // // Read in the array from std::cin
    // // We can hard code the length... or we can use this 
    // // trick ->
    // cout << "size of array: " << sizeof(str_array) << "\n";
    // cout << sizeof(str_array) / sizeof(str_array[0]) << "\n";
    // int size = sizeof(str_array) / sizeof(str_array[0]);
    // for(int i = 0; i < size; i++) {
    //     cout << "Enter a string: ";
    //     cin >> str_array[i];
    // }

    // Print them out
    // cout << str_array;  // ?
    
    // Let's talk more about memory
    // Print out the memory locations of the array
    cout << str_array << "\n";
    cout << &str_array[0] << "\n";
    cout << &str_array[1] << "\n";
    // Does this make sense?
    // Remember the size of the strings?
    // Contiguous memory!
    return 0;
}

