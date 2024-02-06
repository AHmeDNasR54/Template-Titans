#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string ISBN;
    string genre;
public:
    bool status=true;

    //enum status={Available=1,borrowed,bought};
    Book();
    Book(string title,string author,string ISBN,string genre);
    void set_data();
    string getTitle();
    string getAuthor();
    string getISBN();
    string getGenre();
    friend ostream&operator <<(ostream&output,Book&B)
    {
        output<<"Title: "<< B.getTitle()
              <<endl<<"Author: "<<B.getAuthor()
              <<endl<<"ISBN: "<<B.getISBN()
              <<endl<<"Genre: "<<B.getGenre()
              <<endl<<"Status: " << (B.status ? "Available" : "Borrowed") << "\n";
        return output;

    }
        bool operator ==(Book b)
    {
        return(title==b.getTitle()&&author==b.getAuthor()&&ISBN==b.getISBN()&&genre==b.getGenre());
    }
     Book &operator =(Book &b)
{
     title=b.getTitle();
     author=b.getAuthor();
     ISBN=b.getISBN();
     genre=b.getGenre();
    return *this;
}

    virtual ~Book();

protected:


};

#endif // BOOK_H
