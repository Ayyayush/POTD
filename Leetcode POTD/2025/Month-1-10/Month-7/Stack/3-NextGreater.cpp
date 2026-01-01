#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // 💡 Approach: Brute Force using digit frequency map (map<int, int>)
    // T.C. = O(Range of [10^(d-1) to 10^d]) = O(10^d)  ⏱️
    // S.C. = O(1) aux, but map takes O(D) = O(10)       🧠

    int n = 230241;                      // 🔸 Hardcoded input
    map<int, int> mpn;                   // Original number digit frequency map
    int size = 0;
    int num = n;

    // 🔁 Extract digit frequencies and count digits of original number
    while (num)
    {
        int rem = num % 10;
        mpn[rem]++;
        size++;
        num /= 10;
    }

    long long min = pow(10, (size - 1));
    long long max = pow(10, size) - 1;

    // 🔁 Brute force loop for all numbers with same number of digits
    for (int i = min; i <= max; i++)
    {
        if (i <= n) continue;

        // 🔍 Extract digit frequency of current i
        map<int, int> mp;
        int temp = i;
        int cnt = 0;

        while (temp)
        {
            int rem = temp % 10;
            mp[rem]++;
            cnt++;
            temp /= 10;
        }

        // ✅ Compare both maps and size
        if (mp == mpn && cnt == size)
        {
            cout << i << endl;
            return;
        }
    }

    // ❌ If no such number exists
    cout << -1 << endl;
}


void better()
{
    // 💡 Approach: Using next_permutation (Lexicographically Next Greater Permutation)
    // T.C. = O(N)                  // STL next_permutation works in linear time in most cases
    // S.C. = O(N)                  // For the string of digits

    int n = 230241;                // 🔸 Hardcoded input
    string s = to_string(n);       // Convert number to string

    // 🔁 Try to get the next lexicographically greater permutation
    if (next_permutation(s.begin(), s.end()))
    {
        long long num = stoll(s);  // Convert back to number safely

        if (num <= INT_MAX)
        {
            cout << (int)num << endl;
            return;
        }
    }

    // ❌ No valid next permutation
    cout << -1 << endl;
}


int main()
{
    brute();
    return 0;
}
