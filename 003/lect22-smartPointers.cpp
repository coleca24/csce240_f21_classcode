// Copyright 2021 Casey A Cole
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
// #include <ranges>
#include <memory>

using std::vector;
using std::cout;
using std::cin;
using std::for_each;

void fun() {
    int *pt = new int;
}

int main(int argc, char **argv) {
    // Recall pointers -
    // Points to a new int that is stored in
    // the heap (dynamically allocated)
    int *pt = new int;
    // At this point, we have a memory
    // leak because we have not deallocated
    // the space that we allocated.
    // This gets even more pronouced when
    // we use pointers in functions.
    // while (true) {
    //     fun();
    // }
    // And where would we deallocate this?
    // Assuming that we need the int that pt is
    // pointing to... we can't do it in the function...
    // Enter smart pointers (#include <memory>)
    // Two main types:
    // 1 - unique pointer
    // int *temp = data;
    // int * pt2 = new int;
    // *pt2 = 20;
    std::unique_ptr<int> pt2 = std::make_unique<int>(20);
    cout << *pt2 << "\n";
    std::unique_ptr<int> p5;
    // p5 = pt2;

    // 2 - shared pointer - two pointers can
    // point to the same spot, and there is a reference counter
    std::shared_ptr<int> pt3 = std::make_shared<int>(100);
    cout << *pt3 << "\n";
    std::shared_ptr<int> pt4;
    pt4 = pt3;
    cout << *pt4;

    // 3 - weak pointer
    return 0;
}
