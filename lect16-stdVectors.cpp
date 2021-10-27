// Copyright 2021 Casey A Cole
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;

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
    // And finally - some benchmarks to compare:
    // https://dzone.com/articles/c-benchmark-%E2%80%93-stdvector-vs
    return 0;
}
