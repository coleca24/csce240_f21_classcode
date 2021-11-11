# Lecture 18 STL Continued (More with Vectors in Functions and 2D Vectors)

## Vectors in Functions
You can pass a vector to a function as a parameter (as either call by value or reference) or return it (also by value or by reference). 

### As a parameter
Passing a vector as a parameter is just like passing any other data type. For example, if you wanted to make a print function, you could implement it like this: 
```
void print(vector<int> v) {
  for (int i : v) {
    cout << i << " "; 
  }
}
```
And call it like this:
```
int main() {
  vector<int> vect{1,2,3}; 
  vect.print(); 
}
```
In this function we passed the vector by value, however, we can also pass by reference. For example, you could make a initVector function that sets all the values of the vector. 
```
void initVector(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    v[i] = i; 
  }
}
```
And then call it like this:
```
int main() {
  vector<int> vect(2);
  initVector(vect); 
  vect.print();
}
```
The output would then be:
```
1 2
```

Note that the `&` in the parameter will make it so the changes that we make in the function are also reflected in the main. 

### As a return

## 2D Vectors

### Initializing

### Printing

### Removing a Row

### Removing a Column?

## Sets

## Maps
