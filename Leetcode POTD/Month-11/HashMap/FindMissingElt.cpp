#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// 🧠 Approach 1: Brute Force (Using find() function)
// T.C. = O((max - min) * N)          --> har element ke liye linear search
// S.C. = O(1)                        --> koi extra space nahi use kiya
//////////////////////////////////////////////////////////////
void brute()
{
    vector<int> nums = {4, 2, 9, 6};                          // Input array
    vector<int> ans;                                          // Missing elements store karne ke liye
    
    int minVal = *min_element(nums.begin(), nums.end());      // Minimum element
    int maxVal = *max_element(nums.begin(), nums.end());      // Maximum element

    for (int i = minVal + 1; i < maxVal; i++) {               // Min aur max ke beech ke numbers traverse
        if (find(nums.begin(), nums.end(), i) == nums.end())  // Agar number array mein nahi mila
            ans.push_back(i);                                 // To wo missing element hai
    }

    cout << "Brute: ";
    for (int x : ans) cout << x << " ";                       // Missing elements print karte hain
    cout << endl;
}

//////////////////////////////////////////////////////////////
// 🧠 Approach 2: Better (Using unordered_map)
// T.C. = O(N + (max - min))            --> map build + range check
// S.C. = O(N)                          --> map ke liye extra space
//////////////////////////////////////////////////////////////
void better()
{
    vector<int> nums = {4, 2, 9, 6};
    vector<int> ans;
    
    int minVal = *min_element(nums.begin(), nums.end());      // Minimum element
    int maxVal = *max_element(nums.begin(), nums.end());      // Maximum element
    
    unordered_map<int, int> mp;                               // Presence map
    for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;      // Elements mark kar do
    
    for (int i = minVal + 1; i < maxVal; i++) {               // Range traverse karte hain
        if (!mp.count(i)) ans.push_back(i);                   // Agar element missing hai
    }

    cout << "Better: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}

//////////////////////////////////////////////////////////////
// 🧠 Approach 3: Optimal (Using Sorting + Adjacent Difference)
// T.C. = O(N log N)                   --> sorting + linear traversal
// S.C. = O(1)                         --> sirf answer vector extra
//////////////////////////////////////////////////////////////
void optimal()
{
    vector<int> nums = {4, 2, 9, 6};
    vector<int> ans;
    
    sort(nums.begin(), nums.end());                           // Array sort karte hain
    for (int i = 1; i < nums.size(); i++) {                   // Adjacent pairs compare karte hain
        if (nums[i] - nums[i - 1] > 1) {                      // Agar gap > 1 hai to missing elements hain
            for (int j = nums[i - 1] + 1; j < nums[i]; j++)   // Gap ke beech ke sab add kar do
                ans.push_back(j);
        }
    }

    cout << "Optimal: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}
