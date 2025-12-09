class Solution {
public:
    Node* insertPos(Node* head, int pos, int val) {

        // If inserting at the head (position 1)
        if (pos == 1) {
            Node* newnode = new Node(val);            // create new node
            newnode->next = head;                     // link new node to old head
            return newnode;                           // new node becomes head
        }

        Node* temp = head;                             // pointer to traverse
        int currPos = 1;                               // track current position

        // Move temp to (pos - 1)-th node
        while (temp != NULL && currPos < pos - 1) {
            temp = temp->next;
            currPos++;
        }

        // If pos is out of bounds
        if (temp == NULL) return head;

        // Create and insert new node
        Node* newnode = new Node(val);
        newnode->next = temp->next;                    // connect newnode to next node
        temp->next = newnode;                          // connect previous node to newnode

        return head;                                   // return unchanged head
    }
};


class Solution {
public:
    Node* insertAtEnd(Node* head, int x) {

        // If the list is empty, new node becomes head
        if (head == NULL) {
            return new Node(x);
        }

        Node* temp = head;                              // pointer to traverse list

        // Move till the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Create new node and attach at end
        Node* newnode = new Node(x);                    // correct way to allocate
        temp->next = newnode;                           // link last node to new node

        return head;                                    // head remains same
    }
};




//  Linked List Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def insertPos(self, head, pos, val):

        //  If inserting at head (position 1)
        if pos == 1:
            newnode = Node(val)          //  create new node
            newnode.next = head          //  link new node to old head
            return newnode               //  new node becomes new head

        temp = head                      //  pointer to traverse
        currPos = 1                      //  current position

        //  Move temp to (pos - 1)th node
        while temp is not None and currPos < pos - 1:
            temp = temp.next
            currPos += 1

        //  If position is out of bounds
        if temp is None:
            return head

        //  Insert new node
        newnode = Node(val)
        newnode.next = temp.next         //  point new node to next node
        temp.next = newnode              //  link previous node to new node

        return head                      //  return unchanged head



class Solution:
    def insertAtEnd(self, head, x):

        # If list is empty, new node is head
        if head is None:
            return Node(x)

        temp = head                      # pointer to traverse

        # Move to the last node
        while temp.next is not None:
            temp = temp.next

        # Create and attach new node at end
        newnode = Node(x)
        temp.next = newnode

        return head                      # head remains same
