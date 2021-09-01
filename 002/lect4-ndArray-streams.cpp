// Copyright 2021 Casey Cole
#include <iostream>
#include <sstream>
#include <fstream>

using std::string;
using std::cout;
using std::cin;

const int COLS = 2;

// Function prototypes go here
void print2dArray(int arr[][COLS], int);
void print1dArray(int arr[], int);

int main(int argc, char **argv) {
    int arr1d[2] = {1, 2};
    // print1dArray(arr1d, 2);
    // ND Arrays in Functions
    int arr[2][2] = {{1, 1}, {2, 2}};

    // Cin and getline()
    // https://www.cplusplus.com/reference/string/string/getline/
    string line;
    // cin >> line;
    // line =
    // getline(cin, line);
    // cout << "Line: " << line << "\n";

    // Stringsteams
    std::string test = "hello how are you";
    string token;
    std::stringstream s(test);
    // getline(){
    //     token = next string;
    // }
    while (getline(s, token, ' ')) {
        cout << token << "\n";
        printf("%s", token.c_str());
    }
    // printf - The pretty way to print
    // https://www.cplusplus.com/reference/cstdio/printf/
    printf("hello %s\t%i\t %s\n", "Casey", 10, "%s");

    // Reading from a file
    std::ifstream in("./files/data.txt");
    line = "";
    if (in.is_open()) {
        while (getline(in, line)) {
            printf("%s\n", line.c_str());
        }
    } else {
        cout << "no file\n";
    }
    in.close();
    // Writing to a file
    std::ofstream out("./files/data2.txt", std::ofstream::app);
    if (out.is_open()) {
        out << "Hello\n";
    }
    out.close();
    // Exercise: What if the file is CSV?
    // More on files: https://www.cplusplus.com/doc/tutorial/files/

    // More string utilities?

    return 0;
}
void print2dArray(int arr[][COLS], int size) {
    // TODO(class): fill this in
}
