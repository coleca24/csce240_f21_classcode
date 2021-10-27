// Copyright 2021 Casey A Cole
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>

using std::vector;
using std::cout;

bool mysortfunction(int i, int j) {
    return (i>j);
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
    
    
    // How to remove data from vector (pop_back and insert)
    
    
    // Lists
    // Initialization of list<type>
    
    // How to insert data into list (push_back, push_front and insert)
    
    
    // How to remove data from list (pop_back, pop_front and insert)
    
    // Question: why do you figure there is no push_front or pop_front for vectors?
    
    // Algorithms: https://www.cplusplus.com/reference/algorithm/
    vector<int> unsorted{11, 2, 0, 4, 8};
    
    // Sort the whole list with default comparison '<'
    std::sort (myvector.begin(), myvector.end());
    
    // Sort the whole list with function for comparison
    std::sort (myvector.begin(), myvector.end(), mysortfunction);
    
    // What if I wanted to sort part of my array in one way and one part in another way?
    
    // Special case of sort for lists...
    
    
    // And finally - some benchmarks to compare:
    // https://dzone.com/articles/c-benchmark-%E2%80%93-stdvector-vs
    return 0;
}
