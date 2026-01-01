#include <bits/stdc++.h>
using namespace std;
void subset(vector<int> &nums, vector<int> &subs, int i)
{
    if (i == nums.size())
    {
        bool isvalid = true;
        for (int i = 0; i < subs.size(); i++)
        {
            if (i + 1 < subs.size() && subs[i + 1] % subs[i] != 0)
            {
                isvalid = false;
                break;
            }
        }
        if (!isvalid)
        {
            for (int i = subs.size() - 1; i >= 0; i--)
            {
                if (i + 1 < subs.size() && subs[i] % subs[i + 1] != 0)
                {
                    isvalid = false;
                    break;
                }
            }
        }
        if (isvalid)
        {
            for (int i = 0; i < subs.size(); i++)
            {
                cout << subs[i] << " ";
            }
            cout << endl;
            exit(1);
        }

      return;
    }
    subs.push_back(nums[i]);
    subset(nums, subs, i + 1);

    subs.pop_back();
    subset(nums, subs, i + 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> subs;
    subset(nums, subs, 0);
    return 0;
}