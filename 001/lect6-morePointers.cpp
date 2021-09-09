// Copyright 2021 Casey Cole
#include <iostream>

using std::cout;

// printArray(pt, size);
void printArray(int*&, int);
// pt = append(pt, size, 10);
int * append(const int *, int &, int);

int main(int argc, char **argv) {
    // Pointer review: Just a variable that
    // holds a memory location!
    // Some legal initializations of a pointer variable
    int x = 100;
    int *pt = &x;
    // pt = new int[5];
    // pt = new int;
    int arr[5];
    pt = arr;
    pt = &arr[1];
    // Some illegal initializations
    float f = 1.0;
    // pt = &f;
    // The new and delete keyword
    pt = new int[3];
    delete [] pt;
    // new and delete with arrays
    int **arr2d; 
    arr2d = new int*[5];
    for (int i = 0; i < 5; i++) {
        arr2d[i] = new int[2];
    }
    arr2d[0][0] =10;
    // delete [][] arr2d;
    for (int i = 0; i < 5; i++) {
        delete [] arr2d[i];
    }
    delete [] arr2d;
    // Pointers in functions?
    // As parameters
    pt = new int[5];
    int size = 5;
    for (int i = 0; i < size; i++)
        pt[i] = 1;
    // sizeof(*pt)
    // printArray(pt, size);
    // for (int i = 0; i < size; i++)
    //     cout << pt[i] << " ";
    // cout << "\n";
    cout << "value of pt in main: " << pt << "\n";




    // Let's examine if we are doing call-by-ref or call-by-value

    // As a return
    // int * oldArray = new int[5];
    // int * newArry;
    // newArray = resizeArray(oldArray, size);
    // pt =  1,1,1,1,1
    // want pt = 1,1,1,1,1,10
    for (int i = 0; i < size; i++)
        cout << pt[i] << " ";
    cout << "\n";
    pt = append(pt, size, 10);
    for (int i = 0; i < size; i++)
        cout << pt[i] << " ";
    cout << "\n";
    // What should we do for memory clean up?

}

void printArray(int*& pt, int size) {
    // pt[0] = 10;
    pt = new int;
    cout << "value of pt in func: " << pt << "\n";
    // for (int i = 0; i < size; i++)
    //     cout << pt[i] << " ";
    // cout << "\n";
}
int * append(const int * pt, int & size, int newVal) {
    int * newPt = new int[size+1];
    size++;
    for (int i = 0; i < size-1; i++) {
        newPt[i] = pt[i];
    }
    delete [] pt;
    newPt[size-1] = newVal;
    return newPt;
}
