#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int i, j, k;
    string s;
    getline(cin, s);
    for (i = 1; i < s.size(); i++)
    {
        if (find(s.begin(), s.begin() + i - 1, s[i]) != s.begin() + i && find(s.begin() + i + 1, s.end(), s[i]) != s.end())
        {

            for (j = i - 1; j >= 0; j--)
            {
                if (s[j] == s[i])
                {
                    s.erase(j, 1);
                    break;
                }
            }
          
            for (k = i + 1; k < s.size(); k++)
            {
                if (s[k] == s[i])
                {
                    s.erase(k, 1);
                    break;
                }
            }
          
        }
    }

    cout << s.size() << endl;
}





void better()
{
    int i, j, k;
    string s;
    getline(cin, s);

    for (i = 0; i < s.size(); i++)            // O(N)
    {

        bool leftMatch = (find(s.begin(), s.begin() + i, s[i]) != s.begin() + i); // Check left side
        bool rightMatch = (find(s.begin() + i + 1, s.end(), s[i]) != s.end());    // Check right side

        if (leftMatch && rightMatch)
        {
           
            for (j = i - 1; j >= 0; j--)            //O(N/2)
            {
                if (s[j] == s[i])
                {
                    s.erase(j, 1);
                    break;
                }
            }

            // Adjust `i` after left erasure
            i--;

           
            for (k = i + 1; k < s.size(); k++)                   //O(N/2)
            {
                if (s[k] == s[i])
                {
                    s.erase(k, 1);
                    break;
                }
            }

            // Reset `i` to process current position after modification
            i--;
        }
    }

    cout << s.size() << endl;
}

void optimal()           //O(N)
{
     int i, j, k;
    string s;
    getline(cin, s);                            // User se input string lete hain

        int n = s.length();                    // Length of string n mein store karte hain
        vector<int> freq(26, 0);               // Frequency vector banate hain, har character ke liye 0 initial frequency
        int deleted = 0;                       // Deleted characters ka count rakhte hain

        for(int i = 0; i < n; i++) {          // String ke har character ko loop karte hain
            
            freq[s[i] - 'a'] += 1;           // Character ka frequency increment karte hain

            if(freq[s[i]-'a'] == 3) {         // Agar frequency 3 ho gayi, toh excess characters ko delete karte hain
                freq[s[i] - 'a'] -= 2;       // Character ki frequency se 2 ko subtract karte hain, matlab 2 characters delete
                deleted += 2;                // Deleted characters ka count 2 se increment karte hain
            }
        }

        cout << n - deleted;                  // Final output: Total characters - deleted characters
}



int main()
{
    optimal();
    return 0;
}  