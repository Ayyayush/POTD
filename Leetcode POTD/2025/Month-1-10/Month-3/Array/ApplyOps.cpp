#include <bits/stdc++.h>
using namespace std;
void brute()   //O(N)
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i=0;i<nums.size();i++)          //  O(N)
    {
        if(i+1<nums.size() && (nums[i]==nums[i+1]))
        {
            nums[i]=nums[i]*2;
            nums[i+1]=0;
            
        }
        
    }
    int count=0;
    for(int i=0;i<nums.size();i++)      //O(N)
    {
        if(nums[i]==0)
        {
            count++;
        nums.erase(nums.begin()+i);
        i=-1;
        }
    }
    for(int i=0;i<count;i++)    //O(N/2);
    {
        nums.push_back(0);
    }

    for(auto x:nums)
    cout<<x<<" ";

    cout<<endl;

}


void better()
{
    
}
int main()
{
brute();
return 0;
}