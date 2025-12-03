#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    // Push a value at the end of the list
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Loop()
    {
        Node *slow = head; // Slow pointer ko head se initialize kiya......
        Node *fast = head; // Fast pointer ko bhi head se initialize kiya......

        while (fast != NULL && fast->next != NULL)
        {                            // Jab tak fast pointer NULL nahi hota ya end tak nahi pahuncha......
            slow = slow->next;       // Slow pointer ek node aage badhta hai......
            fast = fast->next->next; // Fast pointer do nodes aage badhta hai......

            if (slow == fast)
            {                                   // Slow aur fast mil gaye, loop detect ho gaya......
                First_Node_of_Loop(); // Loop ka starting node find karne ke liye function call kiya......
                return;
            }
        }

        cout << "Loop does not exist" << endl; // Agar loop nahi milta toh yeh message print hota hai......
    }




    void First_Node_of_Loop()
    {
        Node *slow = head;         // Slow pointer wapas head pe......
        Node *fast = head; // Fast pointer ko intersection point pe set kiya......
        Node *prev = NULL;         // Loop break karne ke liye previous node track karenge......

        if (slow == fast)
        { // Special case: Agar loop head se hi shuru hota hai......
            while (fast->next != slow)
            {                      // Jab tak fast ka next slow ke barabar nahi hota......
                fast = fast->next; // Fast pointer ko move karte raho......
            }
            fast->next = NULL; // Loop break kar diya......
            cout << "Starting node of the loop is: " << slow->data << endl;
            return;
        }

        while (slow != fast)
        {                      // Jab tak slow aur fast equal nahi hote......
            prev = fast;       // Previous node track karte hain......
            slow = slow->next; // Slow ek step aage badhta hai......
            fast = fast->next; // Fast ek step aage badhta hai......
        }

        cout << "Starting node of the loop is: " << slow->data << endl; // Starting node print karte hain......
        prev->next = NULL;                                              // Loop break karne ke liye previous node ka next NULL kar diya......
    }



    // Print the entire list
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    List ll;
    ll.push_back(5);
    ll.push_back(2);
    ll.push_back(8);
    ll.push_back(6);

    cout << "Original list:\n";

    ll.tail->next = ll.head;
    ll.Loop();

    return 0;
}
