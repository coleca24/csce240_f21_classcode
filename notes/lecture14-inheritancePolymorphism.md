# Lecture 14 Inheritance and Polymorphism
When we decide to create a new object, we find sometimes find that the object that we want to create has a lot of overlap with an object that is already created (either by us or other developers). To save time, we do not want to redefine functions, so instead we will usually just inherit from that class. That way our new object will have all of the functionality of the inherited class AND more. 

## Defining a Child Class
Let's assume a parent class of: 
```
class Parent {
  public: 
    Parent(){
      cout << "Parent Default\n";
      num = 10; 
    }
  private:
    int num; 
};
```

To define a child class that inherits from this `Parent` class you would do the following:
```
#include 'Parent.h"
class Child : public Parent {
  public:
    Child() {
      cout << "Child Default\n"; 
      anotherNum = 30; 
    }
  private:
    int anotherNum; 
  
};
```

The `: public Parent` defines that we are inheriting "publically" from the `Parent` class (more on what this "publiclly" means later). Now the `Child` class will automatically have a `num` variable (inherited from the `Parent` class). 

Let's set up a `print` function so that we can print the values of the member variables. 
```
class Parent {
  public: 
    Parent(){
      cout << "Parent Default\n";
      num = 10; 
    }
    void print() {
      cout << "Num: " << num << "\n";
    }
  private:
    int num; 
};

class Child : public Parent {
  public:
    Child() {
      cout << "Child Default\n"; 
      anotherNum = 30; 
    }
    void print() {
      cout << "Another Num: " << anotherNum << "\n";
    }
  private:
    int anotherNum; 
  
};
```
If we were to create a new Child in the `main` and call the `print` function we would get the following:
```
int main() {
  Child c; 
  c.print()
}

// Output:
// Another Num: 30 
```
Now what if we wanted to also print out `num` (from the `Parent` class)? We might try the following in the Child class:
```
class Child : public Parent {
  public:
    Child() {
      cout << "Child Default\n"; 
      anotherNum = 30; 
    }
    void print() {
      cout << "Num: " << num << "\n";
      cout << "Another Num: " << anotherNum << "\n";
    }
  private:
    int anotherNum; 
  
};
```
However, we would not be able to directly access `num` from the `Parent` class like this! Instead, we would just call the `Parent` print method instead: 
```
class Child : public Parent {
  public:
    Child() {
      cout << "Child Default\n"; 
      anotherNum = 30; 
    }
    void print() {
      Parent::print();
      cout << "Another Num: " << anotherNum << "\n";
    }
  private:
    int anotherNum; 
  
};
```
The `Parent::` is equivilent to the `super.` call in Java. Now if we printed it would print:
```
int main() {
  Child c; 
  c.print()
}

// Output:
// Num: 10 
// Another Num: 30 
```

The other way that we could solve this is to change the `num` variable from being `private` to `protected`. The `protected` keyword means that that variable will act like a `private` member variable in the `main` and a `public` variable to the `Child` class. 
```
class Parent {
  public: 
    Parent(){
      cout << "Parent Default\n";
      num = 10; 
    }
    void print() {
      cout << "Num: " << num << "\n";
    }
  protected: 
    int num; 
};

class Child : public Parent {
  public:
    Child() {
      cout << "Child Default\n"; 
      anotherNum = 30; 
    }
    void print() {
      cout << "Num: " << num << "\n"; // Now we would have direct access. 
      cout << "Another Num: " << anotherNum << "\n";
    }
  private:
    int anotherNum; 
  
};
```

Also notice, that when you print out a Child object, the `num` variable is set to 10 (which is done in the `Parent` constructor). This happens because the `Child` constructor will call the `Parent` class's default constructor by default. If you wanted to change this, you may add another alternate constructor in the `Parent` class (`Parent(int)`) and call that instead in the `Child` class by putting a ` : Parent(10)` after the `Child` constructor prototype (see below!). 
```
class Parent {
  public: 
    Parent(){
      cout << "Parent Default\n";
      num = 10; 
    }
    Parent(int val) {
      num = val;
    }
    void print() {
      cout << "Num: " << num << "\n";
    }
  protected: 
    int num; 
};

class Child : public Parent {
  public:
    Child() : Parent(30) {  // Calling the alt. constructor in Parent
      cout << "Child Default\n"; 
      anotherNum = 30; 
    }
    void print() {
      cout << "Num: " << num << "\n"; // Now we would have direct access. 
      cout << "Another Num: " << anotherNum << "\n";
    }
  private:
    int anotherNum; 
  
};
```
Now if we define a `Child` and print we will get the following output:
```
int main() {
  Child c; 
  c.print()
}

// Output:
// Num: 30
// Another Num: 30 
```

Things to remember: 
1. Child classes do not have direct access to the parent's private member variables
2. The constructors, destructor, assignment operator and friend functions are not inherited by the child (you can call them, but they are not directly inherited). 

### 3 Ways to Inherit
There are 3 ways to inherit: 1) `public` 2) `private` and 3) `protected`. The differences between the three are just in the way that those modifiers (public, protected, private) are changed in the child class. 
- `public` : all public member variables/functions in the parent are public in the child, all protected member variables/functions are protected in the child
- `protected` : all public and protected member variables/functions are protected in the child
- `private` : all public and protected member variables/functions are private in the child

## Polymorphism
Polymorphism is when we have a parent object that we define or set equal to one of the child objects. Because it is related to the child classes, this is permissible and can sometimes be advantageous. Usually in C++ this is done via object pointers. Example:
```
int main() {
  Parent *p; 
  Child c; 
  p = &c;
}
```
Now `p` is pointing to a `Child` object. However, if I were to call the print function using `p`, I would get the following: 
```
int main() {
  Parent *p; 
  Child c; 
  p = &c;
  p->print(); 
}

// Output: 
// Num: 30 
```
Now, I might have been expecting to get the `Child` output since `p` is pointing to a `Child`, but I would not. This issue stems from static definitions of functions by the compiler. Once you tell the compiler that `p` is a Parent, then that will forever be what it thinks `p` is, regardless of what you point it to. We need to fix this if polymorphism is to be useful! We will do that using virtual functions! 

## Virtual Functions
Making a function virtual will allow for dynamic linking. For example, in the case of our `Parent` pointer that is pointing to a `Child` we can make the `print` function to be dynamically linked so that when we call the `print` we will get the `Child` `print`. 

All we need to do is make the following update to the `Parent` class:
```
class Parent {
  public: 
    Parent(){
      cout << "Parent Default\n";
      num = 10; 
    }
    Parent(int val) {
      num = val;
    }
    virtual void print() {           // Note the virtual keyword
      cout << "Num: " << num << "\n";
    }
  protected: 
    int num; 
```

Now when we run this code, we will get the expected output. 
```
int main() {
  Parent *p; 
  Child c; 
  p = &c;
  p->print(); 
}

// Output: 
// Num: 30 
// Another Num: 30 
```

## Abstract Classes
Abstract classes are those that we cannot instantiate (ie. we would not be able to make a new Object in the main). We can make a class to be an Abstract class (similar to an interface in Java) by making at least one of its functions to be pure virtual. For example, the `print` function below would be a pure virtual function:

```
class Parent {
  public: 
    Parent(){
      cout << "Parent Default\n";
      num = 10; 
    }
    Parent(int val) {
      num = val;
    }
    virtual void print() = 0; 
  protected: 
    int num; 
 };
```

And that would mean that any Child that inherits from it would need to implement that `print()` function (example below)
```
class Child : public Parent {
  public:
    Child() : Parent(30) {  // Calling the alt. constructor in Parent
      cout << "Child Default\n"; 
      anotherNum = 30; 
    }
    void print() {
      cout << "Num: " << num << "\n"; // Now we would have direct access. 
      cout << "Another Num: " << anotherNum << "\n";
    }
  private:
    int anotherNum; 
  
};
```

If a child class does not implement all of the pure virtual functions then it will also become abstract. 
