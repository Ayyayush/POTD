// Approach: Hashing + prev pointer (technically 2-pointer technique with dummy node)
// T.C. = O(N), S.C. = O(1)

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) return nullptr;                                       // Edge case: agar list khali ho

        ListNode* dummy = new ListNode(-1);                              // Dummy node bana rahe hain start mein
        dummy->next = head;                                              // dummy node ko original list se jod do

        ListNode* prev = dummy;                                          // prev: last unique node tracker
        ListNode* curr = head;                                           // curr: current node

        while (curr != nullptr)
        {
            bool duplicate = false;                                      // flag to detect duplicates

            // Jab tak next node exist karti hai aur duplicate milta hai
            while (curr->next != nullptr && curr->val == curr->next->val)
            {
                duplicate = true;                                        // Duplicate mil gaya
                curr = curr->next;                                       // skip karo duplicate nodes
            }

            if (duplicate)
            {
                prev->next = curr->next;                                 // sare duplicates hata ke prev ko next unique se jodo
            }
            else
            {
                prev = prev->next;                                       // koi duplicate nahi mila toh prev ko aage badhao
            }

            curr = curr->next;                                           // har case mein curr ko aage badhao
        }

        return dummy->next;                                              // dummy->next hi naya head hai
    }
};
