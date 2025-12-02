#include <bits/stdc++.h>
using namespace std;





void brute()       // T.C = O(N²)        .......Fail karega for N = 10^5   
{
    int count = 0, n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++)  
    {
        cin >> nums[i];
    }

    for (int i = 0; i < nums.size(); i++)   
    {
        for (int j = i; j < nums.size(); j++)    
        {
            if (j - i != nums[j] - nums[i])       // Check kar raha hai ki subarray ka index difference aur value difference same hai ya nahi    
            {
                count++;                         // Agar condition satisfy nahi ho rahi toh count badh jayega    
            }
        }
    }

    cout << count << endl;                      // Total count print karna hai    
}





void alternative()       // T.C = O(N log N)    ........Two Pointers + Sorting  ...par isse answer yha sahi nhi aayega
{
    int count = 0, n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++)    
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());       // Sorting kar rahe hain taki Two Pointers apply kar sakein    (O(N log N))    

    int left = 0, right = 0;    

    while (right < n)    
    {
        if (right - left == nums[right] - nums[left])       // Condition check kar rahe hain ki index difference aur value difference same hai ya nahi    
        {
            right++;                                      // Agar same hai toh right pointer badh jayega    
        }
        else   
        {
            count += (right - left);                     // Agar condition satisfy nahi ho rahi toh valid subarrays count me add karenge    
            left++;                                       // Left pointer aage badh jayega    
        }
    }

    cout << count << endl;                               // Final count print karna hai    
}


void optimal()
{
    // Time Complexity: O(N)          // Har element ek hi baar traverse ho raha hai
    // Space Complexity: O(N)         // Unordered_map use ho raha hai jo maximum N size le sakta hai

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long result = 0;

    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] - i;
    }

    unordered_map<int, int> mp;
    mp[nums[0]] = 1;

    for (int j = 1; j < n; j++)
    {
        int countOfNumsj = mp[nums[j]];          // nums[j] ka frequency map mein check kar rahe hain

        int totalNumsBeforej = j;                // Current index tak total elements count

        int badPairs = totalNumsBeforej - countOfNumsj;   // Good pairs ko total se subtract kar diya

        result += badPairs;                      // Final result mein bad pairs add kar rahe hain

        mp[nums[j]]++;                           // nums[j] ki frequency badha rahe hain
    }

    cout << result << endl;
}


int main()
{
    return 0;
}
