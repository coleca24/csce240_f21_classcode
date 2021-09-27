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
