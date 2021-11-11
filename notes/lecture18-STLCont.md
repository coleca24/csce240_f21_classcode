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
  print(vect); 
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
  print(vect);
}
```
The output would then be:
```
1 2
```

Note that the `&` in the parameter will make it so the changes that we make in the function are also reflected in the main. 

### As a return
You can also return vectors. This works exactly how it works with all other types. For example, if I wanted to create an addOne function that would create a copy of a passed vector and append a one to the end, I would do that by returning a vector from that function with the new values. 
```
vector<int> addOne(vector<int> v) {
  vector<int> ret(v); // use copy constructor to make a copy of v
  ret.push_back(1);    // append 1
  return ret;
}
```
And then you can call it:
```
int main() {
  vector<int> v{1,2,3};
  vector<int> v2;
  v2 = addOne(v); 
  print(v); 
  print(v2); 
}
```
The output would be:
```
1 2 3
1 2 3 1
```
## 2D Vectors
2D Vectors are just vectors of vectors. So a 2d int vector would be: 
```
vector<vector<int>> v;
```
### Initializing
This is now a little more tricky to initialize. The general process for our vector of ints will be to create a vector<int> with all of the values for a row and then push that row back to the main vector. Example:
```
vector<vector<int>> v; 
vector<int> row; 
row.push_back(1); 
row.push_back(2); // Now row has [1, 2] 

v.push_back(row); // Now v == [1, 2]
v.push_back(row); // Now v == [1, 2
                               1, 2]
```

### Printing
You can print the 2d vector with a foreach loop, a traditional for loop or an iterator (I do not suggest that so I will not show it here). 

For each: 
```
... Assume we have the v vector from the example that was above ... 
for (vector<int> row : v) {       // each element in v is a vector<int>
  for (int i : row) {             // each element in row is an int
    cout i << " "; 
  }
}
```
Traditional for:
```
  for (int i = 0; i < v.size(); i++) { // loop through rows
      for(int j = 0; j < v[i].size(); j++) { //loop through columns
        cout << v[i][j] << " "; 
    }
  }
```

### Removing a Row
Removing a row is easy. You just need to use the pop_back or erase at the right index. You would do the exact same process that we did with 1d arrays and erasing elements (create iterator, point iterator to where you want to erase, and then erase). 

### Removing a Column?
Hmm... more tricky. Remember that each element in the 2d vector is a vector, so to remove a column you would need to loop through all of the vectors within the main vector and remove the correct element (that corresponds to the column you want to remove). For example, if you wanted to remove the last column, you might do something like this: 
```
  We will assume we have v again (from above)
  for (int i = 0; i < v.size(); i++) {
     v[i].pop_back();
  }
```
This will remove the last column, however, if you wanted to remove a column in the middle of a row then you would need an iterator each time through the loop to point to the correct element in each column!                              
