// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.h"

int main(int argc, char **argv) {
    // ArrayList a(5, 1);
    // std::cout << "a at index 0 is " << a.getData(0) << "\n";
    // std::string h = "hello";
    // std::cout << h[0] << "\n";
    // std::cout << h.operator[](0);
    // if (h == h) {  // h.operator==(h)
    //     std::cout << "same\n";
    // }
    
    // std::cout << "a at index 0 is " << a[0] << "\n";
    // if (a == a) {  // a.operator==(a)
    //     std::cout << "same obj\n";
    // }
    
    // a.print();
    // a[0] = 10;
    // // a(0, 10);  // a.operator()(int,int)
    // a.print();

    // std::string s1, s2, s3;

    // // s1 = s2 = s3 = "";
    // s1 = s2.operator=(s3.operator=(""));

    // ArrayList b(2, 1), c(10, 1);

    // a = b = c;

    // a.print();

    // std::cout << h << "\n";
    // // c = a = b;
    // // c = (a = b)(0, 1);  // a.operator=(b)
    // // c.operator=(a.operator=(b).operator()(0,1));
    // a++;
    // ++a;

    // int i = 0, j = 0;
    // j = i++;

    // std::cout << a;

    // operator<<(ArrayList) {

    // }

    ArrayList a(2, 1), b;
    a.print();
    std::cout << a << " " << a;
    // a << std::cout;
    // a = b; // a.operator=(b)
    // b = ++a;
    // b = a++;
    // a.print();
    // b.print();
    return 0;
}


// 1) string ret = ""
// 2) add the right stuff to ret
// 3) SuperString s(ret)
// 4) return s