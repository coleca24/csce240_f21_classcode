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
A STL `list` also holds a collection of elements like a `vector`, however, as we saw in the lecture 16 slides, the elements are not stored in contiguous memory like a `vector`. Instead, it is stored as linked elements in noncontiguous memory.

### Construction
Creation of a `list` is identical to the creation of a `vector`. 

Here are some examples (note that these are also available to you in the `vector` class!
```
list<int> list1;    // Default empty list with size == 0
list<int> list2{1,2,3,4,5}; 
list<int> list3(list2);       // copy constructor
```

### Adding Elements
For a list, you have the same `push_back` and `insert` that you have in the `vector`. They are used in the exact same way. However, with a `list` you also have a `push_front` method. This method will add a new element to the front of the list. 

Example: 
```
list<int> list1{1,2,3,4,5};       // 1 2 3 4 5
list1.push_front(0);              // 0 1 2 3 4 5
```

### Removing Elements
For a list, again, you also have the same `pop_back` and `erase` that you have in the `vector` container and they work in the exact same way. In a list, you also have a `pop_front` method. This method will remove the first element in the list. 

Example: 
```
list<int> list1{1,2,3,4,5};       // 1 2 3 4 5
list1.pop_front();                // 2 3 4 5
```

## Lists vs. Vectors
At this point, a good question to ask yourself is "why does a list allow pushing and popping from the front, but a vector does not?" Good question! This all goes back to how these two containers are stored in memory. Let's consider the following: 
```
vector<int> vect; 
vect.reserve(100); 
```
In this code, we have reserved at least 100 ints of space for our vector. Therefore, we can start adding elements to the end with no problem (of course until we get to 100 ints). Once we get to 100 ints, we can still add to the end and, if there is another memory space available after the last element then we can just resize and add it there (minimal effort - no copying things over etc). However, the moment that we try to insert to the front: 
```
vect.insert(vect.begin(), 10); 
```
We cannot just resize in place, but instead, we will need to fully copy the vector to a new spot in memory and make that new element the first element. 

Now, how is a list different? Well, since a list is noncontiguously stored, there is no issue here! We can just make a new element, put it in an empty spot in memory and then reset the `begin()` iterator to that new node! 

Due to these differences, you will need to carefully consider what data structure to use for a given application as the choice can have profound effciency effects. For example, you may only want to use a `vector` when your data will be fairly stable (not a lot of inserts and removal) and use a `list` when you will need to be resizing frequently!

## The `sort` Algorithm
This will be the first algorithm that we will look at. It is a simple algorithm that we all should have some familiarity with... sort! This algorithm will sort the elements of a container in either increasing or decreasing order. Like all STL algorithms, the sort works with iterators. You will need to give it an iterator that points to the first element that you want sorted and the last element. For example, the following code will sort the vector in ascending order (smallest to largest). 
```
vector<int> vect{11,4,3,18,1};      // 11 4 3 18 1
sort(vect.begin(), vect.end());     // 1 3 4 11 18
```
You can also change this to only sort part of your array by changing the offset of the iterators. This example will only sort elements 1 - 4 and leave element 0 alone.
```
vector<int> vect{11,4,3,18,1};        // 11 4 3 18 1
sort(vect.begin()+1, vect.end());     // 11 1 3 4 18
```
### Sorting with Custom Function
You can, of course, change this ordering for the sort algorithm. To do this you will need to set up a custom function to pass to the `sort` that tells it, of two elements, which should be put before the other. For example, if you wanted to change the order to be descending order (bigger to smaller) then you could define and use a custom function like this:
```
bool compare(int one, int two) {
  return one > two; 
}
... 
vector<int> vect{11,4,3,18,1};               // 11 4 3 18 1
sort(vect.begin(), vect.end(), compare);     // 18 11 4 3 1
```
You can also use something like this to use the sort algorithm to sort vectors of objects. 
```
bool compare(Object one, Object two) {
  if (one.var1 > two.var2) return true;
  else return false;
}
...
vector<Object> vect;   
sort(vect.begin(), vect.end(), compare);  
```
You can of course change the `compare` method to check other variables within the Object as well!

### Sorting Exercise Solution
My exercise to you all was to take this vector: 
```
vector<int> unsorted{11, 2, 0, 4, 8};
```
And sort it so that it was in the order 2, 11, 0, 8, 4 (acsending in the first two elements, leave the middle alone, descending in the last two elements). You may have come up with something like this:
```
bool compare(int a, int b) {
  return a > b; 
}
vector<int> unsorted{11, 2, 0, 4, 8};                  // 11 2 0 4 8
sort(unsorted.begin(), unsorted.begin()+1);            // 2 11 0 4 8
sort(unsorted.begin()+3, unsorted.end(), compare);     // 2 11 0 8 4
```
