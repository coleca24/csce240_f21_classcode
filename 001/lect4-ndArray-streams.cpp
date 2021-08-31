// Copyright 2021 Casey Cole
#include <iostream>
#include <sstream>
#include <fstream>
// #include "nameoffile.h"

using std::string;
using std::cout;

// Function prototypes go here
// void print1dArray(int arr[]);
const int COLS = 2;
void print2dArray(const int arr[][COLS], int);
bool checkforfile(string);

int main(int argc, char **argv) {
    // ND Arrays in Functions
    int arr[2][2] = {{1, 1}, {2, 2}};
    // print2dArray(arr, 2);
    // Cin and getline()
    // https://www.cplusplus.com/reference/string/string/getline/
    string str;
    // std::cin >> str;
    // str =
    // std::getline(std::cin, str);
    // std::cout << "str: " << str << "\n";




    // printf - The pretty way to print
    // https://www.cplusplus.com/reference/cstdio/printf/
    // printf("hello %s %s\n", "1", "Cole");
    // printf("test");

    // Reading from a file
    std::ifstream in("data.txt");
    if (in.is_open()) {
        cout << "File exists and is open\n";
        string line;
        while (getline(in, line)) {
            // read csv
            // stringstream
            // "1,2,3,4"
            // getline("1,2,3,4", str, ',')
            cout << line << "\n";
        }
        in.close();
    } else {
        cout << "File does not exist or did not open\n";
    }
    // Writing to a file
    std::ofstream out("data.txt", std::ofstream::app);
    out << "Line 4\n";
    out.close();
    // Exercise: What if the file is CSV?
    // More on files: https://www.cplusplus.com/doc/tutorial/files/

    // More string utilities?

    return 0;
}

void print2dArray(const int arr[][COLS], int rows) {
    // arr[0][0] = 2;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}
