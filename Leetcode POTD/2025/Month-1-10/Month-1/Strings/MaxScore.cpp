

#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int i,j,k,count1,count0,maxscore=0;
    string s;
    getline(cin, s);                
    int n = s.size();                 

    vector<int> arr(n);

    // Convert string characters to numeric array
    for ( i = 0; i < n; i++) {
        arr[i] = s[i] - '0'; // Convert char to int
    }



     for(i=0;i<arr.size()-1;i++)
    {
        count1=0,count0=0;
        for(k=0;k<=i;k++)
        {
            if(arr[k]==0)
            count0++;
        }
        for(k=i+1;k<arr.size();k++)
        {
            if(arr[k]==1)
            {
                count1++;
            }
        }

        maxscore=max((count1+count0), maxscore);
    }
    cout<<maxscore<<endl;
    cout << endl;
}

int main()
{
    brute();
    return 0;
}
