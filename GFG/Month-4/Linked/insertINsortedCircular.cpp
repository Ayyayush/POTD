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
    Node *head;

public:
    List()
    {
        head = NULL;
    }

    // Insert value in sorted order in circular list
    void push_sorted(int val)
    {
        Node *newNode = new Node(val);

        // Case 1: List is empty
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *curr = head;
        Node *prev = NULL;

        // Case 2: Inserting before head (new smallest element)
        if (val < head->data)
        {
            // Find tail to link back to new head
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }

        // Case 3: Insert in middle or end
        curr = head;
        while (curr->next != head && curr->next->data < val)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    void insertSpecific(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else if (head->data == val && head->next == NULL)
        {
            newNode->next == head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->next->data >= val)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void sortedInsert(int val)
    {
        Node *newNode = new Node(val);

        // Case 1: Empty list
        if (head == NULL)
        {
            newNode->next = newNode; // Circular link to itself
            head = newNode;
            return;
        }

        Node *curr = head;

        // Case 2: Insert before head (new smallest value)
        if (val < head->data)
        {
            // Find the last node (tail)
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = newNode; // Tail now points to new node
            newNode->next = head; // New node points to head
            head = newNode;       // New node becomes new head
            return;
        }

        // Case 3: Insert in middle or end
        while (curr->next != head && curr->next->data < val)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Print circular list
    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main()
{
    List ll;
    ll.push_sorted(20);
    ll.push_sorted(10);
    ll.push_sorted(15);
    ll.push_sorted(5);
    ll.push_sorted(30);

    cout << "Sorted Circular Linked List:\n";
    ll.printList();
    ll.insertSpecific(5);
    ll.insertSpecific(25);
    ll.printList();

    return 0;
}
