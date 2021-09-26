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

### Copy Constructor

### Destructors
