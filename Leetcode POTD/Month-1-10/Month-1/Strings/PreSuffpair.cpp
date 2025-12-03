#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int s;
    cin >> s;
    cin.ignore();
    vector<string> nums(s);

    for (int i = 0; i < nums.size(); i++)
    {
        getline(cin, nums[i]);
    }

    int count = 0;
   

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                // Get lengths of both strings
                int len1 = nums[i].length();
                int len2 = nums[j].length();

                // str1 must not be longer than str2 for it to be a prefix or suffix
                if (len1 > len2) continue;

                // Check if nums[i] is both a prefix and suffix of nums[j]
                if (nums[j].substr(0, len1) == nums[i] && nums[j].substr(len2 - len1, len1) == nums[i]) {
                    count++;  // Increment count if valid
                }
            }
        }

    cout << count << endl;
}


void better()
{
    int s;
    cin >> s;
    cin.ignore();
    vector<pair<string, string>> nums(s); // Create a vector of pairs of strings
    int i, j, maxcount = 0, count=0;

    for (i = 0; i < s; i++)
    {
        string first, second; // Temporary strings to store input
        getline(cin, first);  // Get the first string from the user
        getline(cin, second); // Get the second string from the user

        nums[i] = make_pair(first, second); // Create a pair and store it in the vector
    }

        for (i = 0; i < words.size(); i++) {
            nums.push_back(make_pair(words[i], words[words.size() - 1 - i])); 
            // Pair first half with second half
        }

        // Step 2: Iterate through pairs and check if one is prefix and suffix of the other
        for (i = 0; i < nums.size(); i++) {
            count = 0; // Reset count for each prefix-suffix pair
            // Self-pair check
            if (nums[i].second.find(nums[i].first) != string::npos) {
                count++;
            }

            // Compare with other pairs
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[i].first.find(nums[j].first) != string::npos || 
                    nums[i].first.find(nums[j].second) != string::npos || 
                    nums[i].second.find(nums[j].first) != string::npos || 
                    nums[i].second.find(nums[j].second) != string::npos) {
                    
                    count++;
                }
            }
        }
        cout<<count<<endl;
}


int main()
{   
    brute();
    return 0;
}