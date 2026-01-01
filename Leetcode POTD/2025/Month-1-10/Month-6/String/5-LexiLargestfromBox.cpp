#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hota hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void brute()
{
    /*
        Lexicographically largest ka matlab hota hai:
        jo string dictionary ke hisaab se baad me aaye, jaise:
        "zebra" > "apple" > "abcd"

        🔍 Problem idea:
        - Hume sabse bada character lena hai string se
        - Minimum 1 character har friend ko dena hi hoga (no empty string allowed)
        - Agar sirf 2 friends hain:
            ➤ Second ko kam se kam 1 character do
            ➤ Baaki first friend ko sabse bada lexicographical substring dene ki koshish karo

        - Agar 2 se zyada friends hain:
            ➤ numFriends = k
            ➤ First (k-1) friends ko ek ek character dedo
            ➤ Baaki characters ek hi friend ko dedo, aur try karo us substring ka starting character
               lexicographically largest ho

        ✅ Example 1:
        Input: string = "abcde", friends = 3
        ➤ f2 = 'a', f3 = 'b'
        ➤ f1 = "cde"
        ➤ "cde" starts with 'c' => best among remaining

        ✅ Example 2:
        Input: string = "abccba", friends = 3
        ➤ f2 = 'a', f3 = 'b'
        ➤ f1 = "ccba" → starts with 'c' => good result

        ✅ Edge Case:
        Input: string = "eeeeee", friends = 2
        ➤ Best to give 1 'e' to f2, and remaining to f1


        largest possible = n- (numfreinds -1);
        take possible length=min(longestpossible,n-i)
        substring (ik,take possible length);

        ✅ Example 4:
        Input: s = "eabced", k = 3

        ➤ Total length = 6
        ➤ Minimum 1 character har friend ko dena hoga ⇒ (k - 1) = 2 characters doosre friends ko de do
        ➤ Toh ek friend ko maximum possible characters mil sakte hain = 6 - 2 = 4 characters

        ➤ Ab 4 length tak ke substrings check karo jo sabse lexicographically largest ho

        ➤ Substrings of length ≤ 4:
            "eabc", "abce", "bced", "ced", "ed", "d" ...
            Compare karo: "eabc", "abce", "bced", "ced" → among these, "eabc" is lexicographically largest

        ➤ So final answer = "eabc"

        🧠 Observation:
        Even though 'e' string ke starting aur end dono jagah hai,
        lekin starting se 4 character lene par "eabc" ban raha hai jo sabse bada hai
        (kyunki 'e' se start ho raha hai aur next characters bhi lexicographically lower hain)

        ⚠️ Goal: Har case me aise characters distribute karo ki kisi ek friend ka string
           sabse lexicographically bada ho

        🔧 This is just brute idea setup; actual logic needs to be implemented.
    */

    string word;
    cin >> s;
    int numFriends;
    cin >> numFriends;
    int n = word.length();
    if (numFriends == 1)
        return word;
    string result;

    int longestpossible = n - (numFriends - 1);

    for (int i = 0; i < n; i++)
    {
        int cantakelen = min(longestpossible, n - i);
        result = max(result, word.substr(i, cantakelen));
    }

    cout << result << endl;
}

int bestStartingpoint(string &word, int n)
{
    int i = 0;
    int j = 1; // keep moving to find best starting point

    while (j < n)
    {
        int k = 0;
        // skipping equal characters
        while (j + k < n && word[i + k] == word[j + k]) // i toh wiase bhi j se piche h
        {
            k++;
        }

        if (j + k < n && word[j + k] > word[i + k])
        {
            i = j; // updating best starting point
            j = i + 1;
        }
        else
        {
            j = j + k + 1; // skipping already checked charcters
        }
    }
}
void better()
{
    string word;
    cin >> s;
    int numFriends;
    cin >> numFriends;
    int n = word.length();

    // using two pointer approach
    // maan lo eabceddcfez hai string ... numfriends=3 h
    // i=0 ,j=1 h
    // j  aage chalta rahega aur dhundta rahega
    // check karo ki i ka charcter j ke charcter ke barabar h kya
    // jab tak ewual nhi h i aur j ke charcater mein bada dekhte raho
    // jo bada h i  ko whi rakho
    // agar barabar aa gya h toh i ka next aur j ka next chaarcter compare karo
    // ek k pointer lenge i uar j dono ke aage k++ charcters check krte jayenge
    // k compareison ke baad dono mein se jop bada nikle
    // i ko uske starting point pe le aao k ko  firr se zero kar do
    // firr whi process repaet karo

    if (numFriends == 1)
    {
        cout << word << endl;
        return;
    }

    int i = bestStartingpoint(word, n);

    int longestpossible = n - (numFriends - 1);

     int cantakelen = min(longestpossible, n - i);

     string result;

             result = max(result, word.substr(i, cantakelen));
    

    cout << result << endl;


}

signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye

    brute(); // Brute function call

    return 0; // Program successful terminate ho raha hai
}
