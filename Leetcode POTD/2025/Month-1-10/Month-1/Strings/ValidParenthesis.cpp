#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int i,j,count1=0,count2=0;
    vector<int>index;
    string s, locked;
    getline(cin, s);
    getline(cin, locked);
    int n=s.size();
    for (i = 0; i < locked.size(); i++)
    {
        if (locked[i] == 0)
            index.push_back(i);
    }
    if (s[0] == '(' && s[s.size() - 1] == ')' && s.size()<=4)
    {
        cout << "True";
        return;
    }
    else
    {

            for(j=0;j<index.size();j++)
            {
                if(s[index[j]]=='(')
                s[j]=')';
                else
                s[j]='(';
            }

           
    }

    for(i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        count1++;
        else
        count2++;

        if(count1==count2)
        {
            count1=0;
            count2=0;
        }
    }
     cout<<s<<endl;
    if(count1==count2)
    {
        cout<<s<<endl;
    cout<<"True"<<endl;
    return ;
    }
    else
    {
         cout<<s<<endl;
        cout<<"False"<<endl;
        return;
    }




}
    int main()
    {
        brute();
        return 0;
    }