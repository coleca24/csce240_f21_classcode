// Copyright 2021 Casey Cole
#include <iostream>
#include <sstream>

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

    // Where is this useful?
    // Use case: resizing arrays
    int arr[5] = {1,1,1,1,1};
    // We now want: {1,1,1,1,1,10}
    // Let's attempt with primative arrays
    int arr2[6];
    // So what's the big problem? It works



    // 1) Consistant naming
    // 2) Space
    // More reading: https://www.geeksforgeeks.org/memory-layout-of-c-program/

    // How to do it with pointers?
    int *pt_arr;
    pt_arr = new int[5];
    for (int i = 0; i < 5; i++) {
        pt_arr[i] = 1; 
    }
    int *temp;
    temp = pt_arr; 
    pt_arr = new int[6];
    delete [] temp;
    delete [] pt_arr;
}
