#include <bits/stdc++.h>
using namespace std;

void brute()                                                                                 
{
    vector<int> a = {1, 1, 2, 2, 3, 3, 4};           // Example input
    int target = 7;
    int n = a.size();
    long long count = 0;

    for(int i = 0; i < n - 2; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(a[i] + a[j] + a[k] == target)
                    count++;                        // agar teenon ka sum target ke equal hai to count++
            }
        }
    }

    cout << "Brute: " << count << endl;
}



void better()                                                                                 
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};    // Example input
    int target = 8;
    int n = arr.size();
    const int Mod = 1e9 + 7;

    long long count = 0;
    unordered_map<int, long long> pairSumFreq;          // Stores freq of pair sums (arr[i] + arr[j])

    for (int k = 0; k < n; ++k)
    {
        count = (count + pairSumFreq[target - arr[k]]) % Mod;   // Check if complement pair exists

        for (int j = 0; j < k; ++j)
        {
            int sum = arr[j] + arr[k];                  // form all (i, k) pairs where i < k
            pairSumFreq[sum]++;                         // store their sum
        }
    }

    cout << "Better: " << count << endl;
}




void optimal()                                                                                 
{
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};       // Example input
    int target = 8;
    const int MOD = 1e9 + 7;
    int n = arr.size();
    sort(arr.begin(), arr.end());                 // Sorting is must for 2-pointer logic

    long long count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int t = target - arr[i];                  // Now find two numbers such that sum = t
        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = arr[j] + arr[k];
            if (sum < t)
                j++;
            else if (sum > t)
                k--;
            else
            {
                // arr[i] + arr[j] + arr[k] == target
                if (arr[j] != arr[k])
                {
                    int left = 1, right = 1;
                    while (j + 1 < k && arr[j] == arr[j + 1]) { left++; j++; }
                    while (k - 1 > j && arr[k] == arr[k - 1]) { right++; k--; }

                    count = (count + (long long)left * right) % MOD;
                    j++; k--;
                }
                else
                {
                    // arr[j] == arr[k] → choose 2 out of (k-j+1) → C(n, 2)
                    int len = k - j + 1;
                    count = (count + (long long)(len) * (len - 1) / 2) % MOD;
                    break;
                }
            }
        }
    }

    cout << "Optimal: " << count << endl;
}


int main()
{
    better();
    return 0;
}
