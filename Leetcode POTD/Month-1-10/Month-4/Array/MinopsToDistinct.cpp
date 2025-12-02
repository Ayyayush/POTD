#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2) approx (n iterations * insertions in unordered_set each time)
    // Space Complexity: O(n) for storing set

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    bool isunique = false;
    long long count = 0;

    while (!isunique)                         // jab tak saare elements unique nahi ho jaate
    {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) st.insert(nums[i]);   // vector ke elements ko set mein daal rahe

        if (st.size() == nums.size())         // agar size same hai to unique elements hain
        {
            cout << count << endl;
            isunique = true;
            return;
        }
        else
        {
            if (nums.size() >= 3) nums.erase(nums.begin(), nums.begin() + 3);         // 3 elements hatao
            else nums.erase(nums.begin(), nums.begin() + nums.size());               // agar kam bache ho toh sab hata do

            count++;                         // erase count badha do
        }
    }

    cout << count << endl;
}

void better()
{
    // Time Complexity: O(n log n) due to sorting
    // Space Complexity: O(1)

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    long long count = 0;

    while (true)
    {
        vector<int> temp = nums;                     // vector ka copy le liya sort karne ke liye
        sort(temp.begin(), temp.end());

        bool isunique = true;
        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] == temp[i - 1])              // agar koi duplicate mila to unique nahi hai
            {
                isunique = false;
                break;
            }
        }

        if (isunique)
        {
            cout << count << endl;
            return;
        }
        else
        {
            if (nums.size() >= 3) nums.erase(nums.begin(), nums.begin() + 3);
            else nums.erase(nums.begin(), nums.begin() + nums.size());
            count++;
        }
    }
}

void optimal()
{
    // Time Complexity: O(n) average, due to unordered_set
    // Space Complexity: O(n)

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_map<int, int> freq;                    // har element ka frequency track karne ke liye
    for (int i = 0; i < n; i++) freq[nums[i]]++;

    long long count = 0;
    int i = 0;

    while (true)
    {
        bool isunique = true;
        for (auto it : freq)
        {
            if (it.second > 1)                       // agar koi element 1 se zyada baar aa raha hai
            {
                isunique = false;
                break;
            }
        }

        if (isunique)
        {
            cout << count << endl;
            return;
        }

        // ab 3 elements hatao map se
        for (int j = 0; j < 3 && i < n; j++, i++)
        {
            freq[nums[i]]--;
            if (freq[nums[i]] == 0) freq.erase(nums[i]);     // agar frequency 0 ho gayi to erase karo
        }

        count++;
    }
}

int main()
{
    // brute();      // Uncomment to test brute
    // better();     // Uncomment to test better
    optimal();       // Use optimal by default
    return 0;
}
