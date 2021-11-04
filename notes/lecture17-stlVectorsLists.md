# Lecture 17 STL Vectors and Lists
**Note that lecture 16 notes are in the slide show on dropbox.cse.sc.edu**

In lecture 17, we took a closer look at implementing the `vector` and `list`. In addition, we talked about why we would use one over another and discussed the `sort` algorithm. 

## The `vector` Container
The `vector` container holds a contiguous array of elements. You can think of it as our dynamic array.

### Construction
There are several different ways to create a `vector`. Here are a few examples: 
```
vector<int> vect{1,2,3,4,5}; // creates a vector with the elements 1 2 3 4 5

vector<int> vect1(vect.begin()+1, vect.end()); // creates a vector with the elements 2 3 4 5 

vector<int> vect2(10); // creates a vector of size 10 with all 0's
```
Note that in the second example, the constructor does not take in the raw location of the elements that are to be copied from vect, but instead two iterators (one pointing to the first element to be copied and the second pointing to the last element). 

### Printing
Recall from the lecture 16 slide show, there are many ways to print a vector. Here are two ways.

With iterators
```
for (auto current = vect.begin(); current != vect.end(); current++) {
  cout << *current << " "; // remember we use the * to get the value
}
```

With a foreach loop
```
for (auto i : vect) {
  cout << i << " ";
}
```
`auto` in the first example above will resolve to `std::vector<int>::iterator`. For the second, `auto` will resolve to `int` due to the fact that vect has ints in it. 

### Adding Elements

### Removing Elements

## The `list` Container

### Construction

### Adding Elements

### Removing Elements

## The `sort` Algorithm

### Sorting with Custom Function

### Sorting Exercise Solution

## List vs. Vector Benchmarking 
