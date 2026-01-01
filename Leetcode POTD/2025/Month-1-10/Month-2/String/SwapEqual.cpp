#include <bits/stdc++.h>
using namespace std;
void brute()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if(s1.size()!=s2.size())
    {
    cout<<"False"<<endl;
    return;
    }
    else if(s1==s2)
    {
        cout << "true" << endl;
                return; 
    }

    for (int i = 0; i < s1.size(); i++)
    {
        

        for (int j = s1.size() - 1; j >=0; j--)
        {
            string str = s2;
            swap(str[i], str[j]) ;
           
            if (str == s1)
            {
                cout << "true" << endl;
                return;
            }
           
        }
    }

     cout<<"False"<<endl;
}

void better()
{
      string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if(s1.size()!=s2.size())
    {
    cout<<"False"<<endl;
    return;
    }
    else if(s1==s2)
    {
        cout << "true" << endl;
                return; 
    }
    int st=0,end=s1.size()-1;
    while(st<end)
    {
        string str=s2;
        swap(str[st++],str[end]--)
    }
}
int main()
{
    brute();
    return 0;
}