#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    // T.C. = O(N * log N + N * K)         // sorting + har element se K group check
    // S.C. = O(N)                         // map ke liye extra space

    int n, k;                                                  // array size aur k lena hai
    cin >> n >> k;                                             // input n aur k
    vector<int> arr(n);                                        // array banana
    for (int i = 0; i < n; i++) cin >> arr[i];                 // input array

    if (n % k != 0)                                            // agar array ka size k ke multiple nahi hai
    {
        cout << "false" << endl;                               // toh valid group possible nahi
        return;
    }

    map<int, int> freq;                                        // map bana rahe hain har number ki frequency ke liye

    for (int num : arr) freq[num]++;                           // har number ka count map mein store karo

    /*
      Example:
      arr = [1,2,2,3,3,4], k = 3
      Possible groups = [1,2,3] and [2,3,4]
      Pehle 1 se start karo: check karo 1,2,3 present hain ya nahi
      Fir next smallest number se: 2 se start karo: 2,3,4 present hain ya nahi
    */

    for (auto it = freq.begin(); it != freq.end(); ++it)       // har unique number ko frequency map se uthao
    {
        int num = it->first;                                   // current number
        int count = it->second;                                // current number ki frequency

        if (count > 0)                                         // agar is number ki frequency abhi bhi > 0 hai
        {
            for (int i = 1; i < k; i++)                        // next k-1 consecutive numbers check karo
            {
                if (freq[num + i] < count)                     // agar inki frequency kam hai toh group nahi banega
                {
                    cout << "false" << endl;                   // toh false print karo
                    return;
                }
                freq[num + i] -= count;                        // frequency adjust karo kyunki ye group mein use ho gaye
            }
        }
    }

    cout << "true" << endl;                                    // agar sab groups ban gaye toh true print karo
}





/*
 * Difficulty: Medium Accuracy: 38.4% Submissions: 2K+ Points: 4
 *
 * You are given an array arr[] of positive integers, where each element arr[i] represents the number written on the i-th ball, and a positive integer k.
 * Your task is to determine whether it is possible to rearrange all the balls into groups such that:
 * Each group contains exactly k balls.
 * The numbers in each group are consecutive integers
 *
 * Examples:
 *
 * Input: arr[] = [10, 1, 2, 11], k = 2
 * Output: true
 * Explanation: The hand can be rearranged as [1, 2], [10, 11]. There are two groups of size 2. Each group has 2 consecutive cards.
 *
 * Input: arr[] = [7, 8, 9, 10, 11], k = 2
 * Output: false
 * Explanation: The hand cannot be rearranged into groups of 2, since there are 5 cards, and 5 cards cannot be divided into groups of 2.
 *
 * Constraints:
 * 1 ≤ arr.size() ≤ 106
 * 0 ≤ arr[i] ≤ 105
 * 1 ≤ k ≤ 10^3
 */

/************************************************************ C++ ************************************************/

// Approach 1: Sort the array and greedily form consecutive groups of size k by marking used elements.
// Time Complexity: O(n log n + n·k) due to sorting and scanning for each group, which is O(n log n) when k ≪ n.
// Space Complexity: O(1) extra space (in-place marking with -1), aside from the input array.
class Solution {
public:
    bool validgroup(vector<int>& arr, int k) {
        int n = arr.size();                   // total number of balls

        sort(arr.begin(), arr.end());         // bring consecutive numbers together

        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) {                // already used in a previous group
                continue;
            }

            int curr  = arr[i];               // the next expected number in the group
            int count = 0;                    // how many balls have been added to the current group

            for (int j = i; j < n; j++) {
                if (arr[j] == curr) {         // found the next consecutive ball
                    curr++;                   // expect the next number in sequence
                    count++;                  // one more ball added to this group
                    arr[j] = -1;              // mark this ball as used
                }

                if (count == k) {              // the group is complete
                    break;
                }
            }

            if (count != k) {                  // could not form a full group of size k
                return false;
            }
        }
        return true;                          // all balls successfully grouped
    }
};

/*
 *
 * Dry Run on arr = [3, 1, 4, 2, 2, 3], k = 3
 *
 * Initial array: [3, 1, 4, 2, 2, 3]
 * After sort:     [1, 2, 2, 3, 3, 4]
 *
 * i = 0: arr[0] = 1 (!= -1)
 *   curr = 1, count = 0
 *   j = 0: arr[0] == 1 → mark -1, curr = 2, count = 1
 *   j = 1: arr[1] == 2 → mark -1, curr = 3, count = 2
 *   j = 2: arr[2] == 2 (≠ 3) skip
 *   j = 3: arr[3] == 3 → mark -1, curr = 4, count = 3 → group formed [1,2,3]
 *
 * i = 1: arr[1] == -1 skip
 * i = 2: arr[2] = 2 (!= -1)
 *   curr = 2, count = 0
 *   j = 2: arr[2] == 2 → mark -1, curr = 3, count = 1
 *   j = 3: arr[3] == -1 skip
 *   j = 4: arr[4] == 3 → mark -1, curr = 4, count = 2
 *   j = 5: arr[5] == 4 → mark -1, curr = 5, count = 3 → group formed [2,3,4]
 *
 * i = 3,4,5: all == -1 skip
 *
 * All balls grouped successfully → return true
 */

