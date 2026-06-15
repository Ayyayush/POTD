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
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL || head->next==NULL)
        return NULL;

     
        ListNode * slow=head;
        ListNode * temp=head;
        int size=0,count=0;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }

        while(count<(size/2)-1)
        {
            slow=slow->next;
            count++;
        }

        slow->next=slow->next->next;
        return head;

        
    }
};



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
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL || head->next==NULL)
        return NULL;

        ListNode* fast=head;
        ListNode * slow=head;
         ListNode * prev=head;

        while(fast!=NULL &&  fast->next!=NULL)
        {
            prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        }
       prev->next=slow->next;
        return head;

        
    }
};