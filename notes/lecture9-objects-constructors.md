# Lecture 9 - Intro to Classes and Objects and Constructors

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

## Creating an Object
When you want to use your new object, you need to create a new instance. Whenever a new object is created, it will call a special member function in the class called a constructor. These functions are the exact name as the object and have no return type. Their one and only job is to tell the C++ compiler how to construct or create a new instance of your class. There are many types of constructors the three main types are the default, alternate and copy constructor. 

### Default Constructor
The default constructor is added below. It takes in no arguments. Note that if no constructors are defined in a class then the C++ compiler will automatically provide one for you. It will not do what you want it to do, but it does technically exist! 
```
class ArrayList {
  public: 
    ArrayList();
  private: 
    int *data; 
    int size;
};
```

The definition of the default constructor may look something like this in the .cpp file (in this case the ArrayList.cpp). 
```
ArrayList::ArrayList() {
  size = 0; 
  data = new int[size]; 
}
```
### Parameterized/Alternate Constructors 

### Copy Constructor

### Destructors
