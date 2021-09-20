#include "./ArrayList.h"

ArrayList::ArrayList() {
    size = 0;
    data = new int[size];
}

ArrayList::~ArrayList() {
    std::cout << "destructor" << "\n";
    delete [] data;
}