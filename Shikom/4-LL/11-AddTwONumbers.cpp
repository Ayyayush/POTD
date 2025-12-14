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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1=l1;
        ListNode* temp2=l2;
        string s1="",s2="";
        while (temp1!=NULL)
        {
            s1+=temp1->val;
            temp1=temp1->next;
        }


        while (temp2!=NULL)
        {
            s2+=temp2->val;
            temp2=temp2->next;
        }
       
       reverse(s1.begin(),s1.end());
       reverse(s2.begin(),s2.end());

       long long i1=stoll(s1);
       long long i1=stoll(s2);
       long long i3=i1+i2;
       string s3=to_string(i3);
       ListNode *dummy=NULL;
       for(int i=0;i<s3.size();i++)
       {
        ListNode *curr=new ListNode((int)s3)[i];
        dummy=curr;
        dummy->next=NULL;
       }



       return dummy;

        
    }
};







class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {

            int sum = carry;

            if (temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy->next;
    }
};
