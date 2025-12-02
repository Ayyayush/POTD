#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    int data;

    Node(int val)
    {
        next = NULL;
        data = val;
    }
};

class List
{
public:
    Node *head;
    List()
    {
        head = NULL;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            newNode->next=NULL;
            head=newNode;
        }

    }

    void findLoop()
    {
        Node* fast=head;
        Node* slow=head;

        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }


    }

} ;
int main()
{
}