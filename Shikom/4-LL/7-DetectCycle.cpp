#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node *head;

    List() {
        head = NULL;
    }

    void insert(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // ✅ Function to detect cycle using Floyd’s Algorithm
    bool detectCycle() {
        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // moves 1 step
            fast = fast->next->next;     // moves 2 steps

            if (slow == fast) {
                return true;             // cycle detected
            }
        }
        return false;                    // no cycle found
    }
};

int main() {
    List l;

    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);

    // Creating a cycle manually:
    l.head->next->next->next->next = l.head->next; // 4 → 2

    if (l.detectCycle()) cout << "Cycle detected\n";
    else cout << "No cycle\n";

    return 0;
}



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = set()
        temp = head

        while temp is not None:
            if temp in visited:      # check if node already seen
                return True          # cycle detected

            visited.add(temp)        # mark node as visited
            temp = temp.next         # move ahead

        return False                 # reached end → no cycle
