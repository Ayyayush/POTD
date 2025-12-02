#include <bits/stdc++.h>
using namespace std;

/** 
 * Approach - 1 : Hashing + Sorting (General Approach)
 * T.C. => O(n log n)
 * S.C. => O(n)
 */
void brute() {
    int k = 2;
    vector<int> arr = {1,1,1,2,2,3};
    
    unordered_map<int,int> mp;               // frequency count
    for(int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    vector<pair<int,int>> freqVec;
    for(auto x : mp) {
        freqVec.push_back({x.second, x.first}); // {frequency, number}
    }

    sort(freqVec.rbegin(), freqVec.rend());    // sort descending by frequency

    vector<int> ans;
    for(int i = 0; i < k; i++) {
        ans.push_back(freqVec[i].second);
    }

    for(int x : ans) cout << x << " ";
    cout << endl;
}

/** 
 * Approach - 2 : Fixed-size frequency vector (range <= 1e6)
 * T.C. => O(n + m + n log n) ; m = 1e6
 * S.C. => O(m + n)
 */
void better() {
    int k = 2;
    vector<int> arr = {1,1,1,2,2,3};
    
    vector<int> freq(1000000, 0);             // frequency array
    for(int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }

    vector<pair<int,int>> freqVec;
    for(int i = 0; i < freq.size(); i++) {
        if(freq[i] > 0) {
            freqVec.push_back({freq[i], i});
        }
    }

    sort(freqVec.rbegin(), freqVec.rend());

    vector<int> result;
    for(int i = 0; i < k; i++) {
        result.push_back(freqVec[i].second);
    }

    for(int x : result) cout << x << " ";
    cout << endl;
}

/**
 * Approach - 3 : Using Priority Queue (Heap) - Optimal
 * T.C. => O(n log k)
 * S.C. => O(n + k)
 */
void optimal() {
    int k = 2;
    vector<int> arr = {1,1,1,2,2,3};
    
    unordered_map<int,int> freq;
    for(int x : arr) freq[x]++;               // frequency map

    // Max-heap of pairs (frequency, number)
    priority_queue<pair<int,int>> pq;
    for(auto x : freq) {
        pq.push({x.second, x.first});
    }

    vector<int> ans;
    for(int i = 0; i < k; i++) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    for(int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    cout << "Brute: ";
    brute();

    cout << "Better: ";
    better();

    cout << "Optimal: ";
    optimal();

    return 0;
}
