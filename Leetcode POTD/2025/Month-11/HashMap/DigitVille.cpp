#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// 🧠 Approach 1: Brute Force (Using Boolean Array)
// T.C. = O(N)                      --> har element ko ek baar traverse kar rahe hain
// S.C. = O(N)                      --> seen array ke liye extra space
//////////////////////////////////////////////////////////////
void brute()
{
    vector<int> nums = {1, 3, 2, 3, 4, 1};                  // Input array
    int n = nums.size();                                    // Array ka size
    vector<bool> seen(n, false);                            // Boolean array for marking seen elements
    vector<int> res;                                        // Duplicate elements store karne ke liye

    for (int i = 0; i < n; i++) {
        if (seen[nums[i]])                                  // Agar element pehle se seen hai
            res.push_back(nums[i]);                         // To wo duplicate hai
        else
            seen[nums[i]] = true;                           // Otherwise mark as seen
    }

    cout << "Brute: ";
    for (int x : res) cout << x << " ";                     // Output print karte hain
    cout << endl;
}

//////////////////////////////////////////////////////////////
// 🧠 Approach 2: Better (Using Hashmap / unordered_map)
// T.C. = O(N)                      --> single pass for frequency count
// S.C. = O(N)                      --> map ke liye extra space
//////////////////////////////////////////////////////////////
void better()
{
    vector<int> nums = {1, 3, 2, 3, 4, 1};
    int n = nums.size();
    unordered_map<int, int> mp;                             // Frequency map

    for (int i = 0; i < n; i++)
        mp[nums[i]]++;                                      // Har element ki frequency count karo

    vector<int> res;
    for (auto x : mp) {
        if (x.second == 2)                                  // Agar element 2 baar aya hai
            res.push_back(x.first);                         // To wo sneaky number hai
    }

    cout << "Better: ";
    for (int x : res) cout << x << " ";
    cout << endl;
}

int main()
{
    brute();
    better();
    return 0;
}
