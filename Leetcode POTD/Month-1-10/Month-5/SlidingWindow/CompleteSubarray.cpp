#include <bits/stdc++.h>
using namespace std;

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