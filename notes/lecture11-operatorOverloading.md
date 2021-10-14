# Lecture 11 - Operator Overloading
Operator overloading is the concept that we can overload operators like the assignment (=) operator, addition (+) etc. within a C++ project.

## Motivation
When we use a C++ object like the std::string, we usually take for granted that we can do things like: 
```
std::string hello = "hello"; 
std::string world = "world"; 
cout << hello + world << "\n";
```
We know that the `+` operator will concatenate the two strings together and what will print out will be the string "helloworld". But why is this the case? This is because some C++ developer has overloaded the `+` operator in the std::string class! We can do the same in our classes to make them more user friendly.

Let's take that addition operator as an example in our ArrayList object. We will stick to concatenation, so:

```
ArrayList a(5, 1); // a.data == [1,1,1,1,1]
ArrayList b(2, 2); // b.data == [2, 2]
a + b; // == [1,1,1,1,1,2,2]
```
We would also want this operator to be cascade capable. This means that we would want to be able to do something like `c + b + a` (assuming a, b, and c are all objects). In order to make something cascade capable you usually return the object itself. So, in this case if we want this operator in the ArrayList to be cascade capable then we will want to return an ArrayList object. 

## Declaring in Header
The first step is to declare that you will be overloading an operator in the header file for an object. Let's thing about how the `+` operator is actually called. `a+b` is equivilant to `a.operator+(b)`. Keeping that in mind, the definition below should make sense! `b` is an ArrayList so you will need to take in an ArrayList object. 

ArrayList.h
```
class ArrayList {
  public: 
    ArrayList(); 
    ArrayList operator+(ArrayList); 
  private:
    int *data; 
    int size;
};
```

## Implementation in .cpp
Now we get to define what the `+` operator will actually do. Before implementing this function we need to decide whether the calling object should be modified or not. Remember that `a + b` is equal to `a.operator+(b)` and therefore `a` is the calling object. Should `a` be modified. Well, think about just a regular math expression: 
```
int x, y(4), z(10);
x = y + z; 
```
After y and z are added together, should the value of y change? No. We would not want y to change and therefore would not want the calling object to be modified. When it comes to object methods that we do not want the calling object to be modified we will need to create a new object within the function and return it as the result! 

The implementation of this function will be: 
```
ArrayList ArrayList::operator+(ArrayList rhs) {
  ArrayList ret(size+rhs.size, 0); // Here I am taking advantage of the constructor that 
                                   // takes in a size and default value. 
                                   // This gives me an object that has the right size, but all zeroes
  for (int i = 0; i < size; i++) {
    ret.data[i] = data[i];          // copy over the calling objects data
  }
  for (int i = 0; i < rhs.size; i++) {
    ret.data[i+size] = rhs.data[i];   // copy over the passed objects data
  }
  
  return ret;
}
```

## Calling in the main()

## Adding call-by-reference

## Adding const
