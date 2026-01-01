#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//-----------------------------------------------
// 💡 Method 1: Simple Iterative Two Pointer
// T.C. = O(n)               🕒
// S.C. = O(1)               🗃️
//-----------------------------------------------
void method1()
{
    // Input list: 1 → 1 → 2 → 3 → 3
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    ListNode* curr = head;

    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;               // Duplicate found → skip it
        } else {
            curr = curr->next;                           // Move ahead normally
        }
    }

    // Output the list
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//-----------------------------------------------
// 💡 Method 2: HashSet to Track Duplicates (Use only if unsorted)
// T.C. = O(n)               🕒
// S.C. = O(n)               🗃️
//-----------------------------------------------
void method2()
{
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    unordered_set<int> st;
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while (curr) {
        if (st.count(curr->val)) {
            prev->next = curr->next;                     // Already exists → skip it
        } else {
            st.insert(curr->val);                        // Insert in set
            prev = curr;
        }
        curr = curr->next;
    }

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//-----------------------------------------------
// 💡 Method 3: Using Ancient Node (Handles head duplicates more cleanly)
// T.C. = O(n)               🕒
// S.C. = O(1)               🗃️
//-----------------------------------------------
void method3()
{
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    if (!head || !head->next) {
        cout << head->val << endl;
        return;
    }

    ListNode* ancient = nullptr;
    ListNode* prev = head;
    ListNode* curr = head->next;

    while (curr) {
        if (curr->val == prev->val) {
            if (ancient == nullptr) {
                head = curr;                             // Head is duplicate
            } else {
                ancient->next = curr;                    // Skip prev
            }
            prev = curr;
            curr = curr->next;
        } else {
            ancient = prev;
            prev = curr;
            curr = curr->next;
        }
    }

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//------------------------------------------------------------
// 💡 Method 4: Use array → remove duplicates → rebuild list
// T.C. = O(n log n) for sorting                🕒
// S.C. = O(n)                                  🗃️
//------------------------------------------------------------
void method4()
{
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    vector<int> vals;
    ListNode* curr = head;
    while (curr) {
        vals.push_back(curr->val);                      // Store values
        curr = curr->next;
    }

    sort(vals.begin(), vals.end());                     // Ensure sorting
    vals.erase(unique(vals.begin(), vals.end()), vals.end());   // Remove duplicates

    // Create new list from unique values
    ListNode* newHead = new ListNode(vals[0]);
    ListNode* tail = newHead;

    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }

    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
}

int main()
{
    cout << "Method 1: Simple Iterative:" << endl;
    method1();

    cout << "\nMethod 2: Using HashSet:" << endl;
    method2();

    cout << "\nMethod 3: Ancient Node Approach:" << endl;
    method3();

    cout << "\nMethod 4: Array + Sort + Unique + New List:" << endl;
    method4();

    return 0;
}
