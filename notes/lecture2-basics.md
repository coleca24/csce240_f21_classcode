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
