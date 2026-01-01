#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int minK, maxK, minelt, maxelt, count = 0;
    cin >> minK >> maxK;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> vec;
        for (int j = i; j < nums.size(); j++)
        {
            vec.push_back(nums[j]);
            minelt = *min_element(vec.begin(), vec.end());
            maxelt = *max_element(vec.begin(), vec.end());
            if (minelt == minK && maxelt == maxK)
                count++;
        }
    }
    cout << count << endl;
}



void better()
{
    int n, minK, maxK;
    cin >> n >> minK >> maxK; // Input size aur range values

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array input lo
    }

    long long ans = 0;
    int minkposition = -1, maxkposition = -1, culpritidx = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < minK || nums[i] > maxK)
        {                   // Agar current number range ke bahar hai
            culpritidx = i; // Culprit position update karo
        }

        if (nums[i] == minK)
        {                     // Agar current number minK ke equal hai
            minkposition = i; // minK ka position update karo
        }

        if (nums[i] == maxK)
        {                     // Agar current number maxK ke equal hai
            maxkposition = i; // maxK ka position update karo
        }

        long long smaller = min(minkposition, maxkposition); // Minimum index dono mein se
        long long temp = smaller - culpritidx;               // Calculate temporary valid subarray count

        ans += (temp <= 0) ? 0 : temp; // Agar temp negative ya zero ho toh count add mat karo
    }

    cout << ans << endl; // Final answer print karo
}

int main()
{
    better(); // Call the function
    return 0;
}
