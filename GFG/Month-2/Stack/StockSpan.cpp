#include <bits/stdc++.h>
using namespace std;


void brute()
{
    // using nested loops
}


void better()
{
    int n;
    cin >> n;
    vector<int> stock(n);
    vector<int> span(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stock[i];
    }

    vector<int>vec;      //O(N)
    
    for (int i = 0; i < stock.size(); i++)          // O(N)
    {
        int count = 1;
        int k=i-1;
     
        if (vec.empty())
        {
            span[i] = 1;
           
        }
        else
        {
            while(!(vec[k]>stock[i]))
                {
                    k--;
                    count++;
                }

            span[i] = count;
          
        }
        vec.push_back(stock[i]);
    }
   

    for(auto x:span)
    {
        cout<<x<<" ";
    }
}


void optimal()
{

}

int main()
{
    better();
    return 0;
}