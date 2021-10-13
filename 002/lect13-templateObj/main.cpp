// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.cpp"

using std::cout;

int main(int argc, char **argv) {
    ArrayList<int> intList(5, 1);
    ArrayList<double> doubleList(5, 2.5);

    cout << intList << "\n";
    cout << doubleList << "\n";

    return 0;
}