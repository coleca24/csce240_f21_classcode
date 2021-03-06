#include "./ArrayList.h"

ArrayList::ArrayList() {
    size = 0;
    data = new int[size];
}

ArrayList::ArrayList(int size, int val){
    this->size = size;
    data = new int[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
}

ArrayList::ArrayList(const ArrayList & copy){
    // size = copy.size;
    setSize(copy.getSize());
    // data = copy.data;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy.data[i];
    }
}

void ArrayList::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Incorrect size\n";
        exit(1);
    }
}

int ArrayList::getSize() const {
    return size;
}

int ArrayList::getData(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

void ArrayList::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}
// [1,2,3,4,5] -> insert(1,5) -> [1,5,2,3,4,5]
bool ArrayList::insert(int index, int newVal) {
    if (index >= 0 && index <= size) {
        int *temp = data;
        data = new int[size+1];
        for (int i = 0; i < index; i++) {
            data[i] = temp[i];
        }
        data[index] = newVal;
        for (int i = index+1; i < size+1; i++) {
            data[i] = temp[i-1];
        }
        delete [] temp;
        size++;
        return true;
    }
    return false;
}

// [1,2,3,4,5] -> remove(1) -> [1,3,4,5]
bool ArrayList::remove(int index) {
    if (index >= 0 && index < size) {
        int *temp = data;
        data = new int[size-1];
        for (int i = 0; i < index; i++) {
            data[i] = temp[i];
        }
        for (int i = index; i < size-1; i++) {
            data[i] = temp[i+1];
        }
        size--;
        delete [] temp;
        return true;
    } 
    return false;
}

ArrayList::~ArrayList() {
    // std::cout << "destructor " << numAL << "\n";
    delete [] data;
}