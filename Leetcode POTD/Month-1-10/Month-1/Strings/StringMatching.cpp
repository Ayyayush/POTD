#include <bits/stdc++.h>
using namespace std;
void brute()                  // T.C == O(N*N  * M)         m==length of word
{
    int s, i, j;
    cin >> s;
    cin.ignore();
    vector<string> words(s);
    vector<string>::iterator it;
    for (i = 0; i < s; i++)
    {
        getline(cin, words[i]);
    }
    for (i = 0; i < s; i++)
    {
        string str = words[i];

        for (j = 0; j < s; j++)
        {
              // if(i==j)                      // ye same word ko usme hi search hone se rok rha  ye niche wale if mein bhi kr skte h  
              // continue;
            if (words[j].find(str) != string::npos && i!=j)          // find takes linear time as length of word
            {
                cout << "'" << str << "'" << " ";
                break;
            }
        }
    }
}



void better()          
{
     int s, i, j;
    cin >> s;
    cin.ignore();
    vector<string> words(s);
    vector<string>::iterator it;
    for (i = 0; i < s; i++)
    {
        getline(cin, words[i]);
    }
   
        vector<string> result;
        for(i=0;i<words.size();i++)
        {
            for(j=0;j<words.size();j++)
            {
                if(words[j].find(words[i])!=string::npos && i!=j)
                {
                  result.push_back(words[i])  ;
                  break;
                }
            }
        }

        return result;
    }





void optimal()            // using kmp 
{

}

int main()
{
    brute();
    return 0;
}