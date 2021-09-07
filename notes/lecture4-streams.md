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
An alternative to using the `cout` stream to print to standard out is to use the `printf()` function. The basic syntax is below: 
```
printf("string with wildcards or specifiers (%)", variables or values you want to be subsituted into the wild cards); 
```

Examples:
```
printf("Hello %s", "World!");
// Output: Hello World! 
printf("$i + $i = $i", 1, 1, 2);
// Output: 1 + 1 = 2
printf("There are %i %s students in this class", 190, "great"); 
// Output: There are 190 great students in this class
```
Full list of wildcards/specifiers: https://www.cplusplus.com/reference/cstdio/printf/

## Streams

### cin/cout
We have already used these quite a bit to send output to standard out and read user input from standard in (terminal). 

Basic syntax
```
cout << "Hello\n"; 
int i; 
cin >> i; 
```
Remember that `>>` is the stream extraction operator (`operator>>()`) and `<<` is the stream insertion operator (`operator<<()`). These are functions that can be overloaded to work in any object, they are not unique to cin/cout. We will use them again with file streams. 

### `getline()` function
This is a very useful function. We will use it a lot with file I/O. In its most basic form, it takes in a stream and a string and extracts a string out of the stream and stores it in the stream (try saying that 3 times fast). 

After running this code, what ever string the user enters will be stored in line. This works because the second argument is call-by-reference so the `getline()` function has direct access to the `line` variable passed in. 
```
string line; 
getline(cin, line);
```
Get line has other overloadings that we will see below. More info: https://www.cplusplus.com/reference/string/string/getline/

### stringstreams 
You can turn a string into a stream. This can be very useful if you want to parse through tokens within a string (say if you wanted to read CSV and parse out each value between the commas). To do this, you will use the stringstream. 

Example: 
```
#include <sstream> 

string line = "10,11"; 
std::stringstream sline(line); // create a stream out of line
string token; 
getline(sline, token, ',');
cout << token << "\n"; 
  
//Output: 10 

```

## File I/O
Many times you will be interacting with files to get data to use within your program. Below outlines the basic syntax for reading and writing to files. 
### Reading from files
The following example will attempt to open a file named "data.txt" and read each line and print the line back. 
```
#include <fstream>
std::ifstream in("data.txt");
if (in.is_open()) {
   string line;
   while (getline(in, line)) {
      cout << line << "\n";
   }
   in.close();
} else {
   cout << "File does not exist or did not open\n";
}
```

Breaking down the components: 

The following line will open a connection to the "data.txt" file. Note that the path of "data.txt" denotes that the file is in the same directory as the cpp file. If this is not the case then the full path will need to be given. For example, if "data.txt" was in a folder called "data" then you would change the path to "./data/data.txt". 
```
std::ifstream in("data.txt"); 
```

We must always check to make sure that the file was indeed opened. C++ will not complain if the file does not exist! `is_open()` will return true if the file was found and was opened. 
```
if (in.is_open()) {
   ...
} else {
   cout << "File does not exist or did not open\n";
}
```
The following reads in each of the lines using the `getline()` function. The `line` variable is updated each time through the loop and the value is outputted via `cout`. 
```
string line;
while (getline(in, line)) {
   cout << line << "\n";
}
```
We always need to close our files: 
```
in.close();
```

### Writing to files
You can open files in one of two ways: 
1. to overwrite the file with new values
2. to append to the end of the file (keeping the old data)

To overwrite: 
```
std::ofstream out("data.txt");
```
To append: 
```
std::ofstream out("data.txt", std::ofstream::app);
```

Data is then outputted to the file using the stream insertion operator ('<<'). 
```
out << "Line 4\n"; 
```

Don't forget to close your file! 
```
out.close(); 
```
