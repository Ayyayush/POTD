#include <bits/stdc++.h>
using namespace std;

/* ================= NODE DEFINITION ================= */
class Node
{
public:
    int val;                 // stores data
    Node *prev;              // pointer to previous node
    Node *next;              // pointer to next node

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
    Node *head;              // head pointer of DLL

public:
    DoublyLinkedList()
    {
        head = NULL;         // initially list is empty
    }

    /* -------- INSERT AT END -------- */
    void insert(int x)
    {
        Node *newNode = new Node(x);     // create new node

        if (head == NULL)
        {
            head = newNode;              // if list empty, new node is head
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)       // traverse to last node
        {
            temp = temp->next;
        }

        temp->next = newNode;            // attach new node at end
        newNode->prev = temp;            // set backward link
    }

    /* -------- REMOVE DUPLICATES (SORTED DLL) -------- */
    void rmvDuplicates()
    {
        if (head == NULL)
            return;                      // empty list check

        Node *curr = head;

        while (curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                Node *duplicate = curr->next;   // duplicate node

                curr->next = duplicate->next;   // bypass duplicate

                if (duplicate->next != NULL)
                    duplicate->next->prev = curr;

                delete duplicate;               // free memory
            }
            else
            {
                curr = curr->next;              // move forward
            }
        }
    }

    /* -------- DELETE ENTIRE LIST -------- */
    void deleteList()
    {
        Node *curr = head;

        while (curr != NULL)
        {
            Node *nextNode = curr->next;
            delete curr;                 // delete current node
            curr = nextNode;
        }

        head = NULL;                     // reset head
    }

    /* -------- CHECK IF LIST IS EMPTY -------- */
    bool empty()
    {
        return head == NULL;             // returns true if empty
    }



    /* -------- Find pairs with given sum (YOUR APPROACH: Nested Loops) -------- */
void findPair(int target, vector<pair<int,int>> &arr)
{
    if (head == NULL)
        return;                                   // empty list check

    Node *temp = head;                            // first pointer

    while (temp != NULL)
    {
        Node *curr = temp->next;                  // second pointer starts ahead

        while (curr != NULL)
        {
            int val1 = temp->val;                 // first value
            int val2 = curr->val;                 // second value

            if (val1 + val2 == target)
            {
                arr.push_back({val1, val2});      // store valid pair
            }

            curr = curr->next;                    // move inner pointer
        }

        temp = temp->next;                        // move outer pointer
    }
}



    /* -------- FIND PAIRS WITH GIVEN SUM (SORTED DLL) -------- */
    void findPair(int target, vector<pair<int,int>> &arr)
    {
        if (head == NULL)
            return;

        Node *left = head;               // left pointer

        Node *right = head;
        while (right->next != NULL)      // move right to last node
        {
            right = right->next;
        }

        // Two-pointer approach
        while (left != right && right->next != left)
        {
            int sum = left->val + right->val;

            if (sum == target)
            {
                arr.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
    }

    /* -------- DISPLAY LIST -------- */
    void display()
    {
        Node *temp = head;

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
    dll.insert(4);
    dll.insert(5);

    cout << "Before removing duplicates: ";
    dll.display();

    dll.rmvDuplicates();

    cout << "After removing duplicates: ";
    dll.display();

    vector<pair<int,int>> pairs;
    int target = 6;

    dll.findPair(target, pairs);

    cout << "Pairs with sum " << target << ":\n";
    for (auto &p : pairs)
    {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
