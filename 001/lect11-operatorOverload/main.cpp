// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.h"

int main(int argc, char **argv) {
    ArrayList a(5, 1);
    std::cout << "a at index 0 is " << a.getData(0) << "\n";

    std::string h = "hello";
    std::cout << h[0] << "\n";
    std::cout << h.operator[](0) << "\n";
    h[0] = 't';
    std::cout << "a at index 0 is " << a[0] << "\n";
    a.print();
    a[0] = 10;
    a.print();
    // a++;
    // ++a;
    if (h == h) { // h.operator==(h)
        std::cout << "string equal\n";
    }

    if (a == a) {  // a.operator==(a)
        std::cout << "obj equal\n";
    }
    std::string s1, s2, s3; 
    s1 = s2 = s3 = "hello";
    s1 = s2.operator=(s3.operator=("hello"));

    // a(0, 10, true);
    const ArrayList e;
    // e == e;
    ArrayList b(2, 1), c(10, 2), d(3, 3);
    b = c = d;  // b.operator=(c)
    // b.operator=(void);
    b.print();
    c.print();

    // std::cout << a;
    return 0;
}
