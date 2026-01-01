#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N log N) + O(N log N) + O(P) ≈ O(N log N)
    // Space Complexity: O(N)                           // diff vector ke liye

    vector<int> nums = {1, 3, 6, 19};         // Example input
    int p = 2;                                // Kitne pairs banane hain

    sort(nums.begin(), nums.end());           // Pehle input ko sort karo

    vector<int> diff;                         // Ye vector consecutive differences store karega

    for (int i = 0; i < nums.size() - 1; i++) 
    {
        diff.push_back(abs(nums[i] - nums[i + 1]));  // Consecutive element ka diff calculate karo aur store karo
    }

    sort(diff.begin(), diff.end());           // Sab diffs ko sort karo taki smallest differences pehle milein

    int maximum = 0;                          // Answer store karne ke liye

    for (int i = 0; i < p; i++) 
    {
        maximum = max(maximum, diff[i]);      // Pehle p smallest differences mein se maximum nikalo
    }

    cout << maximum << endl;                  // Final answer print karo
}


void better()
{
    // Ye placeholder hai:
    // Recursion ya backtracking se saare possible p pairs bana sakte ho
    // Aur unmein se minimum maximum difference wala answer choose kar sakte ho
    // Par ye feasible nahi hai large constraints ke liye
    // Isliye better se bhi directly optimal pe hi jaate hain.
}



bool isvalid(vector<int>& nums, int mid, int p) 
{
    // Ye function check karta hai ki current mid ke saath 
    // at least p pairs bana pa rahe ho ya nahi

    int n = nums.size();
    int i = 0, countpairs = 0;

    while (i < n - 1) 
    {
        // Agar current pair ka diff mid se kam ya barabar hai to pair banao
        if (abs(nums[i] - nums[i + 1]) <= mid) 
        {
            countpairs++;        // pair ban gaya
            i += 2;              // dono elements ko skip karo
        } 
        else 
        {
            i++;                 // warna agla element check karo
        }
    }

    return countpairs >= p;      // Agar required pairs ban gaye to true
}



void optimal()
{
    // Time Complexity: O(N log N) + O(N log M)
    // Space Complexity: O(1) extra, sorting ke liye O(N)

    int n, p;
    cin >> n >> p;                          // Array size aur pairs input lo

    vector<int> nums(n);                    // Array declare karo
    for (int i = 0; i < n; i++) cin >> nums[i];    // Elements input lo

    sort(nums.begin(), nums.end());         // Pehle array ko sort karo

    int l = 0, r = nums[n - 1] - nums[0];   // Binary search ke liye range set karo
    int result = r;                         // Answer initially max difference se set karo

    while (l <= r) 
    {
        int mid = l + (r - l) / 2;          // Mid nikalo

        if (isvalid(nums, mid, p)) 
        {
            result = mid;                   // Agar possible hai to answer update karo
            r = mid - 1;                    // Aur chhota answer try karo
        } 
        else 
        {
            l = mid + 1;                    // Nahi ho raha to bada answer try karo
        }
    }

    cout << result << endl;                 // Final minimum maximum difference print karo
}



int main()
{
    optimal();   // Optimal version run karo
    return 0;
}
