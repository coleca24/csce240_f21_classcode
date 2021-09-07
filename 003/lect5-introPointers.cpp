// Copyright 2021 Casey Cole
#include <iostream>

using std::string;
using std::cout;

int main(int argc, char **argv) {
    // Introduction to pointers:
    int x(0);
    x = 100;
    // cout << x << "\n";

    int *xPtr;
    xPtr = &x;

    // cout << "Value of x: " << x << "\n";
    // cout << "Location of x (&x): " << &x << "\n";
    // cout << "Value of xPtr: " << xPtr << "\n";
    // cout << "Location of xPtr (&xPtr): " << &xPtr << "\n";
    // cout << "Value of x again (*xPtr): " << *xPtr << "\n";
    // cout << "A fun one (&(*xPtr)): " << &(*xPtr) << "\n";
    // *xPtr = 1000;
    // cout << "Value of x: " << x << "\n";
    // *(*xPtr)

    // Where is this useful?
    // Use case: resizing arrays
    int arr[5] = {1,1,1,1,1};
    // We now want: {1,1,1,1,1,10}
    // Let's attempt with primative arrays
    int arr1[6]; 
    for (int i = 0; i < 5; i++) {
        arr1[i] = arr[i];
    }
    arr1[5] = 10; 
    for (int i = 0; i < 6; i++) {
        cout << arr1[i] << " ";
    }
    // So what's the big problem? It works
    // 1) Consistant naming
    // 2) Space 
    // More reading: https://www.geeksforgeeks.org/memory-layout-of-c-program/

    // How to do it with pointers?
    int *arr2;
    arr2 = new int[5];
    for (int i = 0; i < 5; i++) {
        arr2[i] = 1;
    }
    int *temp;
    temp = arr2;
    arr2 = new int[6];
    for (int i = 0; i < 5; i++) {
        arr2[i] = temp[i];
    }
    arr2[5] = 10;
    delete [] temp;
}
