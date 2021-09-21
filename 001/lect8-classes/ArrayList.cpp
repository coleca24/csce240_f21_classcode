#include "./ArrayList.h"

int ArrayList::numObjs = 0;
// typedef scout = std::cout;
ArrayList::ArrayList() {
    size = 0;
    data = new int[size];
    numObjs++;
}

// ArrayList::ArrayList(int size) {
//     this->size = size;
//     std::cout << "Local size " << size << "\n";
//     std::cout << "This size " << this->size << "\n";
//     data = new int[size];
// }

ArrayList::ArrayList(int size, int val) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = val;
    }
    numObjs++;
}

void ArrayList::print() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

ArrayList::~ArrayList() {
    std::cout << "destroy\n";
    delete [] data;
}