#include <bits/stdc++.h>
using namespace std;
void brute()
{
    long long n;
    cin>>n;
    vector<int>nums(n);
    for(long long i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    long long countn=0,countp=0,maxcount=-1;
    for(long long i=0;i<nums.size();i++)
    {
        if(nums[i]<0)
        countp++;
        else if(nums[i]>0)
        countn++;

        maxcount=max(countp,countn);
    }

    cout<<maxcount<<endl;
}
int  main()
{
brute();
return 0;
}