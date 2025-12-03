#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(N^2 * M)  -->  N = arr.size(), M = avg length of each string
    // S.C. = O(1)

    vector<string> arr = {"ab", "cd", "ae"};               // 🔹 Hardcoded input
    int count = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int vowel = 0, conso = 0;

        for(int j = i; j < arr.size(); j++)
        {
            for(int k = 0; k < arr[j].size(); k++)
            {
                char ch = arr[j][k];

                // 🔍 Check if it's vowel or consonant using string::find
                if(string("aeiouAEIOU").find(ch) != string::npos)
                {
                    vowel++;
                }
                else
                {
                    conso++;
                }
            }

            // ✅ Check if current subarray is balanced
            if(conso == vowel)
            {
                count++;
            }
        }
    }

    cout << "Balanced subarrays count = " << count << endl;
}


// Hashing + Prefix Difference Technique
// 🔹 T.C. = O(N * M)      (Each word traversed only once)
// 🔹 S.C. = O(N)          (For storing prefix diff counts)

void optimal()
{
    vector<string> arr = {"a", "bc", "e", "fg"};         // 🔸 Sample input

    unordered_map<int, int> freq;                       // Stores frequency of diff (vowel - consonant)
    freq[0] = 1;                                        // Base diff = 0 (for prefix)

    int count = 0;
    int vowel = 0, conso = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (char ch : arr[i])
        {
            if (string("aeiouAEIOU").find(ch) != string::npos)
                vowel++;
            else
                conso++;
        }

        int diff = vowel - conso;

        count += freq[diff];                            // ✅ Count subarrays with same diff seen before
        freq[diff]++;                                   // 🔄 Update frequency of current diff
    }

    cout << count << endl;
}
 
int main()
{
    optimal();
    return 0;
}
