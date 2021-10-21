// Copyright 2021 Casey A Cole
#include <iostream>
using std::cout;

int main(int argc, char **argv) {
    // Motivation
    // Print out the number of arguments (argc)
    cout << "argc: " << argc << "\n";
    // Usage statement
    if (argc != 4) {
        cout << "Usage: ./a.out <num1> <operation> <num2>\n";
        cout << "Operations: + - x /\n";
        exit(1);
    }
    // print out one of the arguments argv[0]...argv[n]

    // loop through all the arguments
    for (int i = 0; i < argc; i++) {
        cout << "i " << i << " argv " << argv[i] << "\n";
    }
    // Remember argv is a char array.
    // We need to convert it to an integer... (atoi)
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char op = argv[2][0];  // ['+', '\0']
    if (op == '+') {
        cout << (num1+num2) << "\n";
    } else if (op == '-') {
        cout << (num1-num2) << "\n";
    } else if (op == 'x') {
        cout << (num1*num2) << "\n";
    } else if (op == '/') {
        cout << (num1/num2) << "\n";
    }
    return 0;
}
