#include <bits/stdc++.h>
using namespace std;

/*
Approach: Brute Force (Sorting)
T.C. => O(n log n)                			// Simple sort on full array
S.C. => O(1)
*/
void brute() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    sort(arr.begin(), arr.end());  			// Full sort

    cout << "Sorted Array (Brute): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

/*
Approach: Using Min Heap (Without considering k-distance optimization)
T.C. => O(n log n)                         	// Heap push and pop for all elements
S.C. => O(n)
*/
void better() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> pq;    // Min-heap

    // Sabhi elements heap me daal rahe ho
    for (int i = 0; i < arr.size(); i++) pq.push(arr[i]);

    // Pop karke sorted array me daal do
    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    cout << "Sorted Array (Better): ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}




/*
Approach: Optimal (Min Heap with k-distance logic)
T.C. => O(n log k)                         	// Each element push/pop within heap of size k+1
S.C. => O(k)
*/
void optimal() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> pq;    // Min-heap

    // Step 1: Pehle k+1 elements heap me daal do
    for (int i = 0; i <= k; i++) pq.push(arr[i]);

    int index = 0;  										// Sorted index pointer

    // Step 2: Baaki elements process karo
    for (int i = k + 1; i < arr.size(); i++) {
        arr[index++] = pq.top();  						// Smallest nikaal ke daal do
        pq.pop();
        pq.push(arr[i]);  								// Naya element heap me daal do
    }

    // Step 3: Heap ke remaining elements nikaal do
    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }

    cout << "Sorted Array (Optimal): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    brute();
    better();
    optimal();
    return 0;
}
