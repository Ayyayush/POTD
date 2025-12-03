/**
 * Reversing Eventh groups 
 * Natural Numbers ke accoridng even number wale grp ko reverse karen h
 * Reverse K group nodes wale se similar problem h 
 * ab maan lo last grp even h par usme elets even nhi h ...
 * toh last wale mein hum actually check karenge ki elts even h ya odd 
 * 
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode* temp = head;
        int gn = 1;
        ListNode* prevgroupLast = NULL;

        while (temp != NULL)
        {
            int k = gn;
            ListNode* groupStart = temp;
            ListNode* groupEnd = temp;
            int count = 0;

            // Count actual number of nodes in this group
            while (groupEnd != NULL && count < k)
            {
                groupEnd = groupEnd->next;
                count++;
            }

            if (count % 2 == 0)  // even length group → reverse
            {
                ListNode* prev = groupEnd;
                ListNode* curr = groupStart;

                while (curr != groupEnd)
                {
                    ListNode* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }

                if (prevgroupLast == NULL)
                {
                    head = prev;
                }
                else
                {
                    prevgroupLast->next = prev;
                }

                prevgroupLast = groupStart;
                temp = groupEnd;
            }
            else  // odd length group → leave as is
            {
                for (int i = 0; i < count; i++)
                {
                    prevgroupLast = temp;
                    temp = temp->next;
                }
            }

            gn++;
        }

        return head;
    }
};
