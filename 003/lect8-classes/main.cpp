// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.h"

int main(int argc, char **argv) {
    ArrayList a(1);
    ArrayList a2('c');
    char c = 'b';
    ArrayList b(c);
    int arr[5] = {1,1,1,1,1};
    // ArrayList a2(arr, 5);
    // a2.print();
    // // ArrayList a3(5, 2);
    // a3.print();
    ArrayList::printNumObjects();
    // ArrayList a3 = {arr, 5};
    // std::cout << a.size;
    return 0;
}
