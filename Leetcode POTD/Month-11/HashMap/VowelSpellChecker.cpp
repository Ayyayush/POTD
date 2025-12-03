/**
 *  Vowel SpellChecker 
 * 
 *  🔹 Problem Explanation:
 *  Humein ek spell checker banana hai jo 3 rules follow karega jab hum queries check karte hain:
 *  
 *  1️⃣ **Exact Match Rule:**  
 *      Agar query exactly kisi wordlist ke word se match karti hai (case-sensitive match),
 *      toh wahi word return karo.
 *  
 *  2️⃣ **Case-Insensitive Match Rule:**  
 *      Agar koi word case-insensitive match karta hai (e.g., "YellOw" vs "yellow"),
 *      toh wordlist ka pehla matching word return karo.
 *  
 *  3️⃣ **Vowel Error Match Rule:**  
 *      Agar vowels ('a', 'e', 'i', 'o', 'u') ko kisi bhi vowel se replace karne ke baad
 *      query kisi word ke vowel pattern se match karti hai, toh us matching word ko return karo.  
 *      (Example: "tIst" → matches with "test")
 *  
 *  4️⃣ Agar koi bhi rule match nahi karta → empty string return karo.
 * 
 *  🔹 Input:
 *      - `wordlist`: list of correct words.
 *      - `queries`: list of query words jinke liye humein spelling check karni hai.
 * 
 *  🔹 Output:
 *      - List of corrected spellings (ya empty string agar match nahi mila).
 * 
 *  🔹 Example:
 *      Input:
 *      wordlist = ["KiTe","kite","hare","Hare"]
 *      queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
 * 
 *      Output:
 *      ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 * 
 *  🔹 Approach Summary:
 *      - Create 3 hash maps for:
 *          1. Exact matches
 *          2. Lowercase matches
 *          3. Vowel-insensitive matches (vowels replaced by '*')
 *      - For each query, check in order: Exact → Lowercase → Vowel form.
 *      - Return corresponding match or "".
 * 
 *  🔹 Detailed Dry Run:
 * 
 *  Step 1️⃣: Preprocessing `wordlist = ["KiTe", "kite", "hare", "Hare"]`
 * 
 *      ExactMap  = { "KiTe": "KiTe", "kite": "kite", "hare": "hare", "Hare": "Hare" }
 *      LowerMap  = { "kite": "KiTe", "hare": "Hare" }       // stores first lowercase match
 *      VowelMap  = { "k*t*": "KiTe", "h*r*": "Hare" }       // vowels replaced by '*'
 * 
 * 
 *  Step 2️⃣: Process each query from 
 *            ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
 * 
 *  🔸 Query 1: "kite"
 *      → Exact match ✅ (found in ExactMap)
 *      → Output: "kite"
 * 
 *  🔸 Query 2: "Kite"
 *      → Exact ❌ 
 *      → Lowercase "kite" ✅ found in LowerMap ("KiTe")
 *      → Output: "KiTe"
 * 
 *  🔸 Query 3: "KiTe"
 *      → Exact ✅ "KiTe"
 *      → Output: "KiTe"
 * 
 *  🔸 Query 4: "Hare"
 *      → Exact ✅ "Hare"
 *      → Output: "Hare"
 * 
 *  🔸 Query 5: "HARE"
 *      → Exact ❌ 
 *      → Lowercase "hare" ✅ found in LowerMap ("hare")
 *      → Output: "hare"
 * 
 *  🔸 Query 6: "Hear"
 *      → Exact ❌
 *      → Lowercase ❌
 *      → Vowel form "h**r" ❌ not found in VowelMap
 *      → Output: ""
 * 
 *  🔸 Query 7: "hear"
 *      → Exact ❌
 *      → Lowercase ❌
 *      → Vowel form "h**r" ❌ not found
 *      → Output: ""
 * 
 *  🔸 Query 8: "keti"
 *      → Exact ❌
 *      → Lowercase ❌
 *      → Vowel form "k*t*" ✅ found in VowelMap ("KiTe")
 *      → Output: "KiTe"
 * 
 *  🔸 Query 9: "keet"
 *      → Exact ❌
 *      → Lowercase ❌
 *      → Vowel form "k**t" ❌ not found
 *      → Output: ""
 * 
 *  🔸 Query 10: "keto"
 *      → Exact ❌
 *      → Lowercase ❌
 *      → Vowel form "k*t*" ✅ found ("KiTe")
 *      → Output: "KiTe"
 * 
 * 
 *  ✅ Final Output:
 *  ["kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"]
 * 
 */


 /*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=P0JdEsDlZX8
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/vowel-spellchecker
*/


/************************************************************ C++ *****************************************************/
//Approach - Using map and set
//T.C : O(N), N = total length of all the input strings and queries
//S.C : O(N)
class Solution {
public:
    unordered_set<string> exactWords;          // stores original words
    unordered_map<string, string> caseMap;     // lowercase : original word
    unordered_map<string, string> vowelMap;    // masked vowels : original word
    
    string toLower(const string& s) {
        string res = s;
        for (char& c : res) {
            c = tolower(c);
        }
        return res;
    }

    string maskVowels(const string& s) {
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }

    string checkForMatch(const string& query) {
        // Exact match
        if (exactWords.count(query)) {
            return query;
        }

        // Case error match
        string lowerQuery = toLower(query);
        if (caseMap.count(lowerQuery)) {
            return caseMap[lowerQuery];
        }

        // Vowel error match
        string maskedQuery = maskVowels(lowerQuery);
        if (vowelMap.count(maskedQuery)) {
            return vowelMap[maskedQuery];
        }

        // 4. No match
        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactWords.clear();
        caseMap.clear();
        vowelMap.clear();

        for (string word : wordlist) {
            exactWords.insert(word);

            string lowerWord = toLower(word);
            if (caseMap.find(lowerWord) == caseMap.end()) { //Add only 1st occurrence
                caseMap[lowerWord] = word;
            }

            string maskedWord = maskVowels(lowerWord);
            if (vowelMap.find(maskedWord) == vowelMap.end()) { //Add only 1st occurrence
                vowelMap[maskedWord] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            result.push_back(checkForMatch(query));
        }
        return result;
    }
};

