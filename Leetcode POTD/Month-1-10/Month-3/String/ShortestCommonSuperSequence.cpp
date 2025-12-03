#include <bits/stdc++.h>
using namespace std;
void brute()
{
    string str1;
    string str2;
    getline(cin,str1);
    getline(cin,str2);
    if(str1==str2)
    {
        cout<<str1<<endl;
        return ;
    }
    string larger=(str1.size()>str2.size()?str1:str2);
    string smaller=(str1.size()<str2.size()?str1:str2);
    string currstr="";

    for(int i=0;i<smaller.size();i++)
    {
        currstr+=smaller[i];
        string res=currstr+larger;
        cout<<res<<endl;
        if(res.find(str1)!=string::npos && res.find(str2)!=string::npos)
        {
            cout<<res<<endl;
            return ;
        }
    }
}
int main()
{
brute();
return 0;
}