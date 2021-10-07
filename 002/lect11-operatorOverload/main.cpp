// Copyright 2021 Casey A Cole
#include <iostream>
#include "./ArrayList.h"

int main(int argc, char **argv) {
    ArrayList a(5, 1);
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

    ArrayList b(2, 1), c(10, 1);

    // a = b = c;
    // a = b.operator=(c);
    // a.operator=(b.operator=(c));
    // b.print();
    // a = b++;
    c = a = b;  // a.operator=(b)
    std::cout << a << b;
    // std::cin >> a >> b;
    c = a + 1;  // a.operator+(1)
    std::cout << a;
    std::cout << c;
    // a << std::cout;
    // a.print();
    // b.print();
    // a = ++b;
    // string s;
    // std::cout << s;
    // System.out.println(a);
    // for (int i = 0; i < 10; i++) {}
    // int i1(0), i2(1);
    // i1 = i2++;
    // a.print();

    // std::cout << h << "\n";
    // a = b;  // a.operator=(b)

    // std::cout << a;

    // operator<<(ArrayList) {

    // }

    // ArrayList<float> a; 
    return 0;
}
