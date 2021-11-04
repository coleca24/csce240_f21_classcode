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
We can add elements to a `vector` using the `insert` or the `push_back` methods. 

The `push_back` method will add a new element to the end of a vector. For example, the following code will add the value `2` to the end of the `vector<int> vect`. 
```
vector<int> vect{1,2,3}; // Vector with values 1, 2, 3
vect.push_back(2);       // Now the vector will have the values 1, 2, 3, 2
```

While `push_back` adds elements just to the end of a `vector` the `insert` method will allow you to add an element anywhere in the `vector`. It works by using iterators. Steps to insert a new element: 
1. Create an iterator
2. Increment the iterator to point to the place in which you want to insert the value
3. Use the insert by passing the iterator and the new value. 
Example: 
```
vector<int> vect{1,2,3};      // vector with values 1 2 3 
vector<int>::iterator it;     // 1) Create an iterator
it = vect.begin();            // 2) Point the iterator to the begining of the vector
vect.insert(it, 0);           // 3) Insert the value 0 at the beginning of the vector (new values 0 1 2 3)
```

Another example (inserting at index 3): 
```
vector<int> vect{1,2,3,4,5};    // 1 2 3 4 5
auto it = vect.begin()+3;       // Create the iterator and point it to the the beginning + 3 indices
vect.insert(it, 0);             // 1 2 3 0 4 5
```

### Removing Elements
We can remove elements from a `vector` using either the `pop_back` or the `erase` methods. 

The `pop_back` will remove the last element from a vector. For example, the following code will remove the last value (3) from the vector. 
```
vector<int> vect{1,2,3};    // 1 2 3
vect.pop_back();            // 1 2
```

The `erase` method will let you remove an element from any index of a vector. This will work by using iterator just like the `insert`. You will need to: 
1. Create a iterator
2. Point the iterator to the spot in the `vector` that you want to remove
3. Pass the iterator to the erase function. 
Example:
```
vector<int> vect{1,2,3};    // 1 2 3
auto it = vect.begin();     // Point the iterator to point to the first element
vect.erase(it);             // 2 3
```

## The `list` Container

### Construction

### Adding Elements

### Removing Elements

## The `sort` Algorithm

### Sorting with Custom Function

### Sorting Exercise Solution

## List vs. Vector Benchmarking 
