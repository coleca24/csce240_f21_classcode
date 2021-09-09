# Lecture 5 - Some Misc. Topics and Intro to Pointers
## Miscellaneous Topics
The following are some micellaneous topics that will be helpful in your Project 1. 
### More on `stringstream`
You can turn a string into a stream using a stringstream. The benefit of this is that you can then use that stringstream as the first argument in the `getline()` function so that you can loop though the values just like you would a file stream (see lecture 4 and file I/O). 

The following code will turn a string into a stream called `ss`. 
```
#include <sstream>
string line = "10 20 30"; 
std::stringstream ss(line); 
```

Then to parse out the individual values you can repeatedly call the `getline()` function that takes in a stream, string and delimiter. Example:
```
#include <sstream>
string line = "10 20 30"; 
string token = ""; 
std::stringstream ss(line);
while (getline(ss, token, ' ') {
   cout << token << "\n"; 
}

// Output: 
// 10
// 20
// 30
```
The way that this `getline(ss, token, ' ')` will work is that it will read the stringstream `ss` (that has "10 20 30" in it) until the first instance of the delimiter (which is the third argument - a space ' '). This will be stored in the `token` string. As the while loop iterates, the value of `token` will be continually updated with each new value that it finds between the ' ' characters in the string. 

### Generating Random Numbers and Chars
We can generate a random number by using the `rand()` and `srand()` functions. 

The following will generate a number between 0 and 9. 
```
int randNum = rand() % 10;
```

However, the issue with this is that the same random numbers will be generated over and over. That is because the seed (https://en.wikipedia.org/wiki/Random_seed) is always set to 1. We will want to change that to get truly random numbers each time. A good way to ensure that you are always getting a fresh set of random numbers is to set the seed to a relative time using the `time()` function (https://www.cplusplus.com/reference/ctime/time/). In this case, the value returned generally represents the number of seconds since 00:00 hours, Jan 1, 1970 UTC (i.e., the current unix timestamp). The seed is set as follows:
```
srand(time(NULL)); 
```

Now how do we change that to a char? 

Remember that a `char` in C++ has an ASCII decimal value: 
![image](https://user-images.githubusercontent.com/3376451/132389795-4d12e60e-e646-413d-a7a3-53cd6f554639.png)

So, for example the character '0' has the decimal equivalent of 48 and '9' has the decimal equivalent of 57. Therefore, if we wanted to generate a character from '0' to '9' then we just need to generate a number between 48 and 57:
```
int num = rand() % 10 + 48; // will generate a number between 48 and 57
char c = num; // c will now be a character between '0' and '9' 
```

## Introduction to Pointers
Yay! Dynamic memory! To fully appreciate pointers and what they afford you, you need to first take a look at the basic layout of a C++ program, especially the difference between the heap and the stack. These are two different places where memory is allocated for variables in your programs. 

Memory layout of a C++ program: 
![image](https://user-images.githubusercontent.com/3376451/132609533-1ec39af4-2fd0-4584-b320-08d33e0d3f73.jpeg)

The **stack** is where the memory for traditional variables (int, int[], double, float, string etc.) is allocated. After your program is finished or that variable goes out of scope, it is automatically deallocated (marked as free) by your system. Note that you do not have any freedom to deallocate variables in the stack yourself. 

The **heap** is where dynamic memory is created. The heap is not maintained by your system, instead you are in charge of allocating and deallocating the variables' memory space. Yes, this is one more thing to worry about, however, there are some really cool benefits! Because you are able to deallocate the space here, that means that you can do things like resizing arrays and return arrays from functions (kinda). 

Up to this point, we have been working exlcusively in the stack, but pointers will be what lets us dip into the heap. 

But first! What is a pointer? A pointer is a variable that holds a memory location. We call it a pointer because since it is holding the memory location of another variable, it is "pointing" to that variable and has direct access to its value. 

For example, in the following code, I define `x` and `xPtr`. `xPtr` is a pointer and you can tell this by the definition in which a `*` is included. I point `xPtr` to `x` by setting it equal to the memory location of `x` (`&x`). Now, I can change the value of `x` by just interacting with `xPtr`. At the end of this code, `x` is equal to 1000, not 100. 
```
int x = 100; 
int *xPtr = &x; 
*xPtr = 1000; 
```
The `*xPtr = 1000` is an example of dereferencing a pointer. All this means is that we go to the pointer's value (in this case the memory location of `x`) and go to that address (so now we are at `x`) and set the value to 1000 (now `x` = 1000). 

A Use Case - Resizing an array - **TODO**

At this point, it may seem trival, but that is just the basics. We will soon get into use cases in which it will make sense as to why this is useful. 
