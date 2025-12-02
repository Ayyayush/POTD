#include <bits/stdc++.h>
using namespace std;

void brute()          // O(N*T)
{
    string s;
    cin >> s;                                               // Input string lo
    int t;
    cin >> t;                                               // Number of transformations

    while (t--)
    {
        string temp = "";                                   // Temporary string to build next state
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != 'z')                                // Agar current char 'z' nahi hai
            {
                temp += s[i] + 1;                            // Next character add karo (e.g. 'a' → 'b')
            }
            else
            {
                temp += "ab";                                // Agar 'z' hai to "ab" add karo
            }
        }
        s = temp;                                            // Update string for next iteration
    }

    cout << s << " " << s.size() << endl;                    // Final string aur uski length print karo
}

void better()         // O(T*N)
{
    string s;
    cin >> s;                                                // Input string
    int t;
    cin >> t;                                                // Number of transformations

    unordered_map<char, long long> mp;                       // Map to store frequency of each character

    for (char &ch : s)
    {
        mp[ch]++;                                            // Initial frequency count
    }

    while (t--)
    {
        unordered_map<char, long long> temp;                 // Temporary map for next transformation

        for (auto &it : mp)
        {
            char ch = it.first;
            long long freq = it.second;

            if (ch != 'z')                                   // Agar character 'z' nahi hai
            {
                temp[ch + 1] += freq;          // Next character mein frequency add karo
            }
            else
            {
                temp['a'] += freq;              // 'z' ke liye 'a' aur 'b' add karo
                temp['b'] += freq;
            }
        }

        mp = temp;                              // Update frequency map
        // mp=move(temp)     // isse temp se value move hokke mp mein jayega 
    }

    string result = "";                                      // Final string banani hai
    for (auto &it : mp)
    {
        result += string(it.second, it.first);               // Character ko uski frequency ke according add karo
    }

    cout << result << " " << result.size() << endl;          // Output final string and size
}

void optimal()
{
    string s; cin >> s;                       // string input le rahe hain
    int t; cin >> t;                          // transformation count le rahe hain

    int M = 1e9 + 7;                          // modulo value
    int n = s.length();                       // original string ka length
    vector<int> mp(26, 0);                    // har character ki frequency ko store karne ke liye

    for(char &ch : s) mp[ch - 'a']++;         // har character ki frequency count kar li

    for(int count = 1; count <= t; count++)   // t baar transformation karni hai
    {
        vector<int> temp(26, 0);              // naye frequency ko temporarily store karne ke liye

        for(int i = 0; i < 26; i++)           // saare 26 characters ke liye loop
        {
            char ch = i + 'a';                // index ko character mein convert kar rahe hain
            int freq = mp[i];                 // current character ki frequency

            if(ch != 'z')                     // agar z nahi hai toh sirf next character mein daalna hai
            {
                temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % M;
            }
            else                              // agar z hai toh 'a' aur 'b' mein add karna hai
            {
                temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
            }
        }

        mp = move(temp);                      // naye freq ko current freq mein update kar diya
    }

    int result = 0;                           // final result calculate karna hai
    for(int i = 0; i < 26; i++)
    {
        result = (result + mp[i]) % M;        // total length ka sum le rahe hain
    }

    cout << result << endl;                   // final answer print kar diya
}

int main()
{
    optimal();
    return 0;
}
