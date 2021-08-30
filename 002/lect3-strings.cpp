// Copyright 2021 Casey Cole
#include <iostream>
#include <string>

using std::string;
using std::cout;

int main(int argc, char **argv) {
    // Declaring a string
    string hello = "hello world!";
    string bye("bye");
    // cout.operator<<(hello);
    cout << hello << "\n";

    // How many bytes?
    // cout << sizeof(hello) << "\n";
    // cout << sizeof(bye) << "\n";

    // Printing the length of the string
    // cout << hello.length() << "\n";
    // cout << hello.size() << "\n";
    // Concatenation of strings
    // Remember: you can't mix types
    int i = 0;
    // string.operator+(int)
    // cout << hello + i << "\n";

    // Accessing and modifying strings
    cout << hello[0] << "\n";
    // User inputted strings
    // Remember: white space is a terminal character to C++
    string name;
    // cout << "Name: ";
    // std::cin >> name;
    // cout << "Variable name= " << name;

    // Array of strings
    string str_array[5];
    // Read in the array from std::cin
    int size = sizeof(str_array) / sizeof(str_array[0]);
    for (int i = 0; i < size; i++) {
        // std::cin >> str_array[i];
    }
    // cout << sizeof(str_array) / sizeof(str_array[0]) << "\n";
    // We can hard code the length... or we can use this trick ->
    // cout << sizeof(str_array) / sizeof(str_array[0]) << "\n";

    // Print them out
    cout << str_array << "\n";  // ?
    
    // Let's talk more about memory
    // Print out the memory locations of the array
    char char_array[5];
    cout << char_array << "\n";
    for (int i = 0; i <= 5; i++) {
        cout << "i=" << i << " loc: " << &str_array[i] << "\n";
    }
    // Does this make sense?
    // Remember the size of the strings?
    // Contiguous memory!
    return 0;
}

