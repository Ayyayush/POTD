#include <bits/stdc++.h>
using namespace std;

#define endl '\n'                // 'endl' ko '\n' se replace kiya gaya hai — zyada fast hota hai (flush nahi karta)
#define int long long            // Har jagah 'int' ko 'long long' treat kiya jaayega (bade input ke liye helpful)
const int MOD = 1e9 + 7;         // Modulo value — CP problems mein common hai (usually for large results)
const int INF = LLONG_MAX >> 1;  // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya)
#define all(x) x.begin(), x.end() // Vector ke pura range ke liye shorthand
#define vi vector<int>            // vi = vector<int>
#define u unordered_map<int, int> // u = unordered_map shorthand
#define f(i, n) for (int i = 0; i < n; i++) // shorthand for loop


void Recurbrute()
{
    /*
     * 🔹 STEP 1: Subsequence Length ka Maximum Limit
     *
     * humein aisa longest subsequence `sub` dhoondhna hai jisko `k` times repeat karne pe
     * wo puri string `s` ka subsequence hona chahiye.
     *
     * So sub * k ka total length = l * k <= n hona chahiye
     * Isliye max length of sub = l <= n / k
     *
     * ✅ Example:
     *   s = "letsleetcode", k = 2 → n = 12 → max length of sub = 12 / 2 = 6
     */

    /*
     * 🔹 STEP 2: Frequency Filtering
     *
     * Pehle har character ka frequency nikaalo.
     * Agar kisi character ka freq < k hai, toh wo kisi bhi valid sub mein ho hi nahi sakta.
     * Toh usse ignore kar do.
     *
     * ✅ Example:
     *   s = "ketlet", k = 2
     *   'k' ki freq = 1 → hatao
     *   Remaining chars = {'l', 'e', 't'} → valid candidates
     */

    /*
     * 🔹 STEP 3: Subsequence Length Constraint
     *
     * Ab jo subsequences banayenge unki max length n/k se zyada nahi honi chahiye
     * Ye constraint hamesha dhyan mein rakho while generating subsequences.
     *
     * ✅ Example:
     *   s.length() = 12, k = 2 → max length = 6
     */

    /*
     * 🔹 STEP 4: Max Usage per Character in One Subsequence
     *
     * Har valid character ko ek sub mein max freq[ch]/k baar hi use kar sakte ho.
     * Kyuki sub ko k times repeat karna hai, toh overall freq[ch] / k se zyada nahi ho sakta.
     *
     * ✅ Example:
     *   s = "leetleet", k = 2
     *   freq['e'] = 4 → 1 sub mein max 4/2 = 2 times use
     *   freq['l'] = 2 → 1 time
     *   freq['t'] = 2 → 1 time
     *   Possible sub = "leet"
     */

    /*
     * 🔹 STEP 5: Backtracking se Subsequence Generation
     *
     * Backtracking ya DFS se saare possible valid subsequences generate karo 
     * (jo above constraints meet karte ho).
     * Har subsequence ke liye:
     *   - sub * k banao (concatenate k times)
     *   - check karo kya wo `s` ka subsequence hai?
     *   - agar haan, toh answer update karo
     *
     * ✅ Example:
     *   sub = "let", k = 2 → "letlet"
     *   s = "letletcode"
     *   Kya "letlet" is a subsequence of s? → haan → update ans
     */

    /*
     * 🔹 STEP 6: Subsequence Checker (Two Pointer Approach)
     *
     * Ye subsequence check karne ka core logic hota hai:
     *   i = sub*k string pe, j = s string pe
     *   Jab bhi sub*k[i] == s[j] mile, i++
     *   End mein agar i == sub*k.length() hai → valid subsequence
     *
     * ✅ Example:
     *   sub = "let", k = 2 → sub*k = "letlet"
     *   s = "letxletcode"
     *   Matching order mein mile: l → e → t → l → e → t → ✔️
     *
     * 🔗 Related Problem (for this logic): Leetcode 392 – "Is Subsequence"
     *     https://leetcode.com/problems/is-subsequence/
     */

    /*
     * 🔹 BONUS (Optimized Check Bina String Banaye):
     *
     * Har bar sub*k string banana costly hoga (O(nk) time).
     * Aise optimize karo:
     *   - sub string ka i pointer rakho
     *   - s ke liye ek j pointer rakho
     *   - jese hi sub[i] match kare → i++
     *   - i ko har bar i % sub.length() se update karo
     *   - ek counter rakho → kitni baar pura sub match hua (i == 0)
     *   - agar yeh count == k ho gaya → valid
     */
}





class Solution {
public:
    string result = "";

    // 🔁 Checks if (sub * k) is a subsequence of s
    bool issubseq(string &s, string &sub, int k)
    {
        int i = 0, j = 0;
        int l = sub.size();
        int n = s.size();

        while (i < n && j < k * l)
        {
            if (s[i] == sub[j % l]) j++;
            i++;
        }

        return j == k * l;
    }

    // 🔁 Backtracking to try all valid subsequences up to maxlen
    void backtracking(string &s, string &curr, vector<bool> &canuse,
                      vector<int> &requiredfreq, int k, int maxlen)
    {
        if (curr.length() > maxlen)
            return;

        if ((curr.length() > result.length() ||
            (curr.length() == result.length() && curr > result)) &&
            issubseq(s, curr, k))
        {
            result = curr;
        }

        for (int i = 25; i >= 0; i--) // lexicographically larger preference
        {
            if (!canuse[i] || requiredfreq[i] == 0) continue;

            // Do
            char ch = 'a' + i;
            curr.push_back(ch);
            requiredfreq[i]--;

            // Explore
            backtracking(s, curr, canuse, requiredfreq, k, maxlen);

            // Undo
            curr.pop_back();
            requiredfreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k)
    {
        int n = s.length();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<bool> canuse(26, false);
        vector<int> requiredfreq(26, 0);

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] >= k)
            {
                canuse[i] = true;
                requiredfreq[i] = freq[i] / k;
            }
        }

        int maxlen = n / k;
        string curr;

        backtracking(s, curr, canuse, requiredfreq, k, maxlen);

        return result;
    }
};






void ImprovedProcedure()
{
    /**
     * humlog har length ka aur saare subseq check akr rhe the 
     * par saare generate nhi krne h 
     * eg subseq== xyz   k==2 
     * maan lo ek aur subseq aaya xyzab   k==2 hua
     * agar dono valid h bhi toh answer xyzab hopga kyunki wo bada h 
     * toh hum pehle bade wale suseq dekhenge 
     * 
     */
}





//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    void backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() > maxLen)
            return;
        
        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result))
            && isSubsequence(s, curr, k)) {
                result = curr;
        }

        for(int i = 0; i <= 25; i++) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            backtracking(s, curr, canUse, requiredFreq, k, maxLen);

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        string curr;
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        return result;


    }
};


signed main()
{
    ios::sync_with_stdio(false); // Fast I/O ke liye C++ streams ko sync off kiya
    cin.tie(NULL);               // cin aur cout ko alag-alag buffer use karne diya for speed

    Recurbrute();                // Abhi brute approach ya dry run simulate karo

    return 0;                    // Program successful terminate hua
}
