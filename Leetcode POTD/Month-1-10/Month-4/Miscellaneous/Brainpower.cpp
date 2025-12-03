#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    int maxsum ;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];

    long long maximum = -1;
    if (n <= 3)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][0] > maximum)
                maximum = nums[i][0];
        }
        cout << maximum << endl;
        return;
    }
    else
    {
        maxsum=-1;
        int sum=0;
      
        for (int i = 0; i < nums.size(); i++)
        {
             sum = nums[i][0];
            for (int j = i + 1 + nums[i][1]; j < nums[0].size(); j++)
            {
                sum += nums[j][0];
                maxsum = max(maxsum, sum);
            }
        }
    }
    cout << maxsum << endl;
}
int main()
{
    brute();
    return 0;
}