Node* splitatMid(Node* head) {                            // Function to split the linked list into two halves
    if (head == NULL || head->next == NULL) {              // If the list is empty or has one element, return NULL
        return NULL;                                      // Return NULL
    }

    Node* slow = head;                                    // Slow pointer to move one step at a time
    Node* fast = head;                                    // Fast pointer to move two steps at a time
    Node* prev = NULL;                                    // Previous pointer to track node before slow

    while (fast != NULL && fast->next != NULL) {           // Traverse the list
        prev = slow;                                       // Move prev to slow
        slow = slow->next;                                 // Move slow pointer one step forward
        fast = fast->next->next;                           // Move fast pointer two steps forward
    }

    if (prev != NULL) {                                    // Disconnect the left half from the right half
        prev->next = NULL;                                 // Set prev's next to NULL to split the list
    }
    
    return slow;                                           // Return right half starting from slow
}


Node* merge(Node* left, Node* right) {                    // Function to merge two sorted linked lists
    Node* ansHead = new Node(0);                          // Create a dummy node for the merged list
    Node* temp = ansHead;                                 // Pointer to build the merged list

    while (left != NULL && right != NULL) {                // While both lists have elements
        if (left->data <= right->data) {                   // Compare values in left and right lists
            temp->next = left;                             // Attach left node to merged list
            left = left->next;                             // Move to the next node in the left list
        } else {
            temp->next = right;                            // Attach right node to merged list
            right = right->next;                           // Move to the next node in the right list
        }
        temp = temp->next;                                 // Move temp to the next node in the merged list
    }

    while (left != NULL) {                                 // If there are any nodes left in the left list
        temp->next = left;                                 // Attach the remaining left nodes
        left = left->next;                                 // Move to the next node in the left list
        temp = temp->next;                                 // Move temp to the next node
    }

    while (right != NULL) {                                // If there are any nodes left in the right list
        temp->next = right;                                // Attach the remaining right nodes
        right = right->next;                               // Move to the next node in the right list
        temp = temp->next;                                 // Move temp to the next node
    }

    return ansHead->next;                                  // Return the merged sorted list (ignoring the dummy node)
}

Node* mergesort(Node* head) {                             // Function to perform merge sort on the linked list
    if (head == NULL || head->next == NULL) {              // Base case: empty or single-node list
        return head;                                      // Return the head of the sorted list
    }

    Node* righthead = splitatMid(head);                    // Split the list into two halves
    Node* left = mergesort(head);                          // Recursively sort the left half
    Node* right = mergesort(righthead);                    // Recursively sort the right half

    return merge(left, right);                             // Merge the sorted left and right halves
}
