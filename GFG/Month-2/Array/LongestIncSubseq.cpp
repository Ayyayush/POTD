#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n, maxcount = -1, count;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        count = 1;
        int number=nums[i];
        for (int j = i+1; j < nums.size(); j++)
        {
            if ( i+1<nums.size() && nums[j]>number)
            {
                cout<<nums[j]<<" ";
                count++;
                number=nums[j];
                maxcount = max(count, maxcount);
            }
            cout<<endl;
           
        }
    }
    cout << maxcount << endl;
}
int main()
{
    brute();
    return 0;
}