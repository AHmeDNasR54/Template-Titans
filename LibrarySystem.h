#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include<iostream>
#include<string>
#include"Book.h"
#include"Container.h"
#include"Node.h"
using namespace std;
class LibrarySystem
{
private:
    Container<Book>con;
public:

    LibrarySystem();
    void addBook();// add in front /end/given position of the list
    void display();
    void sortTitle();
    void sortAuthor();
    void sortISBN();
    void sortGenre();
    void Sort();
    Book* searchByTitle();
    Book* searchByAuthor();
    Book* searchByISBN();
    Book* searchByGenre();
   void Search();
    void removeBook();
    void borrowBook();
    void returnBorrowedBook();
    int totalAvalaibleBooks();
    int totalBorrowedBooks();
    int totalBooks();
    void statistics();
    virtual ~LibrarySystem();

protected:


};

#endif // LIBRARYSYSTEM_H
