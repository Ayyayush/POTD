#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int s1, s2, count1, i, j, k, flag, count2;
    cin >> s1 >> s2;
    cin.ignore();
    
    vector<string> words1(s1);
    for (i = 0; i < s1; i++)
    {
        getline(cin, words1[i]);
    }

    vector<string> words2(s2);
    for (i = 0; i < s2; i++)
    {
        getline(cin, words2[i]);
    }

    for (i = 0; i < words1.size(); i++)
    {
        count1 = 0;
        count2 = 0;

        for (j = 0; j < words2.size(); j++)
        {
            flag = 0; // Reset flag for each word in words2

            for (k = 0; k < words2[j].size(); k++)
            {
                // Check if the current character of words2[j] exists in words1[i]
                if (words1[i].find(words2[j][k]) == string::npos)
                {
                    count1++; // Increment count1 if any character is missing
                    break;    // Exit the loop since words2[j] is not a subset
                }
                else
                {
                    flag++; // Increment flag for each found character
                }
            }

            // Ensure all characters in words2[j] are found in words1[i]
            if (flag == words2[j].size())
            {
                count2++;
            }
        }

        // Condition to check if all words in words2 are subsets of words1[i]
        if (count1 == 0 && count2 >0)
        {
            cout << words1[i] << " ";
        }
    }
}


void better1()
  {
    int s1, s2, i, j, k, flag;
    cin >> s1 >> s2;
    cin.ignore();
    
    vector<string> words1(s1);
    for (i = 0; i < s1; i++)
    {
        getline(cin, words1[i]);
    }

    vector<string> words2(s2);
    for (i = 0; i < s2; i++)
    {
        getline(cin, words2[i]);
    }

    // Process words1
    for (i = 0; i < words1.size(); i++)
    {
        bool isValid = true; // Assume the current word is valid

        for (j = 0; j < words2.size(); j++)
        {
            vector<int> freq1(26, 0), freq2(26, 0); // Frequency arrays for 26 alphabets

            // Calculate frequency for words1[i]
            for (char c : words1[i])
            {
                freq1[c - 'a']++;
            }

            // Calculate frequency for words2[j]
            for (char c : words2[j])
            {
                freq2[c - 'a']++;
            }

            // Check if words1[i] satisfies the frequency of words2[j]
            for (k = 0; k < 26; k++)
            {
                if (freq1[k] < freq2[k])
                {
                    isValid = false; // If not, mark as invalid and break
                    break;
                }
            }

            if (!isValid)
            {
                break; // No need to check further if one word2[j] fails
            }
        }

        if (isValid)
        {
            cout << words1[i] << " "; // Output valid word
        }
    }  
}


void better2()
{
    int s1, s2, count1, i, j, k, flag, count2;
    cin >> s1 >> s2;
    cin.ignore();
    
    vector<string> words1(s1);
    for (i = 0; i < s1; i++)
    {
        getline(cin, words1[i]);
    }

    vector<string> words2(s2);
    for (i = 0; i < s2; i++)
    {
        getline(cin, words2[i]);
    }

    for (i = 0; i < words1.size(); i++)
    {
        count1 = 0;  // Tracks invalid words from words2
        count2 = 0;  // Tracks valid words from words2

        for (j = 0; j < words2.size(); j++)
        {
            flag = 0; // Reset flag for each word in words2

            for (k = 0; k < words2[j].size(); k++)
            {
                // Count occurrences of words2[j][k] in words1[i]
                int freq1 = count(words1[i].begin(), words1[i].end(), words2[j][k]);
                int freq2 = count(words2[j].begin(), words2[j].end(), words2[j][k]);

                // Check if frequency in words1[i] is less than required
                if (freq1 < freq2)
                {
                    count1++;  // Increment count1 if a character is missing or insufficient
                    break;     // Exit loop since words2[j] cannot be satisfied
                }
                else
                {
                    flag++;  // Increment flag for each character matched
                }
            }

            // Ensure all characters in words2[j] are valid subsets of words1[i]
            if (flag == words2[j].size())
            {
                count2++;
            }
        }

        // Output if all words in words2 are valid subsets of words1[i]
        if (count1 == 0 && count2 > 0)
        {
            cout << words1[i] << " ";
        }
    }
}


void optimal()
{
    
}

int main()
{
    optimal();
    return 0;
}
