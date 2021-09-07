// Copyright 2021 Casey Cole
#include <iostream>
#include <sstream>

using std::string;
using std::cout;

int main(int argc, char **argv) {
    // Who completed the challenge?
    // Reading in a csv file into a 2d array?
    // Hint:
    string line = "10,11";
    string token = "";
    std::stringstream s_line(line);
    // getline()!

    // while (getline(s_line, token, ',') )
    // cout << token << "\n";

    // genPassword() in P1... how to generate random
    // chars? Ideas?
    srand(time(NULL));
    cout << time(NULL) << "\n";
    int randNum = 0;
    for (int i =0; i <5; i++) {
        randNum = rand() % 10 + 48;
        char c = randNum;
        cout << randNum << "\n";
        cout << c << "\n";
    }
    
    return 0;
}
