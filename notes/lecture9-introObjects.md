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

