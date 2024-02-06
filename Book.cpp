#include "Book.h"

Book::Book()
{
    //ctor
}

Book::~Book()
{
    //dtor
}
Book::Book(string title,string author,string ISBN,string genre)
{
    this->title=title;
    this->author=author;
    this->ISBN=ISBN;
    this->genre=genre;
}
void Book::set_data()
{
    cout<<"Title: ";cin>>title;
    cout<<"Author: ";cin>>author;
    cout<<"ISBN: ";cin>>ISBN;
    cout<<"Genre: ";cin>>genre;

}
string Book::getTitle()
{
    return title;
}
string Book::getAuthor()
{
    return author;
}
string Book::getISBN()
{
    return ISBN;
}
string Book::getGenre()
{
    return genre;
}
