#include <bits/stdc++.h>
using namespace std;
void brute()       // O(N^3)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int a,b,c;
    cin>>a>>b>>c;
    long long count=0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)  
        {
            for(int k=j+1;k<arr.size();k++)
            {
                if(k<arr.size() && abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c) 
                {
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    count++;
                }
                
            }
        }
    }

    cout<<endl<<count<<endl;
}


void better()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int a,b,c;
    cin>>a>>b>>c;
    long long count=0;
     
}
int main()
{
brute();
return 0;
}