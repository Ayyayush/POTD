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
    Node* head;
    Node* tail;

public:
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



   void swap()
   {
        if (head == NULL)
         return NULL;
         int k;
         cin>>k;

        // Step 1: Find the size of the list
        Node* temp = head;
        int sz = 0;
        while (temp != NULL) {
            temp = temp->next;
            sz++;
        }

        // Step 2: Find the k-th node from the beginning
        Node* temp1 = head;
        for (int i = 1; i < k; i++) {
            temp1 = temp1->next;
        }

        // Step 3: Find the k-th node from the end
        Node* temp2 = head;
        for (int i = 1; i < (sz - k + 1); i++) {
            temp2 = temp2->next;
        }

        // Step 4: Swap the values of temp1 and temp2 (not the pointers)
        if (temp1 != temp2) {
            swap(temp1->val, temp2->val);  // Swap node values
        }

        return head;
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



 

void better()
 {
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    // Traversing the list and printing the elements
    for (auto x : ll) {
        cout << x << " --> ";  // Directly print the value
    }
    cout << "NULL" << endl;



 auto temp1 = ll.begin();  // Points to the first element
    auto temp2 = prev(ll.end());  // Points to the last element


int n;
cin>>n;
for(int i=1;i<=n;i++)
{
    temp1++;
    temp2--;
}
swap(*temp1,*temp2);

 // Traversing the list and printing the elements
    for (auto x : ll) {
        cout << x << " --> ";  // Directly print the value
    }
    cout << "NULL" << endl;

   
    return 0;
}


int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
     ll.push_back(5);
    

    cout << "Original list:\n";
    ll.printList();
    ll.removeNth(2);
     ll.printList();


   
    return 0;
}
