// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.h"

// void resize(ArrayList list);
int main(int argc, char **argv) {
    ArrayList a(1);
    // ArrayList a2('c');
    // ArrayList a3(a);
    // a2 = a3;
    char c = 'b';
    ArrayList b(c);
    int arr[5] = {1,2,3,4,5};
    ArrayList a2(arr, 5);
    std::cout << a2.getData(0) << "\n";
    ArrayList a3(a2);
    a3.print();
    a3.insert(1, 5);  // [1, 5, 2, 3, 4, 5]
    a3.print();
    a3.insert(0, 5);  // [5, 1, 5, 2, 3, 4, 5]
    a3.print();
    a3.insert(7, 5);  // [5, 1, 5, 2, 3, 4, 5, 5]
    a3.print();
    // a2.print();
    // // ArrayList a3(5, 2);
    // a3.print();
    ArrayList::printNumObjects();
    // ArrayList a3 = {arr, 5};
    // std::cout << a.size;
    return 0;
}
