#include <bits/stdc++.h>
using namespace std;
void brute()       //O(N^32);
{
    int index, n,k;
    long double eucledian, minimum = INT_MAX;
    cin >> n;
    cin>>k;
    vector<pair<int, int>> nums(n, make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].first >> nums[i].second;
    }

        for (int j = 0 ; j < n; j++)
        {

                    eucledian = sqrt(((nums[j].first - 0) * (nums[j].first - 0)) + ((nums[j].second - 0) * (nums[j].second-0))) ;
                if (eucledian < minimum)
                {
                   
                    index = j;
                    minimum = eucledian;
                }
            }
        
    // ISME pair mein eucledian aur j ki value bhejo
    // firr uss pair ko sort karo
    // firr loop chala ke k tak ki values vector mein store kr do 
    // firr uss vector ko return kar do 

    
  
}


void better()      //O(N)
{
    int index, n,k;
    long double eucledian, minimum = INT_MAX;
    cin >> n;
    cin>>k;
    vector<pair<int, int>> nums(n, make_pair(0, 0));
    map<double,int>m;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].first >> nums[i].second;
    }

        for (int j = 0 ; j < n; j++)
        {

                    eucledian = sqrt(((nums[j].first - 0) * (nums[j].first - 0)) + ((nums[j].second - 0) * (nums[j].second-0))) ;
                     m.emplace(eucledian,j);
        }  

        auto it = m.begin(); // Iterator use karna padega kyunki `map` ka indexing `[]` se nahi hota

        for (int i = 0; i < k && it != m.end(); i++, it++) {  
            cout << nums[it->second].first << " " << nums[it->second].second << endl;
        }
        
     
}
int main()
{
    better();
    return 0;
}
