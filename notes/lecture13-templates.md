# Lecture 13 Templates
Sometimes you might want to have a single function or object be able to handle different data types. For example, you might want to make an `add` function that will handle `int` or `float` or `char`. To do this, you will need to implement templates. 

Your `add` function might look something like this:
```
template <class T> 
T add(T a, T b) {
  return a + b; 
}
```
The `template <class T>` specifies that you are going to use Templates in the function that follows, and that template will have the name of T. So anywhere that I want to be filled in automatically by the function call will have a `T` instead of another variable type. 

We can now use the function like so: 
```
int main() {
  int a(1), b(2), c(0); 
  float d(1.5), e(9.3), f(0.0); 
  c = a + b;
  f = d + e; 
}
```
Now instead of having to write 2 functions (one for ints and one for floats) we instead can just create the one that works for both! 

## Templates in Classes
We might also want to create objects with templates. Think about our ArrayList object. We might want to fill that ArrayList with `int` or `float` or `string` or even another object! 

The first step in implementing this is to add the `template <class T>` to the class header file. 

```
template <class T> 
class ArrayList {
};
```
Now you can use the `T` type to store data. 
```
template <class T> 
class ArrayList {
  public: 
    ArrayList(); 
  private:
    int size; 
    T *data;
};
```

You must also carry the `template <class T>` to the .cpp file as well. The new methods would look like this:
```
#include "ArrayList.h"

ArrayList<T>::ArrayList() {           // Notice that we have changed ArrayList:: to ArrayList<T>::
  size = 0; 
  data = new T[size];                 // Notice that now we use T instead of int
}
```

Now in the main we can create ArrayLists like so: 
```
int main() {
  ArrayList<int> iA;                  // An ArrayList of ints 
  ArrayList<float> fA;                // An ArrayList of floats
  ArrayList<ArralyList<int>> iiA;     // An ArrayList of ArrayLists of ints
}
```

A few notes about templates: 
1. For friend functions, you will need to use a different class (so you would not be able to use `T` you would need to use a different class for your friend functions. 
2. You will need to include the `ArrayList.cpp` in the main.cpp in order for the type to propegate to all of the `T`s. 
