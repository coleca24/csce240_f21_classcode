// Copyright 2021 Casey A Cole
#include <iostream>
#include <string>

// A small comment
/*
* A large comment block
*
*/

// using namespace std; //This is no good
// typedef std::cout cout_std;

int main(int argc, char **argv) {
    // I/O input and output to standard in/out (terminal)
    int num = 0, num2 = 0;
    // std::cout << "Enter a number: " << " \n";
    // std::cin >> num >> num2;
    // std::cout << num << std::endl;

    ///////////////////////////////////////////////////////////////////////
    // Basic data types
    // int (4 bytes), float (4 bytes),
    // char (1 byte), bool (1 byte), double (8 bytes)
    // Different ways to initialize:
    int a(0), b(0);
    int c = 0;
    int d(0), e = 0;

    bool flag = true;

    char p('p');
    // std::cout << "Value of p is " << p << std::endl;
    // What do you think this will be?
    // std::cout << p + 1 << std::endl;
    int n; 
    n = 'p';
    char q(' ');
    q = p+1;
    // std::cout << q << std::endl;
    // std::cout << n << std::endl;

    // auto keyword for type inference
    auto i = 0;
    // std::cout << sizeof(i) << std::endl;
    // cannot change types after that!
    i = 1.2;
    // std::cout << i << std::endl;
    ///////////////////////////////////////////////////////////////////////
    // Arrays
    // type name[] = {init values};
    // type name[size] = {init value};
    // type name[size1][size2];
    int array[] = {1, 2, 3};
    int array2[100] = {0};
    int array3[10][3];
    ///////////////////////////////////////////////////////////////////////
    // if/else statements
    // Ctrl / to toggle comments
    // if() {
    // }
    // else if(){

    // }
    // else{
    // }

    ///////////////////////////////////////////////////////////////////////
    // switch statements
    // char t = 'T';
    // switch(t) {
    //     case 'T':
    //         //do something
    //         break;
    //     case something_else:
    //         break;
    //     default:
    // }
    ///////////////////////////////////////////////////////////////////////
    // while loops
    // init step;
    // while(condition){
    //     update step;
    // }

    // Post vs. Pre?
    int i = 0; 
    std::cout << ++i;
    std::cout << i; 

    // do-while loops
    // init step;
    // do{
    //    //do something
    //     increment step;
    // }while(condition);

    ///////////////////////////////////////////////////////////////////////
    // for loops
    // for(init step; condition; increment){
    //     do something
    // }

    for(int i = 0; i < 10; i++){
        
    }

    return 0;
}
