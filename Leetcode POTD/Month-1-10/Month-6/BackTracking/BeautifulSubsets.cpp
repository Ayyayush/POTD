#include <bits/stdc++.h>
using namespace std;

bool beautiful(vector<int> &sub, int k)
{
    for (int i = 0; i < sub.size(); i++)
    {
        for (int j = 0; j < sub.size(); j++)   // 🔁 Fixed here
        {
            if (abs(sub[i] - sub[j]) == k)
            {
                return false;
            }
        }
    }
    return true;
}

void subsets(vector<int> &nums, vector<int> &sub, int idx, int &count, int k)
{
    if (idx == nums.size())
    {
        if (beautiful(sub, k))
            count++;
        return;                              // ✅ Added return
    }

    sub.push_back(nums[idx]);
    subsets(nums, sub, idx + 1, count, k);

    sub.pop_back();
    subsets(nums, sub, idx + 1, count, k);
}

int main()
{
    int k;
    cin >> k;
    vector<int> nums = {1};
    vector<int> sub;
    int count = 0;
    subsets(nums, sub, 0, count, k);
    cout << count << endl;
    return 0;
}