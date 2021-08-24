# Lecture 2 - C++ Basics
---
## Anatomy of a C++ Program
The most basic C++ program (Hello World!)
```
#include <iostream> 

int main(int argc, char **argv) {
    std::cout << "Hello World! << std::endl;
    return 0; 
}
```

Breaking it down line by line...

The following includes the header to the iostream library, namely, defines the standard input/output stream objects.
```
#include <iostream>
```
The following is the main function (the main driver of the software). Notice it returns 0 (we will talk more about other options later). 
```
int main(int argc, char **argv) {
    ...
    return 0
}
```
The following prints out Hello World! to the terminal (standard out). Notice the `std::`, this is specifying which namespace to look for the cout command. This `std::` is going to become quite tedious. However, it is better than the alternative (which you will see often in code) - adding a `using namespace std;` statement at the top of the file. This loads in the whole library. A lot of added overhead here. 
```
std::cout << "Hello World! << std::endl;
```

---

## I/0 (Standard in and out)
`std::cout` will print to standard out (the terminal)

`std::cin` will read in input from standard in (the terminal again)

`<<` stream insertion operator (put stuff into the stream to print out)

`>>` stream extraction operator (take stuff out of the stream and put it into your program)

Can be cascaded. For example, in the following code, if the numbers 4 and 5 are entered on the terminal by the user then the variable `a` will hold 4 and the variable `b` will hold 5.
```
int a(0), b(0); 
std::cin >> a >> b;
```
