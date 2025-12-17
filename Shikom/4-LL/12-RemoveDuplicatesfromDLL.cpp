#include <bits/stdc++.h>
using namespace std;

/* ================= NODE DEFINITION ================= */
class Node
{
public:
    int val;                 // stores data
    Node* prev;              // pointer to previous node
    Node* next;              // pointer to next node

    Node(int data)
    {
        val = data;          // initialize value
        prev = NULL;         // previous pointer initially NULL
        next = NULL;         // next pointer initially NULL
    }
};

/* ================= DOUBLY LINKED LIST ================= */
class DoublyLinkedList
{
private:
    Node* head;              // head pointer of DLL

public:
    DoublyLinkedList()
    {
        head = NULL;         // initially list is empty
    }

    /* -------- INSERT AT END -------- */
    void insert(int x)
    {
        Node* newNode = new Node(x);          // create new node

        if (head == NULL)
        {
            head = newNode;                   // if list empty, new node is head
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)            // traverse to last node
        {
            temp = temp->next;
        }

        temp->next = newNode;                 // attach new node at end
        newNode->prev = temp;                 // set backward link
    }

    

    /* -------- REMOVE DUPLICATES (SORTED DLL) -------- */
    void rmvDuplicates()
    {
        if (head == NULL) return;              // empty list check

        Node* curr = head;

        while (curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                Node* duplicate = curr->next; // duplicate node

                curr->next = duplicate->next; // bypass duplicate

                if (duplicate->next != NULL)
                    duplicate->next->prev = curr;

                delete duplicate;              // free memory
            }
            else
            {
                curr = curr->next;             // move forward
            }
        }
    }

    /* -------- DELETE ENTIRE LIST -------- */
    void deleteList()
    {
        Node* curr = head;

        while (curr != NULL)
        {
            Node* nextNode = curr->next;
            delete curr;                       // delete current node
            curr = nextNode;
        }

        head = NULL;                           // reset head
    }

    /* -------- CHECK IF LIST IS EMPTY -------- */
    bool empty()
    {
        return head == NULL;                   // returns true if empty
    }

    /* -------- DISPLAY LIST -------- */
    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

/* ================= MAIN FUNCTION ================= */
int main()
{
    DoublyLinkedList dll;

    dll.insert(1);
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(3);

    cout << "Before removing duplicates: ";
    dll.display();

    dll.rmvDuplicates();

    cout << "After removing duplicates: ";
    dll.display();

    return 0;
}
