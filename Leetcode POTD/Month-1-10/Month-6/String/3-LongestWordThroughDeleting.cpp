#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void brute() // this logic faults becaus we have to also form the words sequenitally
{
    string s;
    cin >> s;                // String input lena
    int n;
    cin >> n;                // Dictionary size input lena
    unordered_map<char, int> mp1, mp2; // Character frequency maps
    vector<string> dictionary(n);      // Dictionary strings store karne ke liye vector


    for (int i = 0; i < s.size(); i++)
    {
        mp1[s[i]]++;         // s ke har character ka count store kar rahe hain
    }
    mp2 = mp1;               // mp2 me copy kar rahe hain taaki original freq safe rahe



    for (int i = 0; i < n; i++)
    {
        cin >> dictionary[i]; // Dictionary ke strings input le rahe hain
    }
    

    string minstring = "";    // Sabse bada string jo bana sakte hain wo yaha store hoga
    bool formed = true;       // Flag ki string bana sakte hain ya nahi

    for (int i = 0; i < n; i++)
    {
        string str = dictionary[i];
        formed = true;         // Har nayi string ke liye flag reset karna hai

        for (int j = 0; j < str.size(); j++)  // Loop ke andar i ki jagah j use karna better hai
        {
            if (mp1.find(str[j]) == mp1.end()) // Agar character s me nahi hai
            {
                formed = false;    // String nahi ban sakti
                break;
            }
            else
            {
                mp1[str[j]]--;    // Character ka count kam kar rahe hain
                if (mp1[str[j]] == 0) // Agar count zero ho gaya to map se hatao
                    mp1.erase(str[j]);
            }
        }
        mp1 = mp2;               // Har string ke baad mp1 ko reset karna hai original freq se

        if (formed)              // Agar string bana paye to check karo size aur lex order
        {
            if (str.size() > minstring.size())  // Agar bada string mila to update karo
            {
                minstring = str;
            }
            else if (str.size() == minstring.size()) // Same length strings me lex order check
            {
                minstring = minstring < str ? minstring : str;
            }
        }
    }

    cout << minstring << endl;  // Result print kar do
}

void better()
{
    string s;
    cin >> s;          // Main string input

    int n;
    cin >> n;          // Dictionary size

    vector<string> dictionary(n);
    for (int i = 0; i < n; i++)
        cin >> dictionary[i];    // Dictionary input

    string result = "";

    for (auto &word : dictionary)
    {
        int i = 0, j = 0;

        // Check if 'word' can be formed from 's' by deleting characters
        while (i < (int)s.size() && j < (int)word.size())
        {
            if (s[i] == word[j])
                j++;
            i++;
        }

        if (j == (int)word.size())  // poora word ban sakta hai
        {
            // Agar bada word mila ya size same aur lex chhota word mila toh update karo
            if ((int)word.size() > (int)result.size() || 
                ((int)word.size() == (int)result.size() && word < result))
            {
                result = word;
            }
        }
    }

    cout << result << endl;  // Final answer print karo
}



signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0; // Program successful terminate ho raha hai
}
