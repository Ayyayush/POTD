#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)                                          // ✅ Helper function: check if string is palindrome
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void kpalindromic(int k, string str, int &count)                     // ✅ Modified: check all permutations instead of subsequences
{
    sort(str.begin(), str.end());                                    // pehle sort kar diya for unique permutations
    set<string> used;                                                // to avoid duplicate permutations

    do
    {
        if (str[0] == '0') continue;                                 // ❌ Leading zero allowed nahi hai

        if (used.count(str)) continue;                               // ❌ duplicate skip karo
        used.insert(str);

        if (isPalindrome(str))                                       // ✅ check palindrome
        {
            long long num = stoll(str);
            if (num % k == 0)                                        // ✅ check divisible by k
            {
                cout << num << " ";
                count++;
            }
        }

    } while (next_permutation(str.begin(), str.end()));              // 🔁 all permutations
}

void brute()
{
    int n, k;
    cin >> n >> k;

    int count = 0;

    for (int i = pow(10, n - 1); i < pow(10, n); i++)                // ✅ All n-digit numbers
    {
        string str = to_string(i);
        kpalindromic(k, str, count);                                 // ✅ Modified function call
    }

    cout << endl << count << endl;
}

int main()
{
    brute();
    return 0;
}
