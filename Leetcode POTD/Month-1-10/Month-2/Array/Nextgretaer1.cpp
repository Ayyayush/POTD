#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int i,j,n,m;
    cin>>n>>m;
    vector<int>nums1(n);
    vector<int>nums2(m);

     for(i=0;i<n;i++)
    {
        cin>>nums1[i];
    }
    for(j=0;j<m;j++)
    {
        cin>>nums2[j];
    }

     
    for(i=0;i<n;i++)
    {
        int count=0;
        auto it=find(nums2.begin(),nums2.end(),nums1[i]);
        if(it!=nums2.end())
        {
        int index=distance(nums2.begin(),it);
        for(j=index;j<m;j++)
        {
            if(nums2[j]>nums1[i])
            {
                count++;
                nums1[i]=nums2[j];
                break;
            }
             }
             if(count==0)
                nums1[i]=-1;
        }
        else
        {
             nums1[i]=-1;
        }
            
       
    }
          for(i=0;i<n;i++)
    {
        cout<<nums1[i]<<" ";
    }
   

}


void better()
{
     int s, i, j;
    cin >> s;
    vector<int> span(s);
    vector<int> stock;
    stack<int> st;
    st.push(0); // 0th index ke liye span ki value one hi hogi
    for (i = 0; i < s; i++)
    {
        cin >> span[i];
    }

   
    for (i = 1; i < span.size(); i++)
    {
        int currprice = span[i];

        // Pichle bade prices ko pop karo jab tak chhota mile
        while (!st.empty() && currprice >= span[st.top()])
        {
            st.pop();
        }

        if (st.empty()) // Agar stack empty ho gaya, iska matlab koi bada price pichle dinon mein nahi hai
        {
            stock.push_back(i + 1); // Pure i+1 din ka span hoga
        }
        else // Agar stack empty nahi hai, toh current price ka span calculate karo
        {
            int prevhigh = st.top();
            stock.push_back(i - prevhigh); // Difference between current index and previous higher price
        }



      for (auto x : stock) 
    {
        cout << x << " ";
    }
}

}




int main()
{
    brute();
    return 0;
}