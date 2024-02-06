#include "Container.h"
/*template <class T>
Container<T>::Container()
{
    first =nullptr;
}
template <class T>
Container<T>::~Container()
{
    //dtor
}
template <class T>
void Container<T>::insertBegin(T value)
{
    Node <T>*t;
    if(first)
    {
       t=new Node<T>;
        t->data=value;
        first->prev=t;
        t->next=first;
        t->prev=nullptr;
        first=t;

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
template <class T>
void Container<T>::insertLast(T value)
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
template <class T>
int Container<T>::Length()
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

template <class T>
void Container<T>::insertInGivenPosition(int position,T value)
{
   if(position<0||position>Length())
        {
            cout<<"Invalid index\n";
            return;
        }
        Node<T>*p;Node<T>*q;Node<T>*t;
        p=first;
        t=new Node<T>;
        t->data=value;
        t->next=nullptr;
        t->prev=nullptr;


        for(int i=1;i<=position;i++)
        {
            q=p;
            p=p->next;
        }

        t->next=p;
        p->prev=t;
        q->next=t;
        t->prev=q;

    }

/*template <class T>
void Container<T>::Insert(int position,T value)
{

}
template <class T>
T Container<T>::removByGivenValue(T value)
{
       Node<T>*p=first;
    if(!p)
    {
        cout<<"The container is empty\n";
        return 0;
    }
    else
    {
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
                T x=p->data;
                delete p;
                return x;
            }
            p=p->next;
        }

    }
            cout<<"invalid data\n";
              return 0;
}
template <class T>
T Container<T>::removByGivenPosition(int position)
{
     T x;
    Node<T>*p=first;
                if(position<1||position>Length())
        {
            cout<<"Invalid position\n";
            return 0;
        }
        if(position==1)
        {
            x=p->data;
            first=first->next;
            if(first)// check that the linked won't become empty
            first->prev=nullptr;
            delete p;
        }
        else{
        for(int i=1;i<position;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;
        x=p->data;
        delete p;
        return x;
    }

}
template <class T>
int Container<T>::findElemnt(T value)
{
       Node<T>*p=first;
       for(int i=1;i<=Length();i++)
       {
           if(p->data==value)
           return i;
           p=p->next;
       }
       cout<<"invalid data\n";
}
template <class T>
Node<T>* Container<T>::findNode(T value)
{
           Node<T>*p=first;
       for(int i=1;i<=Length();i++)
       {
           if(p->data==value)
           return p;
           p=p->next;
       }
       cout<<"invalid data\n";
}
template <class T>
void Container<T>::Swap(Node<T>*p,Node<T>*q)
     {
         Node<T>*temp;
         temp=p;
         p=q;
         q=temp;
     }
template <class T>
void Container<T>::Sort()
{
 // T arr[Length()];
      Node<T>*p=first;
        // Node<T>*hashTable[Length()];
      /*int i=0,counter=0;
      while(p)
      {
          arr[i]=p->data;
          p=p->next;
          i++;
      }
      Node<T>*hashTable[Length()];
       for(int i=0;i<Length();i++)
       {

           T temp=arr[i];
           //if(temp==arr[])
           for(int x=i+1;x<Length();x++)
           {
               if(arr[i]<arr[x])
                temp=arr[i];
                else temp=arr[x];
           }
           for(Node<T>*p=first;p;p=p->next)
       {

           Node<T>*q=p;
           for(Node<T>*temp=p;temp;temp=temp->next)
               if(q->data>temp->data)
                q=temp;
           Swap(q,p);
           //hashTable[counter++]=findNode(temp);

       }


}
template <class T>
void Container<T>::Reverse()
{
    Node<T>*p=first;
    Node<T>*temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;// to move to next node
        if(p->next==nullptr&&p!=nullptr)// to make sure that p is last node in the old linked list
            first =p;// make last node is the first node in the reverse linked list

    }


}
template <class T>
void Container<T>::Merge(Container<T> *con)
{
   Node<T>*p=first;
   while(p->next)
    p=p->next;
   p->next=con->first;
   con->first->prev=p;
}
template <class T>
void Container<T>::display()
{
       Node<T>*p=first;
   while(p)
   {
       cout<<p->data<<" ";
       p=p->next;
   }
   cout<<endl;

}
/*template class Container<int>;
template class Container<string>;
template class Container<float>;
template class Container<double>;
template class Container<char>;*/

