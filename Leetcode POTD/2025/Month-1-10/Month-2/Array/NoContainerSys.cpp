#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(log(n)) for change(), O(1) for find()
// Space Complexity: O(n)
void brute()
{
    unordered_map<int, int> idxToNum; // Stores mapping of index to number
    unordered_map<int, set<int>> numToIdx; // Stores mapping of number to a set of indices
    
    int q;
    cin >> q; // Number of queries
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "change")
        {
            int index, number;
            cin >> index >> number;
            if (idxToNum.count(index)) // Checks if index already has a number assigned  O(1)
            {
                int prevNum = idxToNum[index]; // Get previous number at this index
                numToIdx[prevNum].erase(index); // Remove this index from the set of the previous number O(log(n))
                if (numToIdx[prevNum].empty()) // If no index is left for this number
                {
                    numToIdx.erase(prevNum); // Remove the number entry completely O(1)
                }
            }
            idxToNum[index] = number; // Assign new number to the index
            numToIdx[number].insert(index); // Insert index into the set for this number O(log(n))
        }
        else if (op == "find")
        {
            int number;
            cin >> number;
            if (numToIdx.count(number)) // Check if number exists in map O(1)
            {
                cout << *numToIdx[number].begin() << endl; // Return smallest index containing this number O(1)
            }
            else
            {
                cout << -1 << endl; // If number not found, return -1
            }
        }
    }
}

// Better Approach
// Time Complexity: O(log(n)) for change(), O(k * log(n)) for find()
// Space Complexity: O(n)
void better()
{
    unordered_map<int, int> idxToNum; // Stores mapping of index to number
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx; // Stores mapping of number to min-heap of indices
    
    int q;
    cin >> q; // Number of queries
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "change")
        {
            int index, number;
            cin >> index >> number;
            idxToNum[index] = number; // Store number at the given index O(1)
            numToIdx[number].push(index); // Push index into min-heap for this number O(log(n))
        }
        else if (op == "find")
        {
            int number;
            cin >> number;
            if (!numToIdx.count(number)) // If number doesn't exist in map
            {
                cout << -1 << endl; // Return -1
                continue;
            }
            auto &pq = numToIdx[number]; // Get reference to priority queue (min-heap) of indices
            while (!pq.empty()) // Process indices O(k * log(n))
            {
                int idx = pq.top(); // Get smallest index O(1)
                if (idxToNum[idx] == number) // If index is still valid
                {
                    cout << idx << endl; // Print the index
                    break;
                }
                pq.pop(); // Remove invalid index from heap O(log(n))
            }
        }
    }
}

// Optimal Approach
// The "better" approach is already optimal in this case, as it maintains efficient lookup and update times.
void optimal()
{
    better(); // Calling the better function as it's already optimal
}

int main()
{
    brute();
    better();
    return 0;
}
