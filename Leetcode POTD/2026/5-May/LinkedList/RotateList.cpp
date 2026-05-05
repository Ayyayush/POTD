class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL)                        // If the list is empty, no rotation is possible
            return NULL;

        int size = 0;
        ListNode* temp = head;

        // Calculate the size of the linked list
        while (temp != NULL) {
            size++;                               // Increment size as we traverse the list
            temp = temp->next;                    // Move to the next ListNode
        }

        if (size == 0 || k % size == 0)           // If size is 0 or no rotation needed
            return head;

        k = k % size;                             // In case k > size, rotate only the remainder
        temp = head;

        // Traverse the list to find the (size - k - 1)th node
        for (int i = 0; i < size - k - 1; ++i) {
            temp = temp->next;                    // Move temp to the (size - k - 1)th node
        }

        ListNode* nhead = temp->next;             // The new head will be the (size - k)th node
        temp->next = NULL;                        // Disconnect the last part of the list

        // Traverse to the last node of the rotated list
        ListNode* last = nhead;
        while (last->next != NULL) {
            last = last->next;                    // Move last to the next ListNode
        }

        // Connect the last node to the original head
        last->next = head;                       
        return nhead;                            // Return the new head of the rotated list
    }
};