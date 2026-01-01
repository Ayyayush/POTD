#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2)
    // Kyuki har subarray ke liye loop chala rahe hain (i to j), toh nested loops O(n^2)
    // Space Complexity: O(n) for the input array

    int n;
    cin >> n;                                       // Input size of array

    vector<int> nums(n);                            // Array declaration
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];                             // Input array elements
    }

    int modulo, k, subcount = 0;
    cin >> modulo >> k;                             // Input for modulo and k

    // Brute force approach: Check every subarray
    for(int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;                                // Count of elements satisfying condition in current subarray

        for(int j = i; j < nums.size(); j++)
        {
            if(nums[j] % modulo == k)               // Agar current element condition satisfy karta hai
            {
                cnt++;                              // Toh uska count badha do
            }

            if(cnt % modulo == k)                   // Agar count bhi condition satisfy karta hai
            {
                subcount++;                         // Toh valid subarray count badha do
            }
        }
    }

    cout << subcount << endl;                       // Print final count
}


void brute()
{
    // Time Complexity: O(n)                  // Kyunki hum ek baar hi poora array loop kar rahe hain
    // Space Complexity: O(n)                 // Map mein maximum n different remainders store ho sakte hain

    int n, m, k;
    cin >> n;                                 // Array ka size

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];                       // Array input
    }

    cin >> m >> k;                            // Modulo aur target value k input

    unordered_map<int, long long> mp;         // Map to store count of prefix sum remainders
    long long sum = 0;                        // Sum ka matlab: ab tak kitne elements hain jinke nums[i] % m == k
    long long result = 0;                     // Final answer

    mp[0] = 1;                                // Prefix sum 0 ke liye ek base case daal diya

    for(int i = 0; i < n; i++) {
        if(nums[i] % m == k) {
            sum += 1;                         // Agar current element valid hai, toh sum badha do
        }

        int r1 = sum % m;                     // Current prefix sum ka remainder
        int r2 = (r1 - k + m) % m;            // Required remainder jisse match karne par valid subarray mile

        result += mp[r2];                     // Jitni baar r2 pehle aaya, utne valid subarrays ban sakte hain
        mp[r1]++;                             // Current r1 ko map mein store/update karo
    }

    cout << result << endl;                   // Final count of interesting subarrays print karo
}

int main()
{
    brute();
    return 0;
}
