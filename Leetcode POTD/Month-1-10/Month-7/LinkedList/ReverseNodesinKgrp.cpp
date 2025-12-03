/**
 * Reverse Nodes in K groups
 * *APPROACH
 * hum har k size ke group ko reverse krna h
 * Hum nayi list create nhi kr rhe h ussi mein karenge
 * Agar last mein k size grp nhi ban paya toh usko waise hi return kar denge
 * Hum recursive Approach use karenge
 * Ek call mein uss k group ko reverse kar lenge aur agle grp ke liye recursion call kar denge
 *
 *
 * *Step -1
 * Check karo if K nodes exist
 * hai toh ... reverse krne ke liye reverse karo aur next call kar do
 * last group tak jaake base case hit hone ke baad wapas return karega
 *
 * Ab maan lo hai 1->2->3->4->5    grp size==2
 * ab 5 tak jaake base case hit hua toh aaya 5
 * ab 3 aur 4 wale pe aaye toh 3,4 wale grp ke head ko jo backtracking mein mila h
 * usse connect kar do   3->5
 * aur next elt ko usse   4->3->5
 * same aise krte jayenge
 * ab hohga ....1->4->3->5
 * 2->1->4->3->5
 *
 *
 * Ab maan lo hai 1->2->3->4->5    grp size==3
 * 4,5 aise hi return hjo jayega kyunki grp nhi bana
 * toh 4->5 backtrack hua
 * ab aaya 1,2,3 ke paas wapas
 *  1->4->5...hua similary hi
 * firr........3->2->1->4->5
 * Hum ek temp(har grp ke liye)..aur count leke chalenge
 * aur count ==k hone se pehle temp null pahuch jaye toh k size grp nhi mila
 * base case hit ho gya
 *
 *
 * Reverse function(head,k)
 * {
 * Node* temp=head;
 * count=0;
 * while(temp)
 * {
 * temp=temp->next
 * count++;
 * }
 * if(count<k)
 * {
 * backtrack
 * original head hi milega uss grp ka
 * }
 * else
 * {
 * next call
 * reverse(temp->next,k)
 * }
 * }
 *
 *
 * Ab maan lo 4->5 as it is backtrack hua
 * prevnode=4 h
 * pahucha 1->2->3 ke paas
 * ab dekhte h kaise connect karenge 1,2,3 prev node se
 * ab first node 1 ka naya next hoga prev node
 * toh temp ko iss group ke head yani 1 pe initlaize kr dete h
 *
 * loop chaleybnege jabtak k nodes reverse nhi ho jate
 * count ==0 leke karenge firr se
 * 1->4->5 kiya ab prevnode ho gya 1
 * ab 2 prevnode se juda 2->1->4->5  prevnode ho gya 2
 * ab 3 juda 3->2->1->4->5
 *  count ==k hua   ....break kar do
 *
 *
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        int cnt = 0;

        // Step 1: Check if at least k nodes are present
        while (cnt < k && temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }

        if (cnt < k)
            return head; // Agar k se kam nodes hain to reverse mat karo

        // Step 2: Recursively reverse next group
        ListNode *prevNode = reverseKGroup(temp, k); // 'temp' ab k-th node ke baad point kar raha hai

        // Step 3: Reverse current k-group starting from head
        ListNode *curr = head;
        ListNode *next;

        while (cnt--)
        {
            next = curr->next;     // next node store karo
            curr->next = prevNode; // current ka next ab reversed part banega
            prevNode = curr;       // move prevNode ahead
            curr = next;           // move current ahead
        }

        return prevNode; // prevNode ab current group ka new head hai
    }
};



/**
 * CALL STACK (Top → Bottom):

┌──────────────────────────────────────────────────────────────┐
│ reverseKGroup(head=5, k=2)                                   │
│ → cnt = 1 (only 1 node)                                      │
│ → temp = NULL                                                │
│ → cnt < k, return head = 5 (no reverse)                      │
└──────────────────────────────────────────────────────────────┘
┌──────────────────────────────────────────────────────────────┐
│ reverseKGroup(head=3, k=2)                                   │
│ → cnt = 2, temp = 5                                          │
│ → prevNode = reverseKGroup(5, 2) → returns node(5)           │
│ → Reverse current group:                                     │
│     curr = 3, next = 4                                       │
│     Step 1: 3 → 5                                            │
│     curr = 4, next = 5                                       │
│     Step 2: 4 → 3 → 5                                        │
│ → return node(4) as new head of this group                   │
└──────────────────────────────────────────────────────────────┘
┌──────────────────────────────────────────────────────────────┐
│ reverseKGroup(head=1, k=2)                                   │
│ → cnt = 2, temp = 3                                          │
│ → prevNode = reverseKGroup(3, 2) → returns node(4)           │
│ → Reverse current group:                                     │
│     curr = 1, next = 2                                       │
│     Step 1: 1 → 4                                            │
│     curr = 2, next = 3                                       │
│     Step 2: 2 → 1 → 4 → ...                                  │
│ → return node(2) as final head                               │
└──────────────────────────────────────────────────────────────┘

 */
