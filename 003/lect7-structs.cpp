// Copyright 2021 Casey A Cole
#include <iostream>
#include <string>

using std::string;

// Basically an object with no functions and everything is public.
struct book {
    string title;
    string author;
    float price;
    int words;
    string genre;
};

// printBook
void printBook(book);
// initBook(b1);
void initBook(book&);

// addBook(collection2, b2, size)
book* addBook(const book*, book, int&);
// TODO(class): add initBook function to get in the data from the user.

// TODO(class): add printCollection function.

// TODO(class): add addBook function that will add a new book to the
// collection.

// TODO(on your own): add a removeBook function that will search for
// a title and remove that from the collection of structs.
// remove last book
// book* removeBook(book*, int& size);
// remove at given index
book* removeBook(book*, int index, int& size);
// collection2 = deleteBook(collection2, 0, size);

using std::cout;
int main(int argc, char **argv) {
    // Creating a new book (struct)
    book b1;
    // What is the size of this struct?
    // cout << sizeof(b1) << "\n";
    // Manual initialization of each property
    b1.words = 100;
    // cout << b1.words << "\n";
    book b2 = {"title", "author", 10.99, 10000, "fiction"};
    // cout << b2.title << "\n";
    // printBook(b2);
    // Create the initBook function.
    // initBook(b1);
    // printBook(b1);
    // Static allocation of book collection
    book collection[3];
    // Create printCollection() function
    // for (int i = 0; i < 3; i++) {
    //     // collection[i].author;
    // }
    // Dynamic allocation of book collection with pointers
    book *collection2;
    collection2 = new book[0];
    // addBook() function
    int size = 0;
    collection2 = addBook(collection2, b2, size);
    cout << "Size of collection: " << size << "\n";
    for (int i =0; i < size; i++) {
        printBook(collection2[i]);
    }
    // collection2 = addBook(collection2, b2, size);
    // collection2 = addBook(collection2, b2, size);
    collection2 = removeBook(collection2, 0, size);
    cout << "Size of collection: " << size << "\n";
    for (int i =0; i < size; i++) {
        printBook(collection2[i]);
    }
    delete [] collection2;
    return 0;
}

void printBook(book b) {
    printf("Title: %s\n", b.title.c_str());
    printf("Author: %s\n", b.author.c_str());
    printf("Price: %f\n", b.price);
    printf("Words: %i\n", b.words);
    printf("Genre: %s\n", b.genre.c_str());
}
void initBook(book& b) {
    getline(std::cin, b.title, ',');
    getline(std::cin, b.author, ',' );
    string token;
    getline(std::cin, token, ',' );
    b.price = stof(token);
    getline(std::cin, token, ',' );
    b.words = stoi(token);
    getline(std::cin, b.genre, ',' );
    // std::cin >
}

book* addBook(const book* col, book b, int& size) {
    book * ret = new book[size+1];
    for (int i = 0; i < size; i++) {
        // ret[i] = col[i];
        ret[i].title = col[i].title;
    }
    delete [] col;
    ret[size].title = b.title;
    size++;
    return ret;
}

book* removeBook(book* col, int index, int& size) {
    book * ret = new book[size-1];
    for (int i = 0; i < size; i++) {
        if (i < index) {
            ret[i].title = col[i].title;
        } else if (i > index) {
            ret[i-1].title = col[i].title;
        }
    }
    delete [] col;
    size--;
    return ret;
}