#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            freqMap[ch]++;
        }

        // Step 2: Store characters and frequency as pairs
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

        // Step 3: Sort based on frequency (high to low)
        sort(freqVec.begin(), freqVec.end(), [](pair<char, int> &a, pair<char, int> &b) {
            return a.second > b.second;
        });

        // Step 4: Build the result string
        string result = "";
        for (auto &[ch, freq] : freqVec) {
            result += string(freq, ch);
        }

        return result;
    }
};



//Approach-2 (Using Priority Queue) - O(nlong)
class Solution {
public:
    typedef pair<char, int> P;
    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second<p2.second; //max-heap
        }
    };
    
    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;
        
        unordered_map<char, int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.first, it.second});
        }
        
        string result = "";
        
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result += string(temp.second, temp.first);
        }
        return result;
    }
};


class Solution:
    def frequencySort(self, s: str) -> str:
        # Step 1: Count frequency of each character
        freq_map = {}
        for ch in s:
            freq_map[ch] = freq_map.get(ch, 0) + 1

        # Step 2: Convert to list of (char, freq) pairs
        freq_vec = list(freq_map.items())

        # Step 3: Sort by frequency (high to low)
        freq_vec.sort(key=lambda x: x[1], reverse=True)

        # Step 4: Build result string
        result = ""
        for ch, freq in freq_vec:
            result += ch * freq

        return result



import heapq

class Solution:
    def frequencySort(self, s: str) -> str:
        # Step 1: Count frequency of each character
        freq = {}
        for ch in s:
            freq[ch] = freq.get(ch, 0) + 1

        # Step 2: Create a max heap (Python has min-heap, so use negative freq)
        max_heap = []
        for ch, count in freq.items():
            heapq.heappush(max_heap, (-count, ch))

        # Step 3: Build result string
        result = ""
        while max_heap:
            count, ch = heapq.heappop(max_heap)
            result += ch * (-count)   # negate count back to positive

        return result
