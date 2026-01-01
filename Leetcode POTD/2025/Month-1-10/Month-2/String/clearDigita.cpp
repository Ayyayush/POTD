#include <bits/stdc++.h>
using namespace std;
void brute()
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            s.erase(s.begin()+i-1,s.begin()+i+1);
            i-=2;
        }
    }

    cout<<s<<endl;
}

int  main()
{
    brute();
    return 0;
}