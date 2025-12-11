class Solution {
  public:
    Node* reverse(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        Node* prevNode = NULL;

        while (curr != NULL) {
            // Swap prev and next pointers
            Node* nextNode = curr->next;
            curr->next = curr->prev;
            curr->prev = nextNode;

            prevNode = curr;      // last processed node → new head
            curr = nextNode;
        }

        return prevNode;  // new head after reversing
    }
};



class Node:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None


class Solution:
    def reverse(self, head):
        if head is None:
            return head

        curr = head
        prevNode = None

        while curr is not None:
            # Swap next and prev
            nextNode = curr.next
            curr.next = curr.prev
            curr.prev = nextNode

            prevNode = curr   # This becomes new head at end
            curr = nextNode   # Move forward using original next

        return prevNode   # new head after reversing
