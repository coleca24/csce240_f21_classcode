# Lecture 3 - Strings and Functions
---

## Strings
---
**Important** To use a string in C++, you must include the header for the string library: 
```
#include <string>
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
### String length

### Accessing elements

### User inputted strings

### An Array of strings?

## Functions
---
### Basics

*Function Prototype*

*Function Definition*

*All Together*

### Parmeters and Overloading

### Return Types

### Call-by-Value vs. Call-by-Reference

### `const` keyword

