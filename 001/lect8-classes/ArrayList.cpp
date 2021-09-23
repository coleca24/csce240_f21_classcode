#include "./ArrayList.h"

int ArrayList::numObjs = 0;
// typedef scout = std::cout;
ArrayList::ArrayList() : pi(3.14), e(2.7) {
    // pi = 3.14;
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

ArrayList::ArrayList(int size, int val) : pi(size), e(2.7) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = val;
    }
    numObjs++;
}

ArrayList::ArrayList(const ArrayList & copy) : pi(3.14), e(2.7) {
    setSize(copy.getSize());  // setSize(copy.size);  // size = copy.size;
    // data = copy.data;  // Shallow copy
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy.data[i];
        // copy[i];
    }
}

void ArrayList::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Invalid size\n";
        exit(0);
    }
}

int ArrayList::getSize() const {
    return size;
}

void ArrayList::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// [1, 2, 3] -> insert(1, 5) -> [1, 5, 2, 3]
void ArrayList::insert(int index, int value) {
    int *temp = data;
    data = new int[size+1];
    for (int i = 0; i < index; i++) {
        data[i] = temp[i];
    }
    data[index] = value;
    for (int i = index+1; i < this->getSize()+1; i++) {
        data[i] = temp[i-1];
    }
    delete [] temp;
    size++;
}

ArrayList::~ArrayList() {
    // std::cout << "destroy\n";
    delete [] data;
}