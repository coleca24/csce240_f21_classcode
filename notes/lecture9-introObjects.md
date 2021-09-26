# Lecture 9 - Intro to Classes and Objects

## C++ Class Definitions
To define an object in C++ you will need two files: a header (or .h file) and an implementation file (.cpp). In the header file (.h) you should have the class definition. This is just a collection of prototypes for member functions as well as declarations of member variables. The syntax for this is the following: 
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

