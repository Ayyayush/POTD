#include <bits/stdc++.h>
using namespace std;

void brute()      // O(N^2)
{
    string s;
    getline(cin, s);

    string longpalin = "";
    int maxlen = 0;  // Fix: Length negative nahi ho sakti, isliye 0 initialize kiya

    for (int i = 0; i < s.size(); i++)
    {
        string palin = "";
        for (int j = i; j < s.size(); j++)
        {
            palin += s[j];

            string revs = palin;
            reverse(revs.begin(), revs.end());

            if (palin == revs)
            {
                if (palin.size() > maxlen)
                {
                    maxlen = palin.size();  // Fix: maxlen ko update karna zaroori hai
                    longpalin = palin;  // Fix: longpalin ko bhi update karna padega
                }
            }
        }
    }

    cout << longpalin << endl;  // Fix: Sirf final longest palindrome print hoga
}
   




    void findLongestPalindrome(string &s, int left, int right, string &longpalin)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;   // Left side expand karo
            right++;  // Right side expand karo
        }
        // Loop ke baad (left+1) se (right-1) tak ka substring palindrome hai
        if (right - left - 1 > longpalin.size())
        {
            longpalin = s.substr(left + 1, right - left - 1);
        }
    }
    
    void better()
    {
        string str;
        getline(cin, str);
    
        string longpalin = "";
    
        for (int i = 0; i < str.size(); i++)
        {
            findLongestPalindrome(str, i, i, longpalin);     // Odd length palindrome
            findLongestPalindrome(str, i, i + 1, longpalin); // Even length palindrome
        }
    
        cout << longpalin << endl;
    }
    
    int main()
    {
        better();
    }
    
