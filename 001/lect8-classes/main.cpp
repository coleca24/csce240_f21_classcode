// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.h"

int main(int argc, char **argv) {
    ArrayList a;
    ArrayList b(5);
    b.print();
    // ArrayList c = 'c';
    ArrayList c(5, 1);
    c.print();
    std::cout << ArrayList::numObjs << "\n";

    return 0;
}
