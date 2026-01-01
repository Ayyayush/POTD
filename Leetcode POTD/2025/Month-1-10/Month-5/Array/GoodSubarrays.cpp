#include <bits/stdc++.h> // sabhi standard C++ libraries ko include kar raha hai
using namespace std;

void brute() // brute force function start
{
    int n;               // array ka size input ke liye
    cin >> n;            // size input le rahe hain
    vector<int> nums(n); // nums naam ka vector banaya of size n

    for (int i = 0; i < n; i++) // array ke elements input lene ke liye loop
    {
        cin >> nums[i]; // har element input le rahe hain
    }

    int k;    // required minimum pair count
    cin >> k; // k input le rahe hain

    int subarraycount = 0; // valid subarrays count karne ke liye variable

    for (int i = 0; i < nums.size(); i++) // har possible subarray ka starting index
    {
        vector<int> subs; // subarray ko store karne ke liye temporary vector
        int paircount;    // subarray ke andar < type ke pairs count karne ke liye

        for (int j = i; j < nums.size(); j++) // subarray ka ending index
        {
            subs.push_back(nums[j]); // current element subarray me daal rahe hain

            if (subs.size() >= 2) // jab subarray size 2 ya usse zyada ho
            {
                paircount = 0; // pair count ko reset kar rahe hain

                for (int l = 0; l < subs.size(); l++) // pehla element choose karne ke liye loop
                {
                    for (int m = l + 1; m < subs.size(); m++) // doosra element uske baad wale elements me se choose kar rahe
                    {
                        if (m < subs.size() && subs[l] == subs[m]) // agar pehla element chhota ho dusre se
                            paircount++;                           // to valid pair mila, count badhao
                    }
                }

                if (paircount >= k)  // agar pair count required k se zyada ya barabar hai
                    subarraycount++; // to ye subarray valid hai, count badhao
            }
        }
    }

    cout << subarraycount << endl; // final count print kar rahe hain
}




void better()
{
    int n;               // array ka size input ke liye
    cin >> n;            // size input le rahe hain
    vector<int> nums(n); // nums naam ka vector banaya of size n

    for (int i = 0; i < n; i++) // array ke elements input lene ke liye loop
    {
        cin >> nums[i]; // har element input le rahe hain
    }

    int k;
    cin >> k;

    int i = 0, j = 0;
    long long pairs = 0, subarraycount = 0;
    unordered_map<int, int> mp(0);
    while (j < n)
    {
        pairs += mp[nums[j]];
        mp[nums[j]]++;
        while (pairs >= k)
        {
            subarraycount += (n - j);
            mp[nums[i]]--;
            pairs -= mp[nums[i]];
            i++;
        }

        j++;
    }

    cout << subarraycount << endl;
}
int main()
{
    better(); // brute function call kar rahe hain
    return 0; // program end
}
