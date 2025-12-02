#include <bits/stdc++.h>
using namespace std;

/*
 * 🔗 GfG Link: https://www.geeksforgeeks.org/problems/check-frequencies4211/1
 *
 * ✅ Problem: Check if frequencies can be equal
 * ✅ Difficulty: Medium
 *
 * ✅ Statement:
 * Given a string s consisting of only lowercase characters,
 * check whether it is possible to remove **at most one character**
 * so that the frequency of all distinct characters becomes equal.
 *
 * ➤ Return true if possible, else return false.
 *
 * 🧠 Constraints:
 * 1 ≤ s.length() ≤ 10^5
 */

void brute()
{
    /*
     * 📌 Example input for dry run:
     * string s = "aabbccc";
     */
    string s;
    cin >> s;

    /*
     * ✅ Step 1: Count frequency of each character
     */
    vector<int> freq(26, 0); // frequency of 'a' to 'z'
    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    /*
     * ✅ Step 2: Find min & max frequencies among non-zero elements
     */
    int maxFreqValue = INT_MIN;
    int maxFreqCounter = 0;
    int minFreqValue = INT_MAX;
    int minFreqCounter = 0;

    for (int f : freq)
    {
        if (f == 0)
            continue;

        if (f == maxFreqValue)
        {
            maxFreqCounter++;
        }

        if (f == minFreqValue)
        {
            minFreqCounter++;
        }

        if (f > maxFreqValue)
        {
            maxFreqValue = f;
            maxFreqCounter = 1;
        }

        if (f < minFreqValue)
        {
            minFreqValue = f;
            minFreqCounter = 1;
        }
    }

    /*
     * ✅ Step 3: Analyze the difference between max and min frequency
     */

    // Case 1: All frequencies are already the same
    if ((maxFreqValue - minFreqValue) == 0)
    {
        cout << "true\n";
        return;
    }

    // Case 2: Only one frequency is off by 1, or one character appears only once
    if ((maxFreqValue - minFreqValue) == 1 &&
        (maxFreqCounter == 1 || (minFreqValue == 1 && minFreqCounter == 1)))
    {
        cout << "true\n";
        return;
    }

    /*
     * ❌ Else not possible by removing one character
     */
    cout << "false\n";
}

/*
 * 🔍 Dry Run 1:
 * Input: s = "aabbccc"
 * freq = {a:2, b:2, c:3}
 * minFreq = 2, minFreqCounter = 2 (a, b)
 * maxFreq = 3, maxFreqCounter = 1 (c)
 * ✔️ max - min = 1, maxFreqCounter = 1 → return true
 *
 * 🔍 Dry Run 2:
 * Input: s = "aabbccd"
 * freq = {a:2, b:2, c:2, d:1}
 * minFreq = 1, minFreqCounter = 1 (d)
 * maxFreq = 2, maxFreqCounter = 3 (a,b,c)
 * ✔️ max - min = 1, minFreq = 1 and minFreqCounter = 1 → return true
 *
 * 🔍 Dry Run 3:
 * Input: s = "xxxxyyzz"
 * freq = {x:4, y:2, z:2}
 * min = 2 (y,z), max = 4 (x) → diff = 2 → ❌ return false
 */
