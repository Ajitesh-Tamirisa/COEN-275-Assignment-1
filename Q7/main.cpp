#include "Library.h"
int main() {
    Library library;
    library.addNewBook("Hamlet", "William Shakespeare");
    library.addNewBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addNewBook("The Adventures of Huckleberry Finn", "Mark Twain");

    library.displayBooks();

    LibraryBook& foundBook = library.searchBook("The Catcher in the Rye", "J.D. Salinger");
    if (foundBook.isAvailable()) {
        foundBook.borrowBook();
    }

    LibraryBook& foundBook1 = library.searchBook("Hamlet", "William Shakespeare");
    if (foundBook1.isAvailable()) {
        foundBook1.borrowBook();
    }
    library.displayBooks();


    library.removeBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.displayBooks();

    return 0;
}
