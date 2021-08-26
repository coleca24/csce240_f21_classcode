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
Todo: add code here
```

What this means is that if you want to have the user enter text that has a space in the middle and store it in a string variable using just `std::cin` you would need to do something like this:
```
Todo: add code here
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

### Parmeters and Overloading
For the parameter list, names for each of the variables do not need to be given, just the type (int, float, etc) of the parameter. 

### Return Types
Functions can return primitive types, pointers and objects. 

### Call-by-Value vs. Call-by-Reference

### `const` keyword

### Default values

### Example of a unit-tested function
