#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ! APPROACH : Circular Linked List
    // ! T.C. : O(N)
    // ! S.C. : O(1)

    ListNode* rotateRight(ListNode* head, int k) {

        // ! Edge cases
        if(head == NULL || head->next == NULL || k == 0)
        return head;

        int totalNodes = 1;

        ListNode* lastNode = head;

        // ! Find total nodes and last node
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
            totalNodes++;
        }

        // ! Remove extra rotations
        k = k % totalNodes;

        // ! No rotation needed
        if(k == 0)
        return head;

        // ! Convert into circular linked list
        lastNode->next = head;

        // ! Find position of new last node
        int newLastNodePosition = totalNodes - k;

        ListNode* newLastNode = head;

        // ! Move to new last node
        for(int move = 1; move < newLastNodePosition; move++)
        {
            newLastNode = newLastNode->next;
        }

        // ! New head after rotation
        ListNode* newHead = newLastNode->next;

        // ! Break circular connection
        newLastNode->next = NULL;

        return newHead;          // always give if exists
    }
};