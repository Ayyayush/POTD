#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////
// 🧠 Approach: Brute Force
// ✅ Time Complexity: O(N^2 + K log K)
//    - Outer loop: O(N)
//    - Inner loop (last index search): O(N)
//    - Sorting result of size K: O(K log K)
// ✅ Space Complexity: O(26 + K) = O(K)
//    - Map stores at most 26 characters
//    - Result vector of size K (unique chars with valid sum)
//////////////////////////////////////////////////////////////////
void brute()
{
    // 👉 Input lena
    string s = "abacab";

    unordered_map<char, vector<int>> mp;     // character -> [firstIndex, lastIndex]

    // 👉 First loop to store first & last index for each character
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if (mp.count(ch) == 0)
        {
            mp[ch].push_back(i);     // first index store karo

            for (int j = s.size() - 1; j >= 0; j--)     // last index dhoondo
            {
                if (s[j] == ch)
                {
                    mp[ch].push_back(j);     // last index store karo
                    break;
                }
            }
        }
    }

    vector<int> result;     // final result vector

    // 👉 Har character ke liye ascii sum calculate karo between its first+1 to last index
    for (auto it : mp)
    {
        int first = it.second[0];
        int second = it.second[1];
        int sum = 0;

        if (first == second) continue;       // agar same index hai toh skip karo

        for (int i = first + 1; i < second; i++)
        {
            sum += int(s[i]);
        }

        if (sum != 0)
            result.push_back(sum);
    }

    sort(result.begin(), result.end());     // sort the final result

    // 👉 Output print karna
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}

//////////////////////////////////////////////////////////////////
// 🧠 Approach: Better (1-pass index tracking)
// ✅ Time Complexity: O(N + K log K)
//    - O(N) for building map
//    - O(K log K) for sorting (K = no. of valid unique chars)
// ✅ Space Complexity: O(26 + K) = O(K)
//////////////////////////////////////////////////////////////////
void better()
{
    // 👉 Input string
    string s = "abcab";

    unordered_map<char, vector<int>> mp;      // character -> [firstIndex, lastIndex]

    // 👉 Single pass to find first and last index of each character
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (mp.count(ch) == 0)
        {
            mp[ch] = {i, i};                  // Pehli baar aaya — first & last index same
        }
        else
        {
            mp[ch][1] = i;                    // Update last index
        }
    }

    vector<int> result;     // final result vector

    // 👉 Har character ke liye sum nikaalo between (first, last)
    for (auto it : mp)
    {
        int first = it.second[0];
        int last = it.second[1];

        if (first == last) continue;          // agar koi gap hi nahi, skip karo

        int sum = 0;
        for (int i = first + 1; i < last; i++)   // only characters strictly between
        {
            sum += int(s[i]);                   // ASCII value add karo
        }

        result.push_back(sum);     // store valid sum
    }

    sort(result.begin(), result.end());     // sort final result

    // 👉 Output print karna
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    brute();
    better();
    return 0;
}
