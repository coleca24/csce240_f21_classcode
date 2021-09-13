// Copyright 2021 Casey Cole
#include <iostream>

using std::cout;

// printArray(ptr, size);
void printArray(const int*, int);

// Array = resizeArray(Array, 6);
int * resizeArray(int*, int);

int main(int argc, char **argv) {
    // Pointer review: Just a variable that holds a
    // memory location!
    // Some legal initializations of a pointer variable
    int x = 0;
    int *pt = &x;
    *pt = 10;
    cout << x << "\n";
    int arr[5];
    cout << arr << "\n";
    pt = arr;
    // pt = new int;
    // pt = new int[5];
    // Some illegal initializations
    // pt = new float;
    // pt = x;
    // The new and delete keyword
    pt = new int;
    delete pt;
    // new and delete with arrays
    pt = new int[5];
    delete [] pt;

    int **pt2;
    pt2 = new int*[5];
    for (int i = 0; i < 5; i++) {
        pt2[i] = new int[2];
    }
    // delete [][] int;
    for (int i = 0; i < 5; i++) {
        delete [] pt2[i];
    }
    delete [] pt2;

    // Pointers in functions?
    // As parameters
    int *ptr = new int[5];
    for (int i = 0; i < 5; i++) ptr[i] = 1;
    int size = 5;
    printArray(ptr, size);
    cout << "in main " << &ptr << "\n";
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << "\n";
    // Let's examine if we are doing call-by-ref or
    // call-by-value

    // As a return
    int * Array = new int[5];
    delete [] Array;
    Array = resizeArray(Array, 6);
    delete [] Array;

    // What should we do for memory clean up?

}
void printArray(const int* arr, int size) {
    // arr[0] = 10;
    // arr = new int[10];
    cout << "in func " << &arr << "\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int * resizeArray(int* arr, int size) {
    arr = new int[size];
    return arr;
}
