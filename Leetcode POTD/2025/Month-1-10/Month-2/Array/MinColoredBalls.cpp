#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int limit,maxcolor= 0,n;
    cin>>limit>>n;
    vector<pair<int,int>>queries(n,make_pair(0,0));
   // vector<int>vec(limit+1);
    for(int i=0;i<n;i++)
    {
        cin>>queries[i].first>>queries[i].second;
      //  vec[queries[i].first].push_back(queries[i].second);
    }

    for(int i=0;i<n;i++)
    {
        int curr=queries[i].first;
        maxcolor=max(curr,maxcolor);
        cout<<maxcolor<<" ";
    }

}
int main()
{
brute();
return 0;
}