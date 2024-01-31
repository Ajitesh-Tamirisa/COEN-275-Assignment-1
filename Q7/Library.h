#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
using namespace std;

class LibraryBook{
    private:
        string title;
        string author;
        bool available;
    
    public:
        LibraryBook(){
            title = "";
            author = "";
            available = false;
        };
        //parameterized constructor
        LibraryBook(string title, string author) : title(title), author(author), available(true) {}
        void borrowBook(){
            if(available){
                available = false;
                cout<<"\n>>>>>>>>>>>>>>Borrowing a book>>>>>>>>>>>>>>"<<endl;
                cout<<"Thank you for borrowing '"<<title<<"' by "<<author<<"!\nPlease return it on time."<<endl;
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"<<endl;
            }
            else{
                cout<<"\n>>>>>>>>>>>>>>Borrowing a book>>>>>>>>>>>>>>"<<endl;
                cout<<"'"<<title<<"' by "<<author<<" is currently not available"<<endl;
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"<<endl;
            }
        }
        void returnBook(){
            if (!available) {
                available = true;
                cout<<"Thank you for returning '"<<title<<"' by "<<author<<"!"<<endl;
            } else {
                cout << "The book is already available. Cannot return twice." <<endl;
            }
        }
        bool operator == (const LibraryBook& otherBook) const {
            if (title == otherBook.title && author == otherBook.author) 
                return true; 
            return false; 
        }

        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        bool isAvailable(){
            return available;
        }
};

class Library{
    private:
        vector<LibraryBook> libraryBooks;
    public:
        Library(){
            libraryBooks.push_back(LibraryBook());
        }
        //add a new book to the Library
        void addNewBook(string bookTitle, string bookAuthor){
            LibraryBook book(bookTitle, bookAuthor);
            libraryBooks.push_back(book);
        }

        //display list of books
        void displayBooks(){
            cout<<"\n*******List of available books*******"<<endl;
            for(LibraryBook book: libraryBooks){
                if(book.isAvailable())
                    cout <<"'"<<book.getTitle()<<"' by "<<book.getAuthor()<< endl;
            }
        }

        //search book by author
        LibraryBook& searchBook(const string& title, const string& author){
            
            cout<<"\n??????????????Searching a book??????????????"<<endl;
            for(LibraryBook& book: libraryBooks){
                if(book == LibraryBook(title, author))
                    return book;
            }
            cout<<"'"<<title<<"' by "<<author<<" is currently not available"<<endl;
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            return libraryBooks[0];
        }

        void removeBook(string title, string author){
            LibraryBook searchBook(title, author);
            vector<LibraryBook>::iterator it;
            int count = 0; bool flag = false;
            for(LibraryBook book: libraryBooks){
                if(book == searchBook){
                    it = libraryBooks.begin()+count;
                    libraryBooks.erase(it);
                    flag = true;
                    cout<<"\n'"<<title<<"' by "<<author<<" has been removed from the Library."<<endl;
                }
                count++;
            }
            if(!flag)
                cout<<"No such book found."<<endl;
        }
};

#endif