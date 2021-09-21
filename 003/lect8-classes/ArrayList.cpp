#include "./ArrayList.h"

int ArrayList::numObj = 0;

void ArrayList::printNumObjects() {
    std::cout << "Num Objects: " << numObj << "\n";
}

ArrayList::ArrayList() : num(0) {
    // num = 0;
    size = 0;
    arr = new int[size];
    numObj++;
}

ArrayList::ArrayList(int size) : num(0) {
    std::cout << "int one\n" << size;
    this->size = size;
    arr = new int[size];
}

// ArrayList::ArrayList(char c) : num(0) {
//     std::cout << "char one\n";
//     this->size = 5;
//     arr = new int[size];
// }

ArrayList::ArrayList(int data[], int size) : num(0){
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = data[i];
    }
    numObj++;
}

// ArrayList::ArrayList(int size, int val) : num(val) {
//     this->size = size;
//     arr = new int[size];
//     for (int i = 0; i < size; i++) {
//         arr[i] = val;
//     }
//     numObj++;
// }

void ArrayList::print() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

ArrayList::~ArrayList() {
    delete [] arr;
    numObj--;
    std::cout << "Destroy ";
    std::cout << "Num Objects: " << numObj << "\n";
}