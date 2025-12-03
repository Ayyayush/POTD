#include <bits/stdc++.h>
using namespace std;




// ✅ Approach: Brute Force (No Heap)
// T.C : O(n * m + n*m log(n*m))          		// For creating all pair sums and sorting
// S.C : O(n * m + k)                     		// Vector to store all pair sums

void brute()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];				// Input array a
    for (int i = 0; i < m; i++) cin >> b[i];				// Input array b

    vector<int> allSums;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            allSums.push_back(a[i] + b[j]);					// Store all pair sums
        }
    }

    sort(allSums.begin(), allSums.end(), greater<int>());	// Sort in descending order

    vector<int> res;
    for (int i = 0; i < k && i < allSums.size(); i++)
    {
        res.push_back(allSums[i]);							// Pick top k sums
    }

    for (auto x : res) cout << x << " ";					// Output result
    cout << endl;
}




// ✅ Approach: good Force + Multiset
// T.C : O(n * m * log(n*m) + k)              	// Insertion into multiset + iterate top k
// S.C : O(n * m + k)                         	// multiset + result vector

void good()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];			// Input array a
    for (int i = 0; i < m; i++) cin >> b[i];			// Input array b

    multiset<int> sums;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sums.insert(a[i] + b[j]);				// All pair sums auto-sorted
        }
    }

    vector<int> res;

    auto it = sums.rbegin();						// Start from largest value
    for (int cnt = 0; cnt < k && it != sums.rend(); cnt++, it++)
    {
        res.push_back(*it);							// Get top-k elements
    }

    for (auto x : res) cout << x << " ";			// Output result
    cout << endl;
}


// ✅ Approach: Better Force + Max Heap
// T.C : O(n * m + k log(n*m))         		// n*m sum generation, heap push/pop k times
// S.C : O(n * m + k)                  		// heap + result vector

void better()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];			// Input array a
    for (int i = 0; i < m; i++) cin >> b[i];			// Input array b

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pq.push(a[i] + b[j]);						// Push all pair sums into max heap
        }
    }

    vector<int> res;
    while (!pq.empty() && k--)
    {
        res.push_back(pq.top());						// Get top k max sums
        pq.pop();
    }

    for (auto x : res) cout << x << " ";				// Output the result vector
    cout << endl;
}


/**
 * Optimal approach 
 * dono arrays ko descending order mien sort karo
 * ab set bhi le lo taaki ek hi index pair sum ko wapas na le 
 * ab pura traverse kiye bina try karo kis ek particuakr index ke sath ..
 * agle k elemtns from next array ke sath sum nikal lo
 * set btata rahega ki isse pehle toh nhi nilkla tha 
 * resultant array mein sum daalte raho 
 */


// ✅ Approach: Max Heap + Visited Set (Efficient Top K Sum Pairs)
// T.C : O(n log n + k log k)      			// Sort arrays + Heap push/pop for k pairs
// S.C : O(k)                       			// Heap and Set store at most k elements

void optimal()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];			// Input array a
    for (int i = 0; i < n; i++) cin >> b[i];			// Input array b

    sort(a.rbegin(), a.rend());						// Sort a in descending order
    sort(b.rbegin(), b.rend());						// Sort b in descending order

    // Max-heap: stores {sum, {i, j}}
    priority_queue<pair<int, pair<int, int>>> pq;

    // Visited set to avoid duplicate pairs
    set<pair<int, int>> visited;

    // Seed the heap with the largest possible pair (0, 0)
    pq.push({ a[0] + b[0], {0, 0} });
    visited.insert({0, 0});

    vector<int> result;
    result.reserve(k);									// Reserve space for top-k sums

    while (result.size() < k && !pq.empty())
    {
        auto top = pq.top(); pq.pop();					// Get current max sum pair
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        result.push_back(sum);							// Push to result

        // Push (i, j+1) if valid and not visited
        if (j + 1 < n && visited.emplace(i, j + 1).second)
        {
            pq.push({ a[i] + b[j + 1], {i, j + 1} });
        }

        // Push (i+1, j) if valid and not visited
        if (i + 1 < n && visited.emplace(i + 1, j).second)
        {
            pq.push({ a[i + 1] + b[j], {i + 1, j} });
        }
    }

    for (int x : result) cout << x << " ";				// Output result
    cout << endl;
}

int main()
{
    optimal();
    return 0;
}

/*
 *
 * Dry Run
 *
 * Input: a = [2, 4, 1], b = [3, 5, 2], k = 4
 *
 * Step 1: sort descending
 *   a → [4, 2, 1]
 *   b → [5, 3, 2]
 *
 * Step 2: initialize
 *   pq = {(9, (0,0))}      // 4+5=9
 *   st = {(0,0)}
 *   result = []
 *
 * Step 3: pop (9,0,0)
 *   result = [9]
 *   push (i, j+1) = (0,1): sum=4+3=7
 *   push (i+1, j) = (1,0): sum=2+5=7
 *   pq = {(7,(0,1)), (7,(1,0))}
 *   st = {(0,0), (0,1), (1,0)}
 *
 * Step 4: pop one 7, say (7,1,0)
 *   result = [9, 7]
 *   push (1,1): 2+3=5
 *   push (2,0): 1+5=6
 *   pq = {(7,(0,1)), (6,(2,0)), (5,(1,1))}
 *   st adds (1,1), (2,0)
 *
 * Step 5: pop next 7 (7,0,1)
 *   result = [9, 7, 7]
 *   push (0,2): 4+2=6
 *   (1,1) already in st, skip
 *   pq = {(6,(2,0)), (6,(0,2)), (5,(1,1))}
 *   st adds (0,2)
 *
 * Step 6: pop 6 (6,2,0)
 *   result = [9, 7, 7, 6]
 *   push (2,1): 1+3=4
 *   (3,0) OOB, skip
 *   pq = {(6,(0,2)), (5,(1,1)), (4,(2,1))}
 *   st adds (2,1)
 *
 * result.size()==4 → stop.
 * Output: [9, 7, 7, 6]
 */

int main()
{
    brute();
    return 0;
}
