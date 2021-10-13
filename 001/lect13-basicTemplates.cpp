// Copyright 2021 Casey A Cole
#include <iostream>
#include <string>

using std::string;

// int add(int, int);
// double add(double, double);
// double add(double, int);

// template <class T>  // <typename T>
// T add(T, T);

// HashMap<int,string> hm;
template <class T, class T2>
T add(T, T2);

// add(int, double)

template <>
char add(char, char);

int main(int argc, char** argv) {
    int a(10), b(9), int_sum;
    double c(5.5), d(6.0), double_sum;
    int_sum = add(a, a);
    std::cout << "The sum of a and b is : " << int_sum << std::endl;
    double_sum = add(c, d);
	std::cout << "The sum of c and d is : " << double_sum << std::endl;
	
    double_sum = add(c, a);
    std::cout << "The sum of a and c is : " << double_sum
			  << std::endl;
    return 0;
}
// int add(int a, int b) {
//     return a + b;
// }
// double add(double a, double b) {
//     return a+b;
// }
template <class T, class T2>
T add(T a, T2 b) {
	std::cout << "Template function\n";
    return a + b;
}



