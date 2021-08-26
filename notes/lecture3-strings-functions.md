# Lecture 3 - Strings and Functions
---

## Strings
---
**Important** To use a string in C++, you either need to explicitly specify a namespace (ie. `std::string`) or you can tell your program that you are using just the string from std.  
```
using std::string;
```
Remember that a C++ string is not a primative type, it is an object. This means that it has functions and properties associated with it. For a full list, see the documentation here: <https://www.cplusplus.com/reference/string/string/>

### Creation of a String
The following example is the two common ways that you will be creating strings throughout the course, however, there are several other ways to create a new string (see documentation <https://www.cplusplus.com/reference/string/string/string/> ).
```
string str1 = "hello";
string str2("bye"); 
std::cout << str1 << " " << str2;
```
`output: hello bye`

### Concatenation
You can create a new string from a series of strings using concatenation with the `+` operator or using the `.append()` function. 

Examples: 
```
string firstName = "Casey";
string lastName = "Cole";
string fullName = firstName + " " + lastName;
std::cout << fullName;
```
`output: Casey Cole`

```
string firstName = "Casey";
string lastName = "Cole";
string fullName = firstName.append(" ").append(lastName);
std::cout << fullName;
```
`output: Casey Cole`

Note that you cannot use the `append()` or the `+` operator with mixed types. For example, you cannot add a string to an int. In some other programming languages the int will be automatically casted to a string and be concatenated. Not in C++. 

### String length
There are two ways that you can get the number of characters in a string. You can use the `size()` function or the `length()` function. Both will return the number of bytes in the string... and... since a string is essentially an array of chars and a char is 1 byte... this will give you the number of characters. 

Example:
```
string test = "test";
std::cout << "The length of test is " << test.length() << std::endl; 
std::cout << "The size of test is " << test.size() << std::endl; 
```
```
output: 
The lenth of test is 4
The size of test is 4
```

### Accessing/Modifying elements of strings
C++ strings have random access. The elements of a string can be accessed exactly how you access an array's elements. 

Examples:
```
string test = "test"; 
std::cout << test[1];
```
`output: e`

```
string test = "test";
test[0] = 'r';
std::cout << test; 
```
`output: rest`

### User inputted strings
We can get input from the user using the `std::cin` stream and store them in a string. However, it is worth noting that C++ interprets a space (or multiple spaces) as a terminating character. 

Example: 
```
string name; 
std::cout << "Enter your name: "; 
std::cin >> name; 
std::cout << "Name: " << name; 
```
```
output: 
Enter your name: Casey Cole
Name: Casey
```

What this means is that if you want to have the user enter text that has a space in the middle and store it in a string variable using just `std::cin` you would need to do something like this:
```
string f_name, l_name; 
std::cout << "Enter your name: "; 
std::cin >> f_name >> l_name; 
std::cout << "Name: " << f_name << " " << l_name; 
```
```
output: 
Enter your name: Casey Cole
Name: Casey Cole
```

We will learn in a later lecture about how to simplify this using the `getline()` function! 

### An Array of strings?
Sure! Same syntax as the other primative arrays (replace type with string)

## Functions
---
### Basics
We are going to stay in the functional world for a while to get the hang of coding in C++. A C++ function has three main parts: the prototype, the definition and the call. 

*Function Prototype*

This goes above the main function (or above any function that will be using the function). The main needs to see what this prototype looks like in order for you to use it in the main. The prototype has three main parts: the return type, the function name and the parameter type list. 

**Google Style Sheet** says: regular function have mixed case (camel case). For example: 
```
void AddTableEntry(); 
void DeleteEntry();
```

For the parameter list, names for each of the variables do not need to be given, just the type (int, float, etc) of the parameter. 

Functions can return primitive types, pointers and objects. They cannot return primitive arrays.

For example, if I were to make an `add()` function that I wanted to take in two ints and return an int, then my prototype would look like this: 
```
int add(int, int); 
```

*Function Definition*

The definition is where you define the actions that the function should take given the parameters that it is passed. This is added under the main function. At this point, you will need to give your parameters a name so that you can use them! For example, the definition for the add function would look something like this:
```
int add(int num1, int num2) {
  return num1 + num2; 
}
```

*Function Call*

Now that you have defined the function, you are ready to actually use the function. To use the function, you will issue a function call. This call may be in other user defined functions or in the main function. The function call can be repeated multiple times. An example of a call to the add function is: 
```
int sum = 0; 
sum = add(10,10); 
```

*All Together*

Here is how this would look in your cpp file: 
```
#import <iostream> 

int add(int,int); 

int main() {
  int sum = 0; 
  sum = add(10,10);
}

int add(int num1, int num2) {
  return num1 + num2; 
}
```

### Overloading functions
To overload a function means to create more than one function with the exact same name. This is useful in a variety of situations. For example, if you wanted to make a universal print function that the user just needs to call using `print(<whatever they want to print>)`. You will want the user to be able to pass in a string OR an int OR ... so you might define the following set of overloaded `print()` functions: 
```
void print(string); 
void print(int); 
void print(float);
etc. 
```
Now the user will be able to print any type by using the same syntax! Very convienient! 

**NOTE** in order for C++ to be able to choose which function to use, you have to vary the parameters for each overloaded function. It is not enough to vary, for instance, the return type. 

For example, C++ will see these as identical functions and will not know which function to choose and therefore will not compile. 
```
int sum(int,int);
float sum(int,int);
```

### Call-by-Value vs. Call-by-Reference
This concept is critical in starting to understand how C++ interacts with your computer's memory. 

**Call-by-Value** is just a typical function. These are the ones that we are used to from other programming languages. You send in parameters and return some value (or nothing). We know that if we pass variables to functions, if we were to change the value of that variable in the function definition, then the changes would just be local to that function (the changes would not propegate back to the function that you called it from). 

Let me show you what I mean, take the following example of an `add()` function. If I were to change the value of `n1` in the `add()` function, that would not change the value of the `num1` variable in the `main()` function. The output would still be 10. 
```
#import <iostream> 

int add(int,int); 

int main() {
  int sum = 0; 
  int num1 = 10; 
  int num2 = 10; 
  sum = add(num1,num2);
  std::cout << num1; 
}

int add(int n1, int n2) {
  n1 = 1;
  return n1 + n2; 
}
```
```
output: 10
```

**Call-by-Reference** is where things get a little funky. Instead of sending a seperate copy of the variable, we send what is called a "reference" to the variable. This reference is actually the memory location of the variable in memory. This means that any changes that you make in the function to that variable will be reflected in the `main()`. The way that you specify that you want a variable to be Call-by-Reference is by adding an ampersand (&) to the variable in the function prototype. 

If we change around our previous example so that the first `int` is passed by reference (`int&`) instead of value (`int`), notice that now our output is 1. The change that we made in the `add()` function is reflected in the main! 
```
#import <iostream> 

int add(int&,int); 

int main() {
  int sum = 0; 
  int num1 = 10; 
  int num2 = 10; 
  sum = add(num1,num2);
  std::cout << num1; 
}

int add(int &n1, int n2) {
  n1 = 1;
  return n1 + n2; 
}
```
```
output: 1
```

### `const` keyword

### Default values

### Example of a unit-tested function

