// Copyright 2021 Casey Cole
#include <iostream>

using std::string;
using std::cout;

int main(int argc, char **argv) {
    // Declaring a string
    string hello = "hello world!";
    string bye("bye");
    cout << hello << "\n";

    // How many bytes?
    // cout << sizeof(hello) << "\n";
    // cout << sizeof(bye) << "\n";

    // Printing the length of the string
    
    // Concatenation of strings
    // Remember: you can't mix types

    // Accessing and modifying strings

    // User inputted strings
    // Remember: white space is a terminal character to C++

    // Array of strings
    string str_array[5];
    // Read in the array from std::cin
    // We can hard code the length... or we can use this trick ->
    // cout << sizeof(str_array) / sizeof(str_array[0]) << "\n";

    // Print them out
    // cout << str_array;  // ?
    
    // Let's talk more about memory
    // Print out the memory locations of the array

    // Does this make sense?
    // Remember the size of the strings?
    // Contiguous memory!
    return 0;
}

