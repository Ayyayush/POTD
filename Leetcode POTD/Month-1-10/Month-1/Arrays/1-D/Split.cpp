#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int s;
    cin>>s;
    int i,j,sum1=0,sum2=0,maxsum=0,count=0;
    vector<int>nums(s);
    for(i=0;i<s;i++)
    {
        cin>>nums[i];
    }

    for(i=0;i<nums.size();i++)
    {
        sum1=sum1+nums[i];
        sum2=0;
        for(j=i+1;j<nums.size();j++)
        {
            sum2=sum2+nums[j];
            
        }
        if(sum1>=sum2)
        ++count;
    
    }
    cout<<count-1<<endl;
}



void better()

{
 int s;
    cin>>s;
    int i,j,sum1=0,sum2=0,sum=0,maxsum=0,count=0;
    vector<int>nums(s);
    for(i=0;i<s;i++)
    {
        cin>>nums[i];
    }
 sum=accumulate(nums.begin(),nums.end(),0);
    for(i=0;i<nums.size()-1;i++)
    {
       
        sum1=sum1+nums[i];
        sum2=abs(sum-sum1);

        if(sum1>=sum2)
        ++count;
    
    }
    cout<<count<<endl;

}


void optimal()
{

 long long s;
    cin>>s;
    long long i,j,sum1=0,sum2=0,sum=0,maxsum=0,count=0;
    vector<long long>nums(s);
    for(i=0;i<s;i++)
    {
        cin>>nums[i];
    }
 sum=accumulate(nums.begin(),nums.end(),0);
    for(i=0;i<nums.size()-1;i++)
    {
       
        sum1=sum1+nums[i];
        sum2=abs(sum-sum1);

        if(sum1>=sum2)
        ++count;
    
    }
    cout<<count<<endl;

}

int main()
{
better();
return 0;
}