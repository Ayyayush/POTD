class Solution {
public:
    // Approach: Linked List Traversal without extra space
    // T.C. = O(N * M)   ---> N = length of linked list, M = size of nums vector
    //                       For every node, we do a find in nums vector (O(M))
    // S.C. = O(1)       ---> Only pointers used, no extra data structure

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        // Step 1: Remove head nodes if they are in nums
        while (head != NULL && find(nums.begin(), nums.end(), head->val) != nums.end()) {
            head = head->next;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        // Step 2: Traverse the rest of the list
        while (temp != NULL) {
            if (find(nums.begin(), nums.end(), temp->val) != nums.end()) {
                // Current node needs to be removed
                if(prev != NULL)
                    prev->next = temp->next;  // Skip current node
            } else {
                // Current node is safe, move prev
                prev = temp;
            }
            temp = temp->next;  // Move temp always
        }

        return head;
    }
};



class Solution {
public:
    // Approach: Linked List Traversal with Hashing
    // T.C. = O(N + M)   ---> N = length of linked list, M = size of nums vector
    //                       O(M) for building unordered_set + O(N) traversal
    // S.C. = O(M)       ---> unordered_set used to store nums

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;                                         // nums ko store karne ke liye set
        for (int num : nums) st.insert(num);                           // O(M)

        ListNode* dummy = new ListNode(-1);                            // dummy node taaki head handle ho jaaye
        dummy->next = head;

        ListNode* curr = dummy;                                        // current pointer dummy pe set
        while (curr->next != nullptr) {                                // jab tak list khatam na ho
            if (st.count(curr->next->val)) {                           // agar next node ka value delete karna hai
                curr->next = curr->next->next;                         // us node ko skip kar do
            } else {
                curr = curr->next;                                     // warna aage badho
            }
        }

        return dummy->next;                                            // final updated head return karo
    }
};
