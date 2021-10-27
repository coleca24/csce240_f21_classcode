// Copyright 2021 Casey A Cole
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using std::cout;

bool mysortfunction(int i, int j) {
    return (i > j);
}

int main(int argc, char **argv) {
    // Initialization of vector<type>
    vector<int> vect{1, 2, 3, 4, 5};
    vector<int> vect1(vect.begin(), vect.end());

    for (auto current = vect.begin(); current != vect.end(); current++) {
        cout << *current << " ";
    }
    cout << "\n";

    for (auto i : vect1) {
        cout << i << " ";
    }
    cout << "\n";
    // How to insert data into vector (push_back and insert)
    vector<int>::iterator it;
    it = vect1.begin();
    it = vect1.insert(it , 200);
    for (auto i : vect1) {
        cout << i << " ";
    }
    cout << "\n";

    it = vect1.begin();
    it = vect1.insert(it +1, 200);
    for (auto i : vect1) {
        cout << i << " ";
    }
    cout << "\n";
    // How to remove data from vector (pop_back and erase)
    vect1.pop_back();
    for (auto i : vect1) {
        cout << i << " ";
    }
    cout << "\n";

    it = vect1.begin();
    vect1.erase(it);
    for (auto i : vect1) {
        cout << i << " ";
    }
    cout << "\n";
    // Lists
    // Initialization of list<type>
    list<int> list1{1, 2, 3, 4, 5};
    for (auto i : list1) {
        cout << i << " ";
    }
    cout << "\n";
    // How to insert data into list (push_back, push_front and insert)
    auto it2 = list1.begin();
    list1.insert(it2, 10);
    for (auto i : list1) {
        cout << i << " ";
    }
    cout << "\n";

    list1.push_back(100);
    for (auto i : list1) {
        cout << i << " ";
    }
    cout << "\n";

    list1.push_front(101);
    for (auto i : list1) {
        cout << i << " ";
    }
    cout << "\n";
    // How to remove data from list (pop_back, pop_front and erase)
    it2 = list1.begin();
    list1.erase(it2);
    for (auto i : list1) {
        cout << i << " ";
    }
    cout << "\n";

    list1.pop_back();
    for (auto i : list1) {
        cout << i << " ";
    }
    cout << "\n";

    list1.pop_front();
    for (auto i : list1) {
        cout << i << " ";
    }
    cout << "\n";
    // Question: why do you figure there is no push_front
    // or pop_front for vectors?

    // Algorithms: https://www.cplusplus.com/reference/algorithm/
    vector<int> unsorted{11, 2, 0, 4, 8};
    for (auto i : unsorted) {
        cout << i << " ";
    }
    cout << "\n";

    // Sort the whole list with default comparison '<'
    std::sort(unsorted.begin(), unsorted.end());
    for (auto i : unsorted) {
        cout << i << " ";
    }
    cout << "\n";
    // Sort the whole list with function for comparison
    std::sort(unsorted.begin(), unsorted.end(), mysortfunction);
    for (auto i : unsorted) {
        cout << i << " ";
    }
    cout << "\n";
    // What if I wanted to sort part of my array in one way and
    // one part in another way?

    // Special case of sort for lists...

    // And finally - some benchmarks to compare:
    // https://dzone.com/articles/c-benchmark-%E2%80%93-stdvector-vs
    return 0;
}
