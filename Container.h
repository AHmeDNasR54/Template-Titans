#ifndef CONTAINER_H
#define CONTAINER_H
#include"Node.h"
#include<iostream>
using namespace std;
template<class T>
class Container
{
public:
    Node<T>*first;
public:
    Container()
    {
          first =nullptr;
    }
    Container(T A[],int n)
    {
        Node<T>*p;
        Node<T>*last;
        first=new Node<T>;
        first->data=A[0];
        first->next=NULL;
        last=first;
        for(int i=1; i<n; i++)
        {
            p=new Node<T>;
            p->data=A[i];
            p->next=NULL;
            last->next=p;
            last=p;
        }
    }
    void insertBegin(T value)
    {
        Node <T>*t;
        if(first)
        {
            t=new Node<T>;
            t->data=value;
            first->prev=t;
            t->next=first;
            // t->prev=nullptr;
            first=t;

        }
        else
        {
            t=new Node<T>;
            t->data=value;
            // t->next=nullptr;
            //t->prev=nullptr;
            first=t;
        }

    }
    void insertLast(T value)
    {
        Node <T>*t;
        if(first)
        {
            Node<T>*p;
            p=first;
            while(p->next)
                p=p->next;
            t=new Node<T>;
            t->data=value;
            p->next=t;
            t->next=nullptr;
            t->prev=p;

        }
        else
        {
            t=new Node<T>;
            t->data=value;
            t->next=nullptr;
            t->prev=nullptr;
            first=t;
        }
    }
    int Length()
    {
        Node<T>*p=first;
        int count=0;
        while(p)
        {
            count++;
            p=p->next;

        }
        return count;
    }
    void insertInGivenPosition(int position,T value)
    {
        if(position==1)
        {
            insertBegin(value);
            return;
        }
        else if(position==Length()+1)
        {
            insertLast(value);
            return;
        }
        else
        {
            if(position<2||position>Length())
            {
                cout<<"Invalid index\n";
                return;
            }
            Node<T>*p;
            Node<T>*q;
            Node<T>*t;
            p=first;
            t=new Node<T>;
            t->data=value;
            t->next=nullptr;
            t->prev=nullptr;


            for(int i=2; i<=position; i++)
            {
                q=p;
                p=p->next;
            }

            t->next=p;
            if(p)// very important condition . kan bedeny error(lma b add after last node) melaffny wra 3eny hahahahah
                p->prev=t;
            q->next=t;
            t->prev=q;

        }
    }
    // void Insert(int position,T value);

    T removByGivenValue(T value)
    {
        Node<T>*p=first;
        T x;
        if(!p)
        {
            cout<<"The container is empty\n";
            //return 0;
        }
        else
        {
            if(p->data==value)// first node
            {
                if(p->next)
                p->next->prev=nullptr;
                first=p->next;
                x=p->data;
                delete p;
                  cout<<"Deleted successfully (:\n";
                return x;

            }
            while(p)
            {
                if(p->data==value)
                {
                    if(p->next)//check that the node to be delete isn't last node
                    {
                        p->next->prev=p->prev;
                        p->prev->next=p->next;
                    }
                    else
                    {
                        p->prev->next=p->next;// =null
                    }
                    x=p->data;
                    delete p;
                      cout<<"Deleted successfully (:\n";
                    return x;
                }
                p=p->next;
            }

        }
        cout<<"invalid data\n";
        //return 0;

    }
    T removByGivenPosition(int position)
    {

        T x;
        Node<T>*p=first;
        if(position<1||position>Length())
        {
            cout<<"Invalid position\n";
            //return T;
        }
        else if(position==1)
        {
            x=p->data;
            first=first->next;
            if(first)// check that the linked won't become empty
                first->prev=nullptr;
            delete p;
            cout<<"Deleted successfully (:\n";
        }
        else
        {
            for(int i=1; i<position; i++)
            {
                p=p->next;
            }
            p->prev->next=p->next;
            if(p->next)
                p->next->prev=p->prev;
            x=p->data;
            delete p;
            return x;
              cout<<"Deleted successfully (:\n";
        }
    }
    int findElemnt(T value)
    {
        if(!first)
            return -1;
        Node<T>*p=first;
        for(int i=1; i<=Length(); i++)
        {
            if(p->data==value)
                return i;
            p=p->next;
        }
        cout<<"invalid data\n";
        return -1;
    }
    Node<T>* findNode(T value)
    {
        Node<T>*p=first;
        for(int i=1; i<=Length(); i++)
        {
            if(p->data==value)
                return p;
            p=p->next;
        }
        cout<<"invalid data\n";
    }
    Node<T>* findNodeByGivenPosition(int position)
    {
        if(position<1||position>Length())
        {
            cout<<"Invalid position\n";
            return nullptr;
        }
        Node<T>*p=first;
        for(int i=1; i<position; i++)
        {
            p=p->next;
        }
        return p;
    }
    void Swap(Node<T>*&p,Node<T>*&q)
    {
        T data=p->data;
        p->data=q->data;
        q->data=data;

    }
    void Sort()
    {
        Node<T>*p=first;
        for(Node<T>*p=first; p; p=p->next)
        {

            Node<T>*q=p;
            for(Node<T>*temp=p; temp; temp=temp->next)
                if(q->data>temp->data)
                    q=temp;
            Swap(q,p);

        }


    }
    void Reverse()
    {
        Node<T>*p=first;
        Node<T>*temp;
        while(p)
        {
            temp = p->prev;
            p->prev=p->next;
            p->next=temp;
            p=p->prev;// to move to next node
            if(p->next==nullptr&&p!=nullptr)// to make sure that p is last node in the old linked list
                first =p;// make last node is the first node in the reverse linked list

        }


    }
    void Merge(Container<T> *con)
    {
        Node<T>*p=first;
        while(p->next)
            p=p->next;
        p->next=con->first;
        con->first->prev=p;
    }
    void display()
    {
        Node<T>*p=first;
        if(!p)
            cout<<"There is no data to display\n";
        while(p)
        {
            cout<<p->data;
        if(p->next)
            cout<<"**********\n";
            p=p->next;
        }
        cout<<endl;
    }
    virtual ~Container()
    {

    }

protected:

};

#endif // CONTAINER_H



