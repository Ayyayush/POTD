#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n,prod,z=0,count=0,index=0;
    cin>>n;
    vector<int>nums(n);
    vector<int>addend;
    vector<int>result;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    string str;
    while(count<n && cin>>str )
    {
        count++;
        if(str=="add")
        {
            addend.push_back(nums[z]);
            result.push_back('\0');
            z++;
           
        }
        else if(str=="getproduct")
        {
            prod=1;
            int k=nums[z];
            int startIdx = max(0, (int)addend.size() - k);   // Yeh ensure karega ki negative index nahi ho
        for (int i = addend.size() - 1; i >= startIdx; i--) 
            {
                prod*=addend[i];
            }
            z++;
            result.push_back(prod);

        }
        else
        {
            break;
        }

    }
    for(auto x:result)
    cout<<x<<" ";

    cout<<endl;
}
int main()
{
brute();
return 0;
}