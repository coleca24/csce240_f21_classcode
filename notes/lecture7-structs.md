# Lecture 7 - C++ Structs
In C++, when you want to create a collection of variables, but don't want to create a full-fledged object, then you can use a `struct`. I am going to refer to a `struct` as a "dumb" object that has just member variables and no functions, however, please note that a `struct` can have all these! However, in C++, it is typical that if you want to create a collection of variables with functions, then you would just create an object! 

## General Syntax
To create a `struct` you use the following syntax: 
```
struct [name] {
   [variable 1]
   [variable 2]
   ...
   [variable n]
}; // Don't forget the semicolon! 
```

For example, the following would declare a `struct` called `book` with 3 variables (`string title`, `string author`, `int pages`) 
```
struct book {
  string title; 
  string author; 
  int pages;
};
```

## Creating a `book` and Setting Values
To create a `book` in the `main()` you will declare it like any other variable type (like `string` or `int`). For example, the following will create one `book` named `b1` and set it's values. 
```
int main() {
  book b1; 
  b1.title = "Absolute C++"; 
  b1.author = "Walter Savitch"
  b1.pages = 500; 
}
```

## Creating an Array of `structs`
You can create a primitive array of `struct`s just like you can with any other type. For example, the code below will create an array of 5 `book` structs and set all the contents to default values. 
```
int main() {
  book collection[5]; 
  for (int i = 0; i < 5; i++) {
    collection[i].title = "NULL"; 
    collection[i].author = "NULL"
    collection[i].pages = 0;
  }
}
```

