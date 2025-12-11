class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {

        Node* newNode = new Node(x);
        Node* temp = head;

        // Move to the p-th node
        int index = 0;
        while (temp != nullptr && index < p) {
            temp = temp->next;
            index++;
        }

        // If p is out of bounds (should not happen per constraints)
        if (temp == nullptr) return head;

        Node* nextNode = temp->next;

        // Insert after temp
        temp->next = newNode;
        newNode->prev = temp;

        newNode->next = nextNode;
        if (nextNode != nullptr) nextNode->prev = newNode;

        return head;
    }
};
