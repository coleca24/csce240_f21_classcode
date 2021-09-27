# Lecture 9 - Intro to Classes and Objects

## C++ Class Definitions
To define an object in C++ you will need two files: a header (or .h file) and an implementation file (.cpp). 

### The Header (.h)
In the header file (.h) you should have the class definition. This is just a collection of prototypes for member functions as well as declarations of member variables. The syntax for this is the following: 
```
class ArrayList {
  //Add member variables and functions here! 
};
```

In C++ there are several modifiers that define the level of access of member variables and functions. Two that you should have some familarity with is `public` and `private`. `public` member variables and functions are able to be directly accessed in the main(), whereas, there is no direct access to private functions and variables anywhere other than inside the class definition itself. Each member function and variable should have one of these modifiers. In C++ these modifiers are defined like this: 
```
class ArrayList {
  public: 
    // Everything here will be public
  private:
    // Everything here will be private
};
```

By default if no modifer is given then everything defined in the class will be `private`.

### The Implementation file (.cpp)
This is the file that you will write all of your actual C++ code in. It should be called the same as your header (.h) file. For example, if you were to have make an ArrayList object, then you would have an ArrayList.h and an ArrayList.cpp. The .cpp would use the `#include` keyword at the top to make the connection to the header file (see below): 
```
// Content of ArrayList.cpp 
#include "./ArrayList.h"  // Assuming that ArrayList.h is in the same folder as the ArrayList.cpp file. 
```
After the connection is made then you can start writing functions. Below is an example of a simple function that will print "Hello World". Note all of the connections and syntax. 

ArrayList.h
```
#include <iostream> 

class ArrayList {
  public: 
    void printHelloWorld();
  private: 
     
};
```

ArrayList.cpp
```
#include "./ArrayList.h"

void ArrayList::printHelloWorld() {
  std::cout << "Hello World\n";
}

```

And now the main() function. I usually put mine in a file named main.cpp. 
```
#include "./ArrayList.h"  // need to include the header here too. 

int main() {
  ArrayList a; // Create the object
  a.printHelloWorld(); // Call the member function
  return 0; 
}
```

## Using a `static` Variable or Function
`static` variables and functions are those that do not belong to a certain instance of an object, but instead, belong to the all instances of the class (or the class itself). One example of when you might want to use a `static` variable is when you want to keep track of how many times a function is called (we will use that `printHelloWorld()` function as an example!)

### Defining a `static` variable and function
Let's first define the `static` variable and function. We will make the variable `private` and make a `public` function to return it. 

ArrayList.h
```
#include <iostream> 

class ArrayList {
  public: 
    void printHelloWorld();
    static void getNum();
  private: 
    static int num;
};
```

### Initializing the variable
You will want to initialize this just once when the class is first defined. We will do this at the top of the .cpp implementation file.

ArrayList.cpp
```
int ArrayList::num = 0;  // Make sure that you do not miss the ArrayList::
```

### Changing the variable
In this particular use case, we will want the variable `num` to increase everytime the `printHelloWorld()` function is called. 

ArrayList.cpp
```
int ArrayList::num = 0;  

void ArrayList::printHelloWorld() {
  std::cout << "Hello World\n";
  num++; // increase the static num value here.
}

```

We also want to create the `static getNum()` function as well. This will just print the static variable's value.  

ArrayList.cpp
```
int ArrayList::num = 0;  

void ArrayList::printHelloWorld() {
  std::cout << "Hello World\n";
  num++; 
}

void ArrayList::getNum() {
  std::cout << "Value of num: " << num << "\n";
}

```

### Accessing this `static` function in the `main()`
Now we are ready to test it out in the `main()`. To call a static method, you will need to use the `ArrayList::` syntax. 

```
#include "./ArrayList.h"  // need to include the header here too. 

int main() {
  ArrayList a; 
  a.printHelloWorld(); 
  a.printHelloWorld();
  ArrayList::getNum();  // This is the call to getNum()
  return 0; 
}
```
```
Output: 
Hello World
Hello World
The value of num 2
```

