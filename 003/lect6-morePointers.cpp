// Copyright 2021 Casey Cole
#include <iostream>

using std::cout;

void printArray(const int *, int);
void resize(int *, int);
// newArry = append(oldArray, size, 10);
int * append(const int *, int, int);

int main(int argc, char **argv) {
    // // Pointer review: Just a variable
    // // that holds a memory location!
    // // Some legal initializations of a pointer variable
    // int x = 0;
    // // int *xp = &x;

    // // int arr[10];
    // // xp = arr;
    // // xp = new int;
    // // xp = new int[10];
    
    // // Some illegal initializations
    // // xp = x;
    // // xp = new float;

    // // The new and delete keyword
    // int *xp = new int;
    // *xp = 10;
    // delete xp;

    // // new and delete with arrays
    // xp = new int[5];
    // delete [] xp;
    // int **xp2;
    // xp2 = new int*[5];
    // for (int i = 0; i < 5; i++) {
    //     // if (i == 2) {
    //     //     xp2[i] = new int[3];
    //     // } else {
    //         xp2[i] = new int[2];
    //     // }
    // }
    // for (int i = 0; i < 5; i++) {
    //     delete [] xp2[i];
    // }
    // delete [] xp2;

    // // Pointers in functions?
    // // As parameters
    // int *ptr = new int[5];
    // // cout << sizeof(*ptr) << "\n";
    // for (int i = 0; i < 5; i++) ptr[i] = 1;
    // int size = 5;
    // printArray(ptr, size);
    // for (int i = 0; i < size; i++) {
    //     cout << ptr[i] << " ";
    // }
    // cout << "\n";
    // // Let's examine if we are doing call-by-ref
    // // or call-by-value
    // cout << "location of &ptr in main " << &ptr << "\n";
    // // resize(ptr, 6);
    // // for (int i = 0; i < 6; i++) {
    // //     cout << ptr[i] << " ";
    // // }
    // // cout << "\n";
    // // As a return
    // int * oldArray = new int[5];
    // // YOU DID NOT INITIALIZE -.-
    // int * newArry;
    // newArry = append(oldArray, size, 10);
    // printArray(newArry, 6);
    // delete [] oldArray;
    // delete [] newArry;

    int *temp = new int[2];
    // temp[2] = 10;
    delete [] temp;
    // What should we do for memory clean up?

}

void printArray(const int * ptr, int size) {
    // ptr[0] = 10;
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << "\n";
}
void resize(int * ptr, int new_size) {
    cout << "location of &ptr in resize " << &ptr << "\n";
    delete [] ptr;
    ptr = new int[new_size];
    for (int i = 0; i < new_size; i++) ptr[i] = 100;
}
int * append(const int * oArr, int size, int newVal) {
    int * nArr = new int[size+1];
    for (int i = 0; i < size; i++) {
        nArr[i] = oArr[i];
    }
    nArr[size] = newVal;
    return nArr;
}