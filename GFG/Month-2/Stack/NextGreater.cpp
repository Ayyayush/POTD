#include <bits/stdc++.h>
using namespace std;
void brute()
{
    // using nested loops
}
void better()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    stack<int> s;
    vector<int> result(nums.size());
     for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            result[i]=-1;
        }
        else
        {
            if (s.empty())
            {
                result[i]=-1;
            }
            if (s.top() > nums[i])
            {
                result[i]=s.top();
            }
            else
            {
                s.pop();
            }
        }
        s.push(nums[i]);
    }

    for(auto x:result)
    {
        cout<<x<<" ";
    }
}
int main()
{
    better();
    return 0;
}