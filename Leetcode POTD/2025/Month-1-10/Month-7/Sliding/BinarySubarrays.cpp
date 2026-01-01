#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. => O(N^2)                     // 2 nested loops mein subarrays check ho rahe hain
    // S.C. => O(1)                        // koi extra space nahi lag raha

    int n;                                // array ka size
    cin >> n;

    vector<int> nums(n);                  // array bana liya
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int goal;                             // target sum
    cin >> goal;

    int count = 0;                        // answer store karne ke liye

    for (int i = 0; i < nums.size(); i++)
    {
        long long sum = 0;                // subarray ka sum
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];               // sum update karo
            if (sum == goal)              // agar goal mila toh count badhao
                count++;
        }
    }

    cout << count << endl;                // answer print karo
}

void better()
{
    // T.C. => O(N)                      // ek hi loop mein prefix sum + map update ho raha hai
    // S.C. => O(N)                      // prefix sum ke liye unordered_map ban raha hai

    int n;                               // array size
    cin >> n;

    vector<int> nums(n);                 // array
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int goal;                            // target sum
    cin >> goal;

    unordered_map<int, int> mp;          // prefix sum frequency map
    mp[0] = 1;                           // base case: prefix sum = 0 ka ek count

    int sum = 0, count = 0;              // sum -> prefix sum, count -> answer

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];                  // prefix sum banta ja raha hai
        int req = sum - goal;            // kitna chahiye pehle ka sum

        if (mp.count(req))               // agar required sum mila toh answer mein add karo
        {
            count += mp[req];
        }

        mp[sum]++;                       // current prefix sum ki frequency badhao
    }

    cout << count << endl;               // final answer print karo
}



void optimal()
{
    // T.C. => O(N)                       // har element max ek baar right aur left pointer se process hota hai
    // S.C. => O(1)                       // koi extra space nahi, bas variables

    int n;                                // array ka size
    cin >> n;

    vector<int> nums(n);                  // array
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int goal;                             // target sum
    cin >> goal;

    int prefix_zeros = 0;                 // kitne leading zeros hai window mein
    int window_sum = 0;                   // current window ka sum
    int count = 0;                        // answer

    int i = 0, j = 0;                     // window pointers

    while (j < nums.size())
    {
        window_sum += nums[j];            // right pointer se add karo

        // window adjust karo agar goal se bada ya left zero ho
        while (i < j && (nums[i] == 0 || window_sum > goal))
        {
            if (nums[i] == 1)
                prefix_zeros = 0;         // agar left end pe 1 hai toh zeros reset karo
            else
                prefix_zeros += 1;        // agar zero mila toh count badhao

            window_sum -= nums[i];        // left pointer se remove karo
            i++;
        }

        // agar goal mila toh answer update karo
        if (window_sum == goal)
        {
            count += 1 + prefix_zeros;    // prefix zeros bhi valid hoti hai
        }

        j++;                              // right pointer aage badhao
    }

    cout << count << endl;                // answer print karo
}

int main()
{
    optimal();
    return 0;
}
