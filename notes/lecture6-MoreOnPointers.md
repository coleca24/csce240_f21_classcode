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
## Allocating and Deleting a 2d Array
## `valgrind` and `leaks`
## Pointers as Parameters in Functions
## Pointers as Returns in Functions
