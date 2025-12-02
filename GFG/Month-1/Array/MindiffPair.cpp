#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s;
    cin>>s;
    vector<int>arr(s);
    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }
      int mindiff=INT_MAX,diff=0;
        
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++)
        {
            diff=abs(arr[i]-arr[i+1]);
            mindiff=min(diff,mindiff);
        }
       cout<<mindiff<<endl;
       return 0;
      
}