#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2 * log(n)) because of nested loops and set operations
    // Space Complexity: O(n) for using sets

    vector<int> nums = {1, 3, 1, 2, 2}; // Example input le liya yaha pe

    set<int> st; // Unique elements ka set bna rahe hai original array ke liye
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]); // unique elements daal diye set me
    }

    int count = 0; // final answer yeh store karega

    for (int i = 0; i < nums.size(); i++)
    {
        set<int> st2; // har i ke liye naya set bana rahe hai
        for (int j = i; j < nums.size(); j++)
        {
            st2.insert(nums[j]); // subarray [i...j] ka set bna rahe hai
            if (st2.size() == st.size())
            {
                count++; // agar same number of unique elements hai to count badhao
            }
        }
    }

    cout << "Total complete subarrays = " << count << endl; // output print kar diya
}



void better()
{
    // Time Complexity: O(n^2)      // do nested loop lag rahe hai
    // Space Complexity: O(n)       // 2 unordered_sets use ho rahe hai

    vector<int> nums = {1, 3, 1, 2, 2};     // Example input

    unordered_set<int> st;     // original array ke unique elements store karne ke liye

    for (int i = 0; i < nums.size(); i++) {
        st.insert(nums[i]);     // har unique element ko daal diya
    }

    int count = 0;     // final count yaha store hoga

    for (int i = 0; i < nums.size(); i++) {
        unordered_set<int> st2;     // har i ke liye naya set banana hoga
        for (int j = i; j < nums.size(); j++) {
            st2.insert(nums[j]);     // current subarray ka element daal rahe hai
            if (st2.size() == st.size()) {
                count++;     // agar unique elements ka size match ho gaya to count++
            }
        }
    }

    cout << "Total complete subarrays = " << count << endl;     // final output print
}

void optimal()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> mp;
    unordered_set<int> st(nums.begin(), nums.end());
    int count = 0;

    int i = 0, j = 0;
    while (j < nums.size())
    {
        mp[nums[j]]++;
        while(mp.size() == st.size())
        {
            count += (nums.size() - j);
            mp[nums[i]]--;

            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);

            i++;
        }

        j++;
    }

    cout << count << endl;
}

int main()
{
    optimal();
    return 0;
}