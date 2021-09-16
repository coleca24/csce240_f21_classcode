#include "./ArrayList.h"

ArrayList::ArrayList(int size) {
    this->size = size;
    arr = new int[size];
}

ArrayList::~ArrayList() {
    delete [] arr;
}