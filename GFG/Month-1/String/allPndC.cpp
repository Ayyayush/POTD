#include <bits/stdc++.h>
using namespace std;
void brute()
{
    string s;
    getline(cin,s);
        vector<string> permutations;

    sort(s.begin(),s.end());

    do
    {
        permutations.push_back(s);
    }
    while(next_permutation(s.begin(),s.end()));
       

   for(int i=0;i<permutations.size();i++)
   {
    cout<<permutations[i]<<" ";
   }

}
int main()
{
brute();
return 0;
}