// Copyright 2021 Casey Cole
#include <iostream>
#include <sstream>

using std::string;
using std::cout;

int main(int argc, char **argv) {
    // Who completed the challenge?
    // Reading in a csv file into a 2d array?
    // Hint:
    string line = "10,11", token = "";
    std::stringstream s_line(line);
    getline(s_line, token, ',');
    // cout << token << "\n";
    // getline()!

    // genPassword() in P1... how to generate random
    // chars? Ideas?
    // <random>
    srand(time(NULL));
    cout << "time: " << time(NULL) << "\n";
    int randNum = 0;
    cout << rand() % 10 + 48<< "\n";
    char num = rand() % 10 + 48;
    cout << num << "\n";
    return 0;
}
