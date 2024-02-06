#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template<class F>
class Node
{
public:
    F data;
    Node*next;
    Node*prev;
    Node()
    {
        next=nullptr;
        prev=nullptr;
    }
    virtual ~Node()
    {

    }

protected:

private:
};

#endif // NODE_H
