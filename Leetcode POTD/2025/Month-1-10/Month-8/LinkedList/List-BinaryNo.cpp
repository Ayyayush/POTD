#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void brute()  
{
    // ✅ Approach: Store all bits in vector, convert to a number (❌ flawed)
    // ❌ May cause out-of-range / overflow for large inputs
    // ✅ T.C. = O(n), S.C. = O(n)

    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);    // Linked list: 1 -> 0 -> 1

    ListNode* temp = head;
    vector<int> vec;

    while(temp != NULL) {
        vec.push_back(temp->val);          // store all bits in vector
        temp = temp->next;
    }

    long long num = 0;

    for(int i = 0; i < vec.size(); i++) {
        num = num * 10 + vec[i];           // ❌ treating binary as decimal string
    }

    int idx = 0, sum = 0;

    // reverse the decimal digits and apply power of 2 logic
    while(num)
    {
        int rem = num % 10;
        if(rem == 1) {
            sum += pow(2, idx);            // calculate 2^idx if bit is 1
        }
        idx++;
        num /= 10;
    }

    cout << sum << endl;                   // final decimal value
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void better()
{
    // ✅ Approach: Store values in vector, convert to string, then reverse binary string
    // ✅ T.C. = O(n), S.C. = O(n)
    // ❗ Note: pow(2, idx) and string handling is not optimal, just better than brute

    // Create example linked list: 1 -> 0 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    ListNode *temp = head;
    vector<int> vec;

    while(temp != NULL)
    {
        vec.push_back(temp->val);                  // store bits in order
        temp = temp->next;
    }

    string str = "";
    for(int i = 0; i < vec.size(); i++)
    {
        str += (vec[i] + '0');                     // convert int to char and form binary string
    }

    int idx = 0, sum = 0;

    while(!str.empty())
    {
        char rem = str.back();                     // process from LSB
        str.pop_back();

        if(rem == '1') {
            sum += pow(2, idx);                    // add 2^idx for each '1'
        }

        idx++;
    }

    cout << sum << endl;                           // print final decimal value
}
 



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void optimal()
{
    // ✅ Approach: Bitwise Left Shift
    // ✅ T.C. = O(n), S.C. = O(1)

    // Create example linked list: 1 -> 0 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    int result = 0;

    while(head != NULL)
    {
        result = (result << 1) | head->val;    // left shift + add current bit
        head = head->next;
    }

    cout << result << endl;                   // print final decimal number
}

int main()
{
    optimal();
    return 0;
}
