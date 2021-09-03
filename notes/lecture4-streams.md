# nd-Arrays/Functions, `printf`, Streams and File I/O

## nd-Arrays and Functions
Remember that when you pass an array in C++ it will always be call-by-reference. It is the same with nd-Arrays. In addition, with nd-arrays you will also need to pass the size of all dimensions other than the first dimension. Here's what I mean: 

Take the following 2d array and an implementation of a function to print the array. 
```
void printArray(int arr[][]); // This would not work! 
void printArray(int arr[][2]): // This would work! 

int array2d[2][2] = { {1, 2}, {3, 4} }; 
```
However, a better way to pass the second dimension of the array would be to use a constant global variable (shown below). This is one instance where a global variable is a better alternative. 
```
const int COLS = 2;  
void printArray(int arr[][COLS]): 

int array2d[2][2] = { {1, 2}, {3, 4} }; 
```

## `printf()` function


## Streams

### cin/cout

### `getline()` function

## File I/O
