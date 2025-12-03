

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        // Fast and slow pointers to detect the cycle
        Node *fast = head;
        Node *slow = head;

        // Flag to check if a cycle exists
        bool iscycle = false;

        // Step 1: Detect the cycle using Floyd's Cycle Detection Algorithm
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
               
                iscycle = true;
                break;
            }
        }

        // If no cycle is detected, return 0
        if (!iscycle)
        {
           
            return NULL;
        }

        // Step 2: Handle the special case where the cycle starts at the head
        slow = head;
        if (slow == fast)
        { // Special Case
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL; // Break the cycle
        }
        else
        {
            // Step 3: General case to find the start of the cycle and remove 
            Node *prev = NULL; // To track the node before the start of the cycle
            while (fast != slow)
            {
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL; // Break the cycle
        }

       
        return 1; // Cycle successfully removed

   
        // code here
    }
};