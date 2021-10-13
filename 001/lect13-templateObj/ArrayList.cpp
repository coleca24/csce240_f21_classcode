#include "./ArrayList.h"

template <class T>
ArrayList<T>::ArrayList() {
    size = 0;
    data = new T[size];
}
template <class T>
ArrayList<T>::ArrayList(int size, T val) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
}
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & copy) {
    // size = copy.size;
    setSize(copy.getSize());
    // data = copy.data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy.data[i];
    }
}

template <class T>
void ArrayList<T>::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Incorrect size\n";
        exit(1);
    }
}

template <class T>
int ArrayList<T>::getSize() const {
    return size;
}

template <class T>
T ArrayList<T>::getData(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
void ArrayList<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

template <class T>
T ArrayList<T>::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}
template <class T>
T& ArrayList<T>::operator[](int index) {
    return data[index];
}

template <class T>
bool ArrayList<T>::operator==(const ArrayList<T> & rhs) const {
    bool ret = true;
    if (size != rhs.size) {
        ret = false;
    } else {
        for (int i = 0; i < size; i++) {
            if (data[i] != rhs[i]) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

template <class T>
const ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> & rhs) {
    size = rhs.getSize();
    delete [] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = rhs[i];
    }
    return *this;
}

template <class T>
void ArrayList<T>::operator()(int index, T val) {
    // ADD error checking on index
    data[index] = val;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(T newVal) const {
    ArrayList<T> temp(size+1);
    for (int i = 0; i < size; i ++) {
        temp.data[i] = data[i];
    }
    temp.data[size] = newVal;
    return temp;
}
template <class U>
ostream& operator<<(ostream & os, ArrayList<U> a) {
    for (int i = 0; i < a.getSize(); i++) {
        os << a.getData(i) << " ";
    }
    os << "\n";
    return os;
}
template <class T>
ArrayList<T>::~ArrayList() {
    // std::cout << "destructor " << numAL << "\n";
    delete [] data;
}