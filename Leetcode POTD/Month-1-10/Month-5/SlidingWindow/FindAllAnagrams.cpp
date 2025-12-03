#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(m * n log n)          
    // m = length of main string, n = length of pattern
    // Har window mein substring n size ki banate hain (O(n)), phir usse sort karte hain (O(n log n))
    // Total windows = m - n + 1 => Overall = O((m - n + 1) * n log n)

    // Space Complexity: O(n)                  
    // har baar ek n size ki substring ban rahi hai + sorting ke liye space

    string s;                     
    getline(cin, s);             

    string p;                    
    getline(cin, p);             

    vector<int> vec;             

    string sorted_p = p;         
    sort(sorted_p.begin(), sorted_p.end());     // pattern ko sort kar liya

    int window_size = p.size();

    for (int i = 0; i <= s.size() - window_size; i++)   // har window check karenge
    {
        string subs = s.substr(i, window_size);         // current window uthayi
        sort(subs.begin(), subs.end());                 // usse bhi sort kiya

        if (subs == sorted_p)                           // agar anagram mila
        {
            vec.push_back(i);                           // index store karo
        }
    }

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";                          // print karo result

    cout << endl;
}


void better()
{
    // Time Complexity: O(m + n)    
    // m = length of s, n = length of p
    // Har character ek baar decrement aur ek baar increment ho raha hai (26 size freq array use kar rahe hain)

    // Space Complexity: O(1)       
    // fixed size freq array (26 size ka), no extra space based on input

    string s, p;
    getline(cin, s);                  // input main string
    getline(cin, p);                  // input pattern string

    vector<int> arr(26, 0);           // character frequency of pattern

    int m = s.length();
    int n = p.length();

    for (char &ch : p)               
        arr[ch - 'a']++;              // pattern ke characters ka freq count kar liya

    int i = 0, j = 0;
    vector<int> result;              // final result vector

    while (j < m)
    {
        arr[s[j] - 'a']--;            // current window mein character hata rahe hain

        if (j - i + 1 == n)           // window size == pattern size
        {
            if (arr == vector<int>(26, 0))    // agar freq match karta hai
                result.push_back(i);          // to starting index store kar lo

            arr[s[i] - 'a']++;        // window ko slide karne se pehle left char add karo
            i++;                      // left pointer aage badhao
        }

        j++;                          // right pointer aage badhao
    }

    for (int index : result)         
        cout << index << " ";         // print all starting indices of anagrams
    cout << endl;
}

int main()
{
    better();
    return 0;
}
