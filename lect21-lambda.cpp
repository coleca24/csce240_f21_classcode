// Copyright 2021 Casey A Cole
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::for_each;

// Structure of lambda
// [ capture clause ] (parameters) -> return-type
// {
//    definition of method
// }

void myfunction(int i) {
    cout << i << " ";
}

int main(int argc, char **argv) {
    // Solution to Exercise: Can you update this to return the 2 max values?
    vector<int> v{2, 4, 6, 10, 2, 57};
    // Printing
    for (int i : v) {
        cout << i << " ";
    }
    cout << "\n";

    // for_each in algorithm
    // https://www.cplusplus.com/reference/algorithm/for_each/
    // for_each(v.begin(), v.end(), myfunction);
    // cout << "\n";
    // Printing with Lambda
    // for_each(v.begin(), v.end(), [](int i) {
    //     std::cout << i << " ";
    //     // i = i+1;
    // });
    // cout << "\n";

    for (int i : v) {
        cout << i << " ";
    }
    cout << "\n";

    // Another application... How would you go about
    // finding the first element that is greater than a certain number?
    // auto p = find_if(v.begin(), v.end(), [](int i) {
    //     return i > 6;
    // });
    // cout << *p << "\n";
    return 0;
}

// Learn more: https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
// More examples:
