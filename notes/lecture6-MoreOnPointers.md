# Lecture 6 - More on Pointers
Pointers are just variables that hold a memory location. It is because they hold that memory location that we can have access to the variable that it is pointing to. In the figure below, `ptr` holds the memory location of `Var1` and therefore, will be able to access and modify its value. 

![image](https://user-images.githubusercontent.com/3376451/132876968-0854330a-efcf-42f4-a1ac-23aca0d4379c.png)

Continuing on with the example from the figure, if I were to write the following code:
```
// From figure
int Var1 = 100; 
int *ptr = &Var1;

// New code:
*ptr = 1000; 
cout << Var1 << "\n"; 
```
I would get `1000` as the output. The value of `Var1` was changed via `ptr` by "dereferencing" the pointer (\*prt = ). 

This is just one way that you can initialize a pointer. Here are several other ways: 
```
int *ptr = new int; // points ptr to an int that has been created in the heap
int *ptr = new int[5]; // points ptr to an int array 
                       //that has been created in the heap
int arr[5]; 
int *ptr = arr; // remember that if I were to print out arr then I would get a memory location! 
```
The rule of thumb, like all variable types, is to make sure that the value on the right-hand side of the assignment is of the right type (in this case, a memory location). Here are some examples of incorrect ways to initialize a pointer:
```
int *ptr = new float; // You cannot mix and match types. 
                      // if you define it as int then it must point to an int. 
ptr = 10; // You cannot set a pointer to any other value other than a memory location
prt = x;  // Again, x is an int, not a memory location. 
```

## More on `new` and `delete`
The `new` keyword will allocate memory in the heap. The `delete` keyword will deallocate the memory in the heap. For every `new` there should be a corresponding `delete`. If you miss a delete then you will "leak" memory (more on that later). Some examples: 
```
int *ptr = new int; // allocate an int in the heap
delete ptr;  // deallocate that int in the heap
ptr = new int[5]; // allocate an int array of size 5 in the heap
delete [] ptr; // delete the array in the heap (note the added [] to denote an array)
```
## Allocating and Deleting a 2d Array
Allocating n-dimensional arrays require 2 steps:
1. Allocate an array of pointers (of size = number of rows)
2. Initiialize each of those pointers to an array (of size = number of columns)

```
int ROWS = 5, COLS = 2; 
int **arr2d; 
arr2d = new int*[ROWS]; // step 1 described above
for(int i = 0; i < ROWS; i++) {
    arr2d[i] = new int[COLS]; // step 2 described above
}
```
Deallocating n-dimensional arrays also required 2 steps: 
1. Deallocate the inner arrays (the ones created in the for loop above)
2. Deallocate the main array (created in step 1 of allocation)

```
for(int i = 0; i < ROWS; i++) {
  delete [] arr2d[i]; // step 1 
}
delete [] arr2d; // step 2
```

## `valgrind` and `leaks`
These are the two memory checkers that we will use. They will check for any memory leaks. Valgrind is for Windows/WSL and Linux and leaks is for Mac. 

To use valgrind: 
```
g++ file.cpp
valgrind ./a.out
```

To use leaks: 
```
g++ file.cpp
leaks -atExit -- ./a.out
```
## Pointers as Parameters in Functions
We can send pointers as parameters in functions just like any other type. 
TODO: add examples
## Pointers as Returns in Functions
