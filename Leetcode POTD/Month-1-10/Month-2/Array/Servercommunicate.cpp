#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int i,j,m,n,s,count=0;
    cin>>m>>n;
   int nums[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>nums[i][j];
        }
    }

     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           if((nums[i][j]==1 && nums[i+1][j]==1) || (nums[i][j]==1 && nums[i][j+1]==1))
           {
              count+=2;
           }
        }
    }

    cout<<count<<endl;


}

void better()
{

}
int main()
{
brute();
return 0;
}