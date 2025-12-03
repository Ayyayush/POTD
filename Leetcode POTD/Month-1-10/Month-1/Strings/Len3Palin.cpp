#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int i, j, k, count = 0;
    string s, str1, str2;
    getline(cin, s);
    vector<string>temp;
    vector<string>::iterator it;
    for (i = 0; i < s.size(); i++)
    {
       
        for (j = i + 1; j < s.size(); j++)
        {
            for (k = j + 1; k < s.size(); k++)
            {
                 str1 = "";
                str1 += s[i];
                str1 += s[j];
                str1 += s[k];

                str2 = str1;                       // Copy str1 into str2
                reverse(str2.begin(), str2.end()); // Reverse str2
                it=find(temp.begin(),temp.end(),str2);

                if (str1 == str2 && it==temp.end())
                {
                    temp.push_back(str2);
                    count++;
                    cout<<str2<<endl;
                }

            }
        }
    }
    cout << count << endl;
}

void better()
{
    
}
int main()
{
    brute();
    return 0;
}