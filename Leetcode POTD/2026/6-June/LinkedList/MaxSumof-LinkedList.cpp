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
class Solution
{
public:
    int pairSum(ListNode *head)
    {

        int maxSum = 0;

        if (head == NULL || head->next == NULL)
        {
            return head->val;
        }

        ListNode *temp = head;
        int count = 0, size = 0;

        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }

        unordered_map<int, int> mp;
        temp = head;
        int n = size;
        size = size / 2;
        count = 0;

        while (temp != NULL)
        {
            int index;

            if (count < size)
            {
                index = count;
            }
            else
            {
                index = n - 1 - count;
            }

            mp[index] += temp->val;

            maxSum = max(maxSum, mp[index]);

            temp = temp->next;
            count++;
        }

        return maxSum;
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
    int pairSum(ListNode* head) {

        int maxSum = 0;

        if(head == NULL || head->next == NULL)
        {
            return head->val;
        }

        ListNode* temp = head;
        int count = 0, size = 0;
        vector<int>arr;

        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
          
        }


        int i=0,j=arr.size()-1;
        while(i<=j)
        {
            maxSum=max(maxSum,arr[i]+arr[j]);
            i++;
            j--;
        }

        return maxSum;
    }
};