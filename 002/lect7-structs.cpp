// Copyright 2021 Casey A Cole
#include <iostream>
#include <string>
#include <sstream>

using std::string;

// Basically an object with no functions and
// everything is public.
struct book {
    string title = "NULL";
    string author;
    float price;
    int pages;
};

//  print(b2);
void print(book);

// initCollection(collection, size);
void initCollection(book[], int);

// lib = addBook(lib, size);
book* addBook(book*, book, int&);
// addBook(lib,size);
// void addBook(book*&, int);
// TODO(class): add initBook function to get in the data from the user.

// TODO(class): add printCollection function.

// TODO(class): add addBook function that will add a new book to the
// collection.

// TODO(on your own): add a removeBook function that will search for
// a title and remove that from the collection of structs.

int main(int argc, char **argv) {
    // Creating a new book (struct)
    book b1;
    b1.author = "author";
    // Using curly braces: = {val1, val2};
    book b2 = {"title", "author", 9.99, 100};
    // What is the size of this struct?
    // Manual initialization of each property

    // Create the printBook function.
    // print(b2);
    // Static allocation of book collection
    book collection[4];
    // Create a initCollection() function
    int size = 4;
    // initCollection(collection, size);
    // // Create printCollection() function
    // for (int i = 0; i < 4; i++) {
    //     print(collection[i]);
    // }
    // Dynamic allocation of book collection with pointers
    book *lib;
    lib = new book[0];
    // addBook() function
    size = 0;
    lib = addBook(lib, b2, size);
    for (int i = 0; i < size; i++) {
        print(lib[i]);
    }
    // addBook(lib,size);

    return 0;
}

book* addBook(book* lib, book b, int & size) {
    book *ret = new book[size+1];
    for (int i = 0; i < size; i++) {
        ret[i].title = lib[i].title;
    }
    ret[size].title = b.title;
    delete [] lib;
    size++;
    return ret;
}

void print(book b) {
    printf("Title: %s\n", b.title.c_str());
    printf("Author: %s\n", b.author.c_str());
    printf("Price: %.2f\n", b.price);
    printf("Pages: %i\n", b.pages);
}
void initCollection(book col[], int size) {
    string line, token;
    for (int i = 0; i < size; i++) {
        getline(std::cin, line);
        //stringstream
        // for (int j -> COL)
        //      getline(...',')
        //       data[i][j] = token
        std::stringstream ss(line);
        getline(ss, token, ',');
        col[i].title = token;
        getline(ss, token, ',');
        col[i].author = token;
        getline(ss, token, ',');
        col[i].price = stof(token);
        getline(ss, token, ',');
        col[i].pages = stoi(token);
    }
}