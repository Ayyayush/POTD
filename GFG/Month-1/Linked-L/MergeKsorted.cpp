#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    #define p pair<int, Node*>
    
    Node* mergeKLists(vector<Node*>& arr) {
        // Min-heap use kar rahe hain taaki har list ka sabse chhota element sabse pehle aaye
        priority_queue<p, vector<p>, greater<p>> pq;
        
        // Dummy node create kar rahe hain jo merged linked list ka head hoga
        Node* newHead = new Node(-1);
        
        // Har linked list ka first element min-heap mein daal rahe hain
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != NULL) {
                pq.push({arr[i]->data, arr[i]});
            }
        }
        
        Node* temp = newHead; // Temporary pointer jo merged list ko banayega
        
        // Jab tak heap empty na ho jaaye, smallest element nikal ke list mein daalte rahenge
        while (!pq.empty()) {
            Node* curr = pq.top().second; // Heap ka sabse chhota element
            pq.pop();
            temp->next = curr; // Merged list mein add kar rahe hain
            temp = temp->next;
            
            // Agar current node ke baad bhi elements hain toh next node ko heap mein push karenge
            if (curr->next) {
                pq.push({curr->next->data, curr->next});
            }
        }
        
        return newHead->next; // Dummy node ke next se actual merged list shuru hogi
    }
};

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    int k = 3; // Total 3 sorted linked lists
    vector<Node*> arr(k);
    
    // Pehli linked list
    arr[0] = new Node(1);
    arr[0]->next = new Node(4);
    arr[0]->next->next = new Node(5);
    
    // Doosri linked list
    arr[1] = new Node(1);
    arr[1]->next = new Node(3);
    arr[1]->next->next = new Node(4);
    
    // Teesri linked list
    arr[2] = new Node(2);
    arr[2]->next = new Node(6);
    
    Solution obj;
    Node* mergedHead = obj.mergeKLists(arr);
    
    cout << "Merged Sorted Linked List:\n";
    printList(mergedHead);
    
    return 0;
}
