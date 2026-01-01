class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> arr;
            for (int j = i; j < nums.size(); j++)
            {
                bool flag = true;
                arr.push_back(nums[j]);
                if (arr.size() >=3)
                {
                    int diff = arr[0] - arr[1];
                    for (int k = 0; k < arr.size() - 1; k++)
                    {
                        if (arr[k] - arr[k + 1] != diff)
                        {
                            flag = false;
                            break;
                        }
                    }
                      if (flag)
                    count++;
           
                }
               }
        }
        return count;
    }
};


#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Time Complexity: O(N^2 * 26)     (N^2 substrings, each checking 26-char map)
    // Space Complexity: O(26)          (frequency map of lowercase characters)

    string s;
    cin >> s;

    long long sum = 0;						// Final answer

    for (int i = 0; i < s.size(); i++)		// Start of substring
    {
        unordered_map<char, int> mp;		// Frequency map for current substrings

        for (int j = i; j < s.size(); j++)	// End of substring
        {
            mp[s[j]]++;						// Add current character to frequency map

            int minFreq = INT_MAX, maxFreq = INT_MIN;

            for (auto &it : mp)				// Find min and max freq in map
            {
                maxFreq = max(maxFreq, it.second);
                minFreq = min(minFreq, it.second);
            }

            sum += (maxFreq - minFreq);		// Beauty = max - min freq
        }
    }

    cout << sum << endl;
}

int main()
{
    better();
    return 0;
}
