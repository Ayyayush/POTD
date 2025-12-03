 Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        
        
        
    Node *curr = head;                      // Current node
    Node *prevTail = NULL;                  // Pichle reversed group ki tail
    Node *newHead = NULL;                   // Nayi head after reversal

    while (curr != NULL)
    {
        int count = 0;
        Node *groupHead = curr;             // Current group ka head
        Node *prev = NULL;                  // Reverse karne ke liye prev pointer
        
        // Reverse current group of size 'k'
        while (curr != NULL && count < k)
        {
            Node *agla = curr->next;        // Agla node ka pointer
            curr->next = prev;              // Current node ka pointer ulta karte hain
            prev = curr;                    // Prev ko current node banate hain
            curr = agla;                    // Curr ko agli node par le jaate hain
            count++;
        }

        if (newHead == NULL)
        {
            newHead = prev;                 // Pehla group reverse hone ke baad naya head set karte hain
        }

        if (prevTail != NULL)
        {
            prevTail->next = prev;          // Pichle group ki tail ko current group ke head se connect karte hain
        }

        prevTail = groupHead;               // Current group ki tail ko update karte hain
    }

    head = newHead;                         // Naya head set karte hain
}


        // code here