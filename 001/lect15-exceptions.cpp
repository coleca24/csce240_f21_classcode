// Copyright 2021 Casey A Cole
#include <iostream>
#include <exception>

bool validateNum(int);

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cout << "Usage: ./a.out <number 1> <operation> <number 2>" << "\n";
        exit(1);
    }
    int num1 = atoi(argv[1]);
    bool valid = validateNum(num1);
    int num2 = atoi(argv[3]);
    char op = argv[2][0];
    try {
        if (op == '+') {
            std::cout << num1 + num2 << "\n";
        } else if (op == '-') {
            std::cout << num1 - num2 << "\n";
        } else if (op == 'x') {
            std::cout << num1 * num2 << "\n";
        } else if (op == '/') {
            if (num2 == 0) throw std::exception();
            std::cout << num1 / num2 << "\n";
        }
    } catch(std::exception e) {
        std::cout << "NaN\n";
        std::cout << e.what() << "\n";
    }

    // What about validating something more specific, like if the numbers are 
    // above a certain value

    return 0;
}

bool validateNum(int num) {
    try {
        if (num > 10) {
            throw num;
        }
        return true;
    } catch (int e) {
        std::cout << e << " was greater than 10\n";
        return false;
    } catch(...) {

    }
}