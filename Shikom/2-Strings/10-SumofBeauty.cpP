#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// BRUTE FORCE APPROACH                                     //
// T.C. = O(N^3)                                            //
// S.C. = O(26) or O(N) for substring                       //
//////////////////////////////////////////////////////////////

void brute()                 
{                            
    string s;                
    cin >> s;               

    long long sum = 0;      

    for(int i = 0; i < s.size(); i++)                          // start of substring
    {
        string str = "";                                       // building substring
        
        for(int j = i; j < s.size(); j++)                      // end of substring
        {
            str += s[j];                                       // extend substring

            unordered_map<char,int> mp;                        // freq map for substring

            for(int k = 0; k < str.size(); k++)                // count freq of all chars
            {
                mp[str[k]]++;                                  
            }

            int mn = INT_MAX, mx = INT_MIN;                    // find beauty
            for(auto &it : mp)
            {
                mx = max(mx, it.second);
                mn = min(mn, it.second);
            }

            sum += (mx - mn);                                  // add beauty of substring
        }
    }

    cout << sum << endl;      
}

//////////////////////////////////////////////////////////////
// BETTER APPROACH                                          //
// T.C. = O(N^2 * 26)                                       //
// S.C. = O(26)                                             //
//////////////////////////////////////////////////////////////

void better()
{
    string s;
    cin >> s;

    long long sum = 0;
    int n = s.size();

    for(int i = 0; i < n; i++)                                 // start index
    {
        int freq[26] = {0};                                    // reset freq table for each i
        
        for(int j = i; j < n; j++)                             // end index
        {
            freq[s[j] - 'a']++;                                // add char to freq

            int mx = 0, mn = INT_MAX;                          // compute beauty for substring

            for(int k = 0; k < 26; k++)                        // scan all characters
            {
                if(freq[k] > 0)                                // only consider chars present
                {
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
            }

            sum += (mx - mn);                                  // add beauty
        }
    }

    cout << sum << endl;
}

//////////////////////////////////////////////////////////////
// OPTIMAL APPROACH                                         //
// Using HashMap per expansion                              //
// T.C. = O(N^2)                                            //
// S.C. = O(26) approx                                     //
//////////////////////////////////////////////////////////////

void optimal()
{
    string s;
    cin >> s;

    int count = 0;

    for(int i = 0; i < s.size(); i++)                          // start of substring
    {
        unordered_map<char, int> mp;                           // freq map

        for(int j = i; j < s.size(); j++)                      // expand substring
        {
            mp[s[j]]++;                                        // update freq

            int maxfreq = INT_MIN;                             // track beauty
            int minfreq = INT_MAX;

            for (auto &p : mp)                                 // check all char freq
            {
                maxfreq = max(maxfreq, p.second);
                minfreq = min(minfreq, p.second);
            }

            count += (maxfreq - minfreq);                      // beauty contribution
        }
    }

    cout << count << endl;
}

//////////////////////////////////////////////////////////////
// MAIN FUNCTION — STRIVER FORMAT                           //
//////////////////////////////////////////////////////////////

int main()
{
    // Call any version you want to test:
    // brute();
    // better();
    optimal();

    return 0;
}
