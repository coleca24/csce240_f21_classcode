# Lecture 12 More Operator Overloading and Friend Functions
Nearly every operator can be overloaded in C++, and you can make them "do" whatever you want them to. That means that you can make the `=` operator do something like subtraction or addition. You wouldn't... but you could. This is a lot of freedom, however, there are some rules. 
1. You cannot change the presdence of operators (* will always come before +, for instance). 
2. You cannot change the number of parameters they take in (the = operator will always just take in one parameter)

The following are some special cases that you should be aware of:
## `operator[]`
We use the `[]` to do assignment and extraction, however, we only ever give it just one int (one parameter). So how is it that we can overload this operator to do two different things if the prototype will only ever take in one int? In C++, we make two prototypes that are almost identical, however one will return the reference to the value that we want to set and the other will just return the data and be marked as const qualified (this one will be the extractor). 

```
int operator[](int index) const;      // Extraction cout << Obj[0]  
int& operator[](int index);           // Setter Obj[0] = 1
```
They are both implemented in the same way: 

```
...
  return data[index];
...
```
The way that the setter works is that it returns the memory location of the element so that it can be set. 

## Pre and Post (++Obj and Obj++) 
These are unary operators that do not take in any logical parameter. However, they work in two distinct ways. 

Let's take the example of just ints for now, for the pre: 
```
int x(0), y(0); 
x = ++y; 
```
After execution, both x and y will have the value of 1. 

However, this is not the case for the post. 
```
int x(0), y(0); 
x = y++; 
```
After this is executed, the value of y will be 1, but the value of x will still be 0. That is what is meant by "post" increment. First the old value is returned and *then* it is incremented. 

So, we will want to have a way that the C++ compiler can tell the difference when we are using the operator on either side of the object. There was really no clean way of doing this so the C++ developers decided on this: 
```
ArrayList operator++();     // This one is for pre
ArrayList operator++(int);  // This one is for post
```
Note that the `int` that is passed to the post is absolute garbage and should not be used at all in the implementation! 

## Friends
