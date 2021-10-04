# Lecture 10 - Object Constructors

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
An object can have as many alternate constructors as you want as long as each definition is distinguishable from each other (varied parameters). For example, we may want to make a constructor for our ArrayList that takes in a size and a value to initialize each value of the `data` array to. We might design that constructor to look like this: 
```
ArrayList::ArrayList(int size, int value) {
  this->size = size; 
  data = new int[size]; 
  for (int i = 0; i < size; i++) {
    data[i] = value; 
  }
}
```

**`this`**

The `this` keyword is similar to Java. It is a pointer to the object itself (that is why we must use the `->` syntax). We needed to use the `this` keyword in the constructor above because the parameter passed to the constructor was named the same as the member variable (`size`). To set the object's `size` and not just the local passed `size` we need to execute the assignment: `this->size = size`. 

**Adding Default Values**

### Copy Constructor
The copy constructor is a special constructor that does not exist in Java. Its job is to tell the C++ compiler how to actually copy your object. This allows you to be able to pass an object by value into a function (create a local copy). Its implementation is very straightforward. The goal is just to copy the contents of the passed object into the object being constructed. 

ArrayList.h
```
class ArrayList {
  public: 
    ArrayList();
    ArrayList(const ArrayList&); // Copy Constructor
  private: 
    int *data; 
    int size;
};
```
ArrayList.cpp
```
ArrayList::ArrayList(const ArrayList & copy) {
  size = copy.size; 
  data = new int[size];
  for (int i = 0; i < size; i++)  {
    data[i] = copy.data[i];
  }
}
```

### Destructors
An object's destructor is called automatically at when an object goes out of scope. The C++ compiler will automatically create a default destructor for you if you do not. However, it will not do what we probably want it to do! Below, the destructor has been added to the class definition of our ArrayList: 

ArrayList.h
```
class ArrayList {
  public: 
    ArrayList();
    ArrayList(const ArrayList&);
    ~ArrayList();  // destructor
  private: 
    int *data; 
    int size;
};
```
For objects that use dynamic memory, the destructor for an object will clean up (deallocate) any dynamic memory created in the object. For example, the destructor for the ArrayList object would look like this: 

ArrayList.cpp
```
ArrayList::~ArrayList() {
  delete [] data;
}
```

## Using a Constant Variable
You can define constant variables in an object as member variables. Example: `pi` variable below. 

ArrayList.h
```
class ArrayList {
  public: 
    ArrayList();
    ArrayList(const ArrayList&);
    ~ArrayList();  // destructor
  private: 
    int *data; 
    int size;
    const float pi; 
};
```

To initialize them, you will need to use the following syntax in the .cpp implemenation file: 
ArrayList.cpp
```
ArrayList::ArrayList() : pi(3.14) {
  /// ....
}
```
You cannot just say `pi = 3.14` in the body of the constructor (the `=` operator does not work for const variables - for good reason!). If you had multiple constant variables you would list them like this (assume pi, num1, and num2 are all const). 
ArrayList.cpp
```
ArrayList::ArrayList() : pi(3.14), num1(10), num2(8) {
  /// ....
}
```
**Remember** You will need to do this for each constructor!

## Member Functions
You can now define an infinite set of member functions. For each function, you will want to add a prototype in the header (with a return type, name and parameter type list) and then you will add the function implementation in the .cpp implementation file in the following form: 

```
return_type ClassName::function_name(para1 name1, para2 name2 ... ) {
}
```
Notice that the return type of the function is before the ClassName::!

We went over two examples in class, the insert and the remove. See the code in 002/lect8-classes for the implementation of those two functions. 

## Getters and Setters
When you are defining your functions within a class and another object is passed as an argument then you will have direct access to their member variables via the `.` operator (look at the copy constructor implementation for an example). This is not the best practice. Instead, you would want to define getters and setters (or accessors and mutators). The reason being is that you can adding some extra checking within the functions so that you are not accidentally setting something like size equal to a negative number (or somthing crazy like that). For example, for the size variable, you would write these like so in the header:
ArrayList.h
```
class ArrayList {
  public: 
    ArrayList();
    ArrayList(const ArrayList&);
    ~ArrayList();  
    int getSize();  // Getter for size 
  private: 
    int *data; 
    int size;
    const float pi; 
    void setSize(int);  // Setter for size
};
```
Notice that the getter is usually public and the setter is always private. The implementation for these, might go something like this: 
ArrayList.cpp
```
int ArrayList::getSize() {  // Notice that the return goes before the ArrayList::
  return size; 
}

void ArrayList::setSize(int size) {
  if (size >= 0) {
    this->size = size; 
  } else {
    std::cout << "Invalid size\n";
    exit(1);
  }
}
```
Notice that the `setSize(int)` first checks to see if the size is non-negative and only set it if it is. If not, then it returns an error message and exits the program. 

## Constant vs. Non-constant functions
Now, if you try to straight use these in the copy constructor, for example: 
ArrayList.cpp
```
ArrayList::ArrayList(const ArrayList & copy) {
  setSize(copy.getSize()); 
  data = new int[size];
  for (int i = 0; i < size; i++)  {
    data[i] = copy.data[i];
  }
}
```
You will get an error! The error relates to the fact that `copy` is a constant object that can only call functions that have been const modified. In C++, you have to tell the compiler which of your member functions a constant object should be able to call and which they cannot. To define a const modified function (one that a constant object can call) you simply add the const keyword after the protoype in the header and in the cpp file: 

ArrayList.h
```
class ArrayList {
  public: 
    ArrayList();
    ArrayList(const ArrayList&);
    ~ArrayList();  
    int getSize() const;  // Added const here
  private: 
    int *data; 
    int size;
    const float pi; 
    void setSize(int); 
};
```

ArrayList.cpp
```
int ArrayList::getSize() const {  
  return size; 
}
```
Notice that we did not add a `const` to the setter for size. That is because the only functions that should be const modified are the ones that will NOT modify the object that is calling it. `setSize(int)` by very nature will modify the object! 
