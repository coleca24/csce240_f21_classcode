// Copyright 2021 Casey A Cole
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
// #include <ranges>

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
    // i = i+1;
}

int main(int argc, char **argv) {
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

    // for (int i : v) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // Printing with Lambda
    // for_each(v.begin(), v.end(), [](int & i) {
    //     // std::cout << i << " ";
    //     i = i+1;
    // });
    // cout << "\n";

    // for (int i : v) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // Another application... How would you go about
    // finding the first element that is greater than a certain number?
    // vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i) {
    //     return i > 6 && i != 7;
    //     // Add more logic?
    // });
    // cout << *p << "\n";

    // int count = count_if(v.begin(), v.end(), [](int i) {
    //     return i > 6 && i != 7;
    //     // Add more logic?
    // });
    // cout << count << "\n";

    // int value = 6;
    // auto myFunction = [=] {
    //     // value = value*2;
    //     return value*2;
    // };
    // cout << myFunction() << "\n";
    // cout << value << "\n";

    // auto const ints = {0,1,2,3,4,5};
    // auto even = [](int i) { return 0 == i % 2; };
    // auto square = [](int i) { return i * i; };
 
    // // // "pipe" syntax of composing the views:
    // for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
    //     std::cout << i << ' ';
    // }
 
    // std::cout << '\n';
 
    // // a traditional "functional" composing syntax:
    // for (int i : std::views::transform(std::views::filter(ints, even), square)) {
    //     std::cout << i << ' ';
    // }
    return 0;
}

// Learn more: https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
// More examples: https://en.cppreference.com/w/cpp/ranges
