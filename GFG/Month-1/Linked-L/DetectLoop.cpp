#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    public:
    Node* head;
    Node* tail;


    List() {
        head = NULL;
        tail = NULL;
    }

    // Push a value at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
   
   void Loop()
   {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast->data==slow->data)
        {
            cout<<"Loop exists"<<endl;
            return;
        }
    }
    cout<<"Loop does not exists"<<endl;
   }

    // Print the entire list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};




int main() {
    List ll;
    ll.push_back(5);
    ll.push_back(2);
    ll.push_back(8);
    ll.push_back(6);

    cout << "Original list:\n";
   
    ll.tail->next=ll.head;
    ll.Loop();
     

   
    return 0;
}
 