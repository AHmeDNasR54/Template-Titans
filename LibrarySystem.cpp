#include "LibrarySystem.h"

LibrarySystem::LibrarySystem()
{
    //ctor
}

LibrarySystem::~LibrarySystem()
{
    //dtor
}
void LibrarySystem::addBook()
{
    Book b;
    b.set_data();
            cout << "===========================================\n";
            cout << "           Add Information Management   \n";
            cout << "===========================================\n";
            cout << "1. In front of the list\n";
            cout << "2. At end of the list\n";
            cout << "3. In a given position\n";
            cout << "===========================================\n";
            cout << "Please enter your choice (1-3): ";
            int choice3;
            cin >> choice3;
            switch(choice3)
            {
            case 1:
        con.insertBegin(b);
        break;
    case 2:
        con.insertLast(b);
        break;
    case 3:
        cout<<"Enter position: ";int pos;cin>>pos;
        con.insertInGivenPosition(pos,b);
        break;
    default :
        cout<<"Invalid index\n";
    }
}
void LibrarySystem::display()
{
    con.display();
}
void LibrarySystem::sortTitle()
{
   for(Node<Book>*p=con.first; p; p=p->next)
        {

            Node<Book>*q=p;
            for(Node<Book>*temp=p; temp; temp=temp->next)
                if(q->data.getTitle()>temp->data.getTitle())
                    q=temp;
            con.Swap(q,p);
        }
   }
void LibrarySystem::sortAuthor()
{
   for(Node<Book>*p=con.first; p; p=p->next)
        {

            Node<Book>*q=p;
            for(Node<Book>*temp=p; temp; temp=temp->next)
                if(q->data.getAuthor()>temp->data.getAuthor())
                    q=temp;
            con.Swap(q,p);
        }
}
void LibrarySystem::sortISBN()
{
   for(Node<Book>*p=con.first; p; p=p->next)
        {

            Node<Book>*q=p;
            for(Node<Book>*temp=p; temp; temp=temp->next)
                if(q->data.getISBN()>temp->data.getISBN())
                    q=temp;
            con.Swap(q,p);
        }
}
void LibrarySystem::sortGenre()
{
   for(Node<Book>*p=con.first; p; p=p->next)
        {

            Node<Book>*q=p;
            for(Node<Book>*temp=p; temp; temp=temp->next)
                if(q->data.getGenre()>temp->data.getGenre())
                    q=temp;
            con.Swap(q,p);
        }
}
void LibrarySystem::Sort()
{
            cout << "===========================================\n";
            cout << "           Sort Information Management   \n";
            cout << "===========================================\n";
            cout << "1. Sort By Title\n";
            cout << "2. Sort By Author\n";
            cout << "3. Sort By ISBN\n";
            cout << "4. Sort By Genre\n";
            cout << "===========================================\n";
            cout << "Please enter your choice (1-4): ";
            int choice3;
            cin >> choice3;
            switch(choice3)
            {
            case 1:
        sortTitle();
        break;
    case 2:
        sortAuthor();
        break;
    case 3:
        sortISBN();
        break;
    case 4:
        sortGenre();
        break;
    default :
        cout<<"Invalid data\n";

    }
}
Book* LibrarySystem::searchByTitle()
{
        cout<<"Enter title: ";string title;cin>>title;
        Node<Book>*p=con.first;
        for(int i=1;i<=con.Length();i++)
        {
            if(p->data.getTitle()==title)
                return &p->data;
            p=p->next;
        }
        cout<<"Invalid data\n";
        return nullptr;

}
Book* LibrarySystem::searchByAuthor()
{
           cout<<"Enter Author: ";string Author;cin>>Author;
        Node<Book>*p=con.first;
        for(int i=1;i<=con.Length();i++)
        {
            if(p->data.getAuthor()==Author)
                return &p->data;
            p=p->next;
        }
        cout<<"Invalid data\n";
        return nullptr;
}
Book* LibrarySystem::searchByISBN()
{
           cout<<"Enter ISBN: ";string ISBN;cin>>ISBN;
        Node<Book>*p=con.first;
        for(int i=1;i<=con.Length();i++)
        {
            if(p->data.getISBN()==ISBN)
                return &p->data;
            p=p->next;
        }
        cout<<"Invalid data\n";
        return nullptr;
}
Book* LibrarySystem::searchByGenre()
{
            cout<<"Enter Genre: ";string Genre;cin>>Genre;
        Node<Book>*p=con.first;
        for(int i=1;i<=con.Length();i++)
        {
            if(p->data.getGenre()==Genre)
                return &p->data;
            p=p->next;
        }
        cout<<"Invalid data\n";
        return nullptr;

}
void LibrarySystem::Search()
{
            cout << "===========================================\n";
            cout << "           Search Information Management   \n";
            cout << "===========================================\n";
            cout << "1. Search By Title\n";
            cout << "2. Search By Author\n";
            cout << "3. Search By ISBN\n";
            cout << "4. Search By Genre\n";
            cout << "===========================================\n";
            cout << "Please enter your choice (1-4): ";
            int choice3;
            cin >> choice3;
            switch(choice3)
            {
            case 1:
                {

                Book*b=searchByTitle();
                if(b!=nullptr)
                 cout<<*b<<endl;
                }
                break;
            case 2:
                {
                Book*b=searchByAuthor();
                if(b!=nullptr)
                 cout<<*b<<endl;
                }
                break;
            case 3:
                {
               Book*b= searchByISBN();
                if(b!=nullptr)
                    cout<<*b<<endl;
                }
                break;
            case 4:
                {
               Book*b= searchByGenre();
                if(b!=nullptr)
                    cout<<*b<<endl;
                }
                break;
            default :
                 cout<<"Invalid index\n";
            }

}
void LibrarySystem::removeBook()
{

            cout << "===========================================\n";
            cout << "           Remove Information Management   \n";
            cout << "===========================================\n";
            cout << "1. Remove By Position\n";
            cout << "2. Remove By Book's Title\n";
            cout << "===========================================\n";
            cout << "Please enter your choice (1-2): ";
            int choice3;
            cin >> choice3;
            switch(choice3)
            {
            case 1:
        cout<<"Enter position: ";int pos;cin>>pos;
        con.removByGivenPosition(pos);
           break;
    case 2:
        Book b=*searchByTitle();
        con.removByGivenValue(b);
        break;
    }
}
void LibrarySystem::borrowBook()
{
            cout << "===========================================\n";
            cout << "           Borrow Information Management   \n";
            cout << "===========================================\n";
            cout<<  " DO you want to specific book or show you available books?\n";
            cout << "1. Specific Book\n";
            cout << "2. Show available books\n";
            cout << "===========================================\n";
            cout << "Please enter your choice (1-2): ";
            int choice3;
            cin >> choice3;
            switch(choice3)
            {
            case 1:
                {
                int t=1;
                  while(t){
                Book b=*searchByTitle();
                if(b.status){
                cout<<b<<endl;
                cout<<"Is this the book you want to borrow? (y/n)?\n";
                char answer;cin>>answer;
                if(answer=='y'||answer=='Y')
                {
                    cout<<"Here you are..\n";
                    Node<Book>*p=con.first;
                    for(int i=1;p;i++)
                    {
                        if(p->data==b)
                        {
                            p->data.status=false;
                            break;
                        }
                        p=p->next;

                    }
                    t=0;
                }
                }
                else {
                    cout<<"Sorry this Book isn't available ):\n";
                    cout<<"Do you want to choose another book? y\n ?\n";
                    char ans;cin>>ans;
                    if(ans=='y'||ans=='Y')
                        t=1;
                    else t=0;
                }

               }
                }
            break;
            case 2:
            Node<Book>*p=con.first;
            int istheranybook=0;
            while(p)
            {
                if(p->data.status)
                {
                    istheranybook=1;
                    cout<<p->data<<endl;
                }
                    if(p->next)
                cout<<"*******\n";
                p=p->next;

            }
            if(istheranybook==1){
            cout<<"Now choose you want\n";
            int t=1;
                while(t){
                Book b=*searchByTitle();
                cout<<b<<endl;
                cout<<"Is this the book you want to borrow? (y/n)?\n";
                char answer;cin>>answer;
                if(answer=='y'||answer=='Y')
                {
                    cout<<"Here you are..\n";
                    Node<Book>*p=con.first;
                    for(int i=1;p;i++)
                    {
                        if(p->data==b)
                        {
                            p->data.status=false;
                            break;
                        }
                        p=p->next;

                    }
                    t=0;
                }

            }
            }
            else cout<<"Sorry there is no book is available\n";


}
}
void LibrarySystem::returnBorrowedBook()
{


    Book *b=searchByTitle();
                if(b!=nullptr){cout<<*b<<endl;
                cout<<"OK,correct details\n\n";
                cout<<"What's your review from 1 to 10 about this book: ";int rev;cin>>rev;
                cout<<"thank you, We hope to see you again in our library\n";
               Node<Book>*p=con.first;
                    for(int i=1;p;i++)
                    {
                        if(p->data==*b)
                        {
                            p->data.status=true;
                            break;
                        }
                        p=p->next;

                    }
                }

}

int LibrarySystem::totalAvalaibleBooks()
{
    int count=0;
    Node<Book>*p=con.first;
    for(int i=1;i<=con.Length();i++)
    {
        if(p->data.status)
            count++;
        p=p->next;
    }
    return count;
}
int LibrarySystem::totalBorrowedBooks()
{
        int count=0;
    Node<Book>*p=con.first;
    for(int i=1;i<=con.Length();i++)
    {
        if(!p->data.status)
            count++;
        p=p->next;
    }
    return count;
}
int LibrarySystem::totalBooks()
{
    return con.Length();// return totalBorrowedBooks()+totalAvalaibleBooks();

}
void LibrarySystem::statistics()
{
            cout << "===========================================\n";
            cout << "        statistics Information Management   \n";
            cout << "===========================================\n";
            cout << "1. Total Number Of Available Books\n";
            cout << "2. Total Number Of Borrowed Books\n";
            cout << "3. Total Number Of  Books\n";
            cout << "===========================================\n";
            cout << "Please enter your choice (1-2): ";
            int choice3;
            cin >> choice3;
            switch(choice3)
            {
            case 1:
                cout<<"Total Number Of Available Books: "<<totalAvalaibleBooks()<<endl;
                break;
            case 2:
                cout<<"Total Number Of Borrowed Books: "<<totalBorrowedBooks()<<endl;
                break;
            case 3:
                cout<<"Total Number Of  Books: "<<totalBooks()<<endl;
                break;
            default:
                cout<<"Invalid data\n";
            }
}


