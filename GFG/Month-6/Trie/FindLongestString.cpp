#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    // 🔴 Brute Force Approach
    // T.C. = O(n * k * k)       (n = number of strings, k = max string length)
    // S.C. = O(1)

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    string maxstring = "";

    for (int i = 0; i < n; i++) 
    {
        string current = words[i];
        string temp = "";
        bool present = true;

        for (int j = 0; j < current.size(); j++) 
        {
            temp += current[j];
            bool found = false;

            for (int k = 0; k < n; k++) 
            {
                if (words[k] == temp) 
                {
                    found = true;
                    break;
                }
            }

            if (!found) 
            {
                present = false;
                break;
            }
        }

        if (present) 
        {
            if (maxstring.size() < current.size()) 
                maxstring = current;
            else if (maxstring.size() == current.size()) 
                maxstring = min(maxstring, current);
        }
    }

    cout << maxstring << endl;
}

void better()
{
    // 🟡 Better Approach using Hash Map
    // T.C. = O(n * k)           (k = avg word length)
    // S.C. = O(n * k)           (for storing all strings in hash map)

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) 
    {
        mp[words[i]]++;
    }

    string maxstring = "";

    for (int i = 0; i < n; i++) 
    {
        string current = words[i];
        string temp = "";
        bool present = true;

        for (int j = 0; j < current.size(); j++) 
        {
            temp += current[j];
            if (!mp.count(temp)) 
            {
                present = false;
                break;
            }
        }

        if (present) 
        {
            if (maxstring.size() < current.size()) 
                maxstring = current;
            else if (maxstring.size() == current.size()) 
                maxstring = min(maxstring, current);
        }
    }

    cout << maxstring << endl;
}


/**
 * Trie is the best data structure to handle prefix 
 * ye bilku; tree ki tarah hi hota h bas ye diff h ki
 * isme node ki jagah vector of nodes hota h
 * hum trie ka vector bnate h aur 26 size ka lete h 
 * ab maan lo a-z ke liye ban gya 
 * par ab a ke liye bhi apna 26 size ka vector h 
 * aise hi b,c,d...z ke liye bhi hoga 
 * Tree mein jaise left child aur right child hota h
 * listv mien next aur data hota h 
 * waise hi trie mein sabse pehle ek boolena variable hota h
 * bool is endofword
 * isko trie mein daalenge 
 * 
 * struct trieNode
 * {
 * bool isEndofWord;
 * }
 * 
 *
 * Example to illustrate how "pro" is stored in a Trie:
 *
 * Word inserted: "pro"
 *
 *       "pro"
 *        ↓
 *   ┌─────────────┐
 *   │   ... P ... │   ← TrieNode for 'p'
 *   └─────────────┘
 *            ↓
 *   ┌─────────────┐
 *   │   ... R ... │   ← TrieNode for 'r'
 *   └─────────────┘
 *            ↓
 *   ┌─────────────┐
 *   │   ... O ... │   ← TrieNode for 'o'
 *   └─────────────┘
 *            ↓
 *   isEndOfWord = true   ← marks the end of the word "pro"
 *
 * This structure helps in fast prefix-based word search using Trie.
 * 
 * jaha pe word end ho rha h waha pe jaake endofword true karenge 
 * 
 * struct TrieNode
 * {
 * bool isEndofWord;
 * TrieNode* children[26];
 * 
 * 
 * TrieNode()
 * {
 * isEndOfWord=false;
 * for(int i=0;i<26;i++)
 * {
 * children[i]=nullptr;
 * }
 * }
 * 
 * }
 * 
 * insert(word) ....... ye apna parameter mein word lega
 * {
 * pro=""
 * 
 * }
 * 
 * 
 * 
 */
int main()
{
    // Sample usage:
    // Input:
    // 6
    // n ni nin nine ninj ninja

    brute();     // 🔴 Call brute here
    better();    // 🟡 Call better here

    return 0;
}
