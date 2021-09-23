#include "./ArrayList.h"

int ArrayList::numObj = 0;

void ArrayList::printNumObjects() {
    std::cout << "Num Objects: " << numObj << "\n";
}

ArrayList::ArrayList() : num(0), pi(3.14) {
    // num = 0;
    size = 0;
    arr = new int[size];
    numObj++;
}

ArrayList::ArrayList(int size) : num(0), pi(3.14) {
    // std::cout << "int one\n" << size;
    this->size = size;
    arr = new int[size];
}

ArrayList::ArrayList(const ArrayList & copy) : num(0), pi(3.14) {
    // size = copy.getSize();
    setSize(copy.getSize());
    // arr = copy.arr;  // shallow copy
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        // arr[i] = copy.arr[i];
        // arr[i] = copy.getData(i);
        setData(i, copy.getData(i));
    }
}

// ArrayList::ArrayList(char c) : num(0) {
//     std::cout << "char one\n";
//     this->size = 5;
//     arr = new int[size];
// }

ArrayList::ArrayList(int data[], int size) : num(0), pi(3.14) {
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

void ArrayList::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int ArrayList::getSize() const {
    return size;
}

int ArrayList::getData(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}
void ArrayList::setData(int index, int value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

void ArrayList::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    }
}

void ArrayList::insert(int index, int value) {
    int *temp = arr;
    arr = new int[size+1];
    for (int i = 0; i < index; i++) {
        arr[i] = temp[i];
    }
    arr[index] = value;
    for (int i = index +1; i <size + 1; i++) {
        arr[i] = temp[i-1];
    }
    size++;
    delete [] temp;
}

ArrayList::~ArrayList() {
    delete [] arr;
    numObj--;
    // std::cout << "Destroy ";
    // std::cout << "Num Objects: " << numObj << "\n";
}