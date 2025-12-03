#include <bits/stdc++.h>
using namespace std;
void brute()             //O(N*K)
{
    string blocks;
    getline(cin,blocks);
    int k,count,maxcount=INT_MIN;
    cin>>k;
    string subs="";
    for(int i=0;i<k;i++)         // O(K)
    subs+='B';

    if((blocks.find(subs)!=string::npos) || blocks.size()<k)
    {
        cout<<"0"<<endl;
        return ;
    }
    for(int i=0; i<blocks.size();i++)          // O(N)
    {
         count=0;
        for(int j=i;j<i+k;j++)               //O(K)
        {
            if(j<blocks.size() && blocks[j]=='B')
            count++;
        }
        maxcount=max(count,maxcount);
    }
    

    cout<<k-maxcount<<endl;
}

void better()           //O(N*K)
{
    string blocks;
    getline(cin,blocks);
    int k,count,maxcount=INT_MIN;
    cin>>k;
    string subs="";
    subs.assign(k,'B');
   

    if((blocks.find(subs)!=string::npos) || blocks.size()<k)
    {
        cout<<"0"<<endl;
        return ;
    }
    for(int i=0; i<blocks.size();i++)          // O(N)
    {
         count=0;
        for(int j=i;j<i+k;j++)               //O(K)
        {
            if(j<blocks.size() && blocks[j]=='B')
            count++;
        }
        maxcount=max(count,maxcount);
    }
    

    cout<<k-maxcount<<endl;
}
int main()
{
better();
return 0;
}