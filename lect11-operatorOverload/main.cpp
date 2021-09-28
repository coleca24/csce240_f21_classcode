// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.h"

int main(int argc, char **argv) {
    ArrayList a(5, 1);
    std::cout << "a at index 0 is " << a.getData(0) << "\n";
    
    // std::cout << "a at index 0 is " << a[0] << "\n";
    return 0;
}
