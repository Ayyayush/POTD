#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
     public:
Node* next;
int data;
Node(int val)
{
data =val;
next= NULL;
}
};
class List
{
    public:
    Node* head;
    Node* tail;

    List()
    {
        head=NULL;
        tail=NULL;


    }
       void push_back(int val)
    {
        Node* newNode= new Node(val);

        if(head==NULL)
        {
        head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
          
            
        }

    }
      

void middleNode()
{
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)    // O(N)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    cout<<slow->data<<endl;
}


void split()
{
    Node* start=head;
    int k,count=1;
    cin>>k;
    while(start!=NULL && count<=k)
    {
        cout<<start->data<<"->";
        start=start->next;
        count++;
    }
    while(count<k)
    {
        cout<<" "<<"->";
    }

}

    void printlist()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
              temp = temp->next;
        }
        cout << "NULL\n";
    
        
    }

};
int main()
{
List ll;
ll.push_back(5);
ll.push_back(8);
ll.push_back(15);
ll.push_back(20);
ll.push_back(32);


ll.printlist();
ll.split();
ll.printlist();

}