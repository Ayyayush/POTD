#include <bits/stdc++.h>
using namespace std;
void brute()         // O(N)+O(3)=O(N)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int count = 0;
    for (int i = 0; i < nums.size() - 2; i++)   // 0(N)
    {
        if (nums[i] == 0)
        {
            count++;
            for (int j = i; j < i+3; j++)           // 0(3)
            {
                if (nums[j] == 0)
                    nums[j] = 1;
                else
                    nums[j] = 0;
            }
        }
       
    }

    for(auto x:nums)
    cout<<x<<" ";
    cout<<endl;
    auto it = find(nums.begin(), nums.end(), 0);
    if (it != nums.end())
        cout << "-1" << endl;
    else
        cout << count << endl;
}
int main()
{
    brute();
    return 0;
}