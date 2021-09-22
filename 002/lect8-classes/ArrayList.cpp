#include "./ArrayList.h"

int ArrayList::numAL = 0;
int ArrayList::getNumAL() {
    return numAL;
}
ArrayList::ArrayList() : pi(3.14), e(2.7) {
    size = 0;
    data = new int[size];
    numAL++;
}

// ArrayList::ArrayList(int size) {
//     this->size = size;
//     data = new int[size];
//     for (int i = 0; i < size; i++) {
//         data[i] = 0;
//     }
// }
ArrayList::ArrayList(int size, int val) : pi(3.14), e(2.7) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
    numAL++;
}

ArrayList::ArrayList(const ArrayList & copy) : pi(3.14), e(2.7) {
    size = copy.size;
    // data = copy.data;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy.data[i];
    }
}

void ArrayList::print() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

ArrayList::~ArrayList() {
    numAL--;
    std::cout << "destructor " << numAL << "\n";
    delete [] data;
}