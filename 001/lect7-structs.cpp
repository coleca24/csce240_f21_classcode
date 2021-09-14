// Copyright 2021 Casey A Cole
#include <iostream>
#include <string>
#include <sstream>

using std::string;

// Basically an object with no functions and
// everything is public.
struct book {
    string title = "NULL";
    string author = "NULL";
    float price = 0.0;
    int pages = 0;
};

void print(book);

// initLibrary(library, size);
void initLibrary(book[], int);

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
    book b2 = {"title", "author", 1.2, 500};
    print(b2);
    // What is the size of this struct?

    // Manual initialization of each property

    // Create the initBook function.

    // Static allocation of book collection
    book library[4];
    int size = 4;
    initLibrary(library, size);
    // Create printCollection() function
    for (int i = 0; i < size; i++) {
        std::cout << i << "\n";
        print(library[i]);
    }
    // Dynamic allocation of book collection with pointers
    book * lib;
    lib = new book[0];
    // addBook() function
    book newBook;
    int numOfBooks;
    // addBook(lib, newBook, numOfBooks);
    return 0;
}

void print(book b) {
    printf("Title: %s\n", b.title.c_str());
    printf("Author: %s\n", b.author.c_str());
    printf("Price: %.2f\n", b.price);
    printf("Pages: %i\n", b.pages);
}

void initLibrary(book lib[], int size) {
    string line;
    int count = 0;
    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        // while (getline(ss, line, ',')) {
            
        // }
        for (int i = 0; i < size; i++) {
            getline(ss, line, ',');
            if (i == 0) lib[count].title = line;
            else if (i == 1) lib[count].author = line;
            else if (i == 2) lib[count].price = stof(line);
            else lib[count].pages = stoi(line);
        }
        count++;
    }
}
