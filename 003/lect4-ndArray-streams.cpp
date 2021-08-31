// Copyright 2021 Casey Cole
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;

const int COL = 2;

// Function prototypes go here
void print2dArray(const int arr[][COL], int);
void print1DArray(int[], int);

int main(int argc, char **argv) {
    // ND Arrays in Functions
    int arr2[2];
    int arr[2][2] = {{1, 1}, {2, 2}};
    // print2dArray(arr, 2);
    // Cin and getline()
    // https://www.cplusplus.com/reference/string/string/getline/
    // string line;
    // cin >> line;
    // getline(cin, line);
    // cout << line << "\n";
    // Stringsteams
    // Exercise: Read in a string with a number in it and
    // use a stringstream to parse out the number.
    int num;
    // cout << "Enter a line with a number: ";
    // getline(cin, line);
    // std::stringstream s(line);
    // s >> num;
    // cout << "Num dollars: " << num;

    // printf - The pretty way to print
    // https://www.cplusplus.com/reference/cstdio/printf/
    // printf("hello %s %s\n", printf("%s", "Casey"), "Cole");

    // Reading from a file
    std::ifstream in("data.txt");
    if (in.is_open()) {
        cout << "File exists and is open.\n";
        string line;
        while (getline(in, line)) {
            cout << line << "\n";
        }
        in.close();
    }
    // Writing to a file
    std::ofstream out("data.txt", std::ofstream::app);
    out << "Hello\n";
    out.close();
    // Exercise: What if the file is CSV?
    // More on files: https://www.cplusplus.com/doc/tutorial/files/

    return 0;
}

void print2dArray(const int arr[][COL], int rows) {
    // COL = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COL; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}