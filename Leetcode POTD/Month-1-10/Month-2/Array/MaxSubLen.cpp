#include <bits/stdc++.h>
using namespace std;

// Brute force approach to find the longest increasing or decreasing subsequence
void brute()           // O(N^3)
 {
    int s;
    cin >> s; // Input size of array
    vector<int> nums(s);
    
    // Input array elements
    for (int i = 0; i < s; i++) {
        cin >> nums[i];
    }

    int maxleninc = 1, maxlendec = 1;
    
    // Checking for longest increasing or decreasing subsequence
    for (int i = 0; i < nums.size(); i++) {
        int length;
        for (int j = i + 1; j < nums.size(); j++) {
            
            // Checking for increasing subsequence
            if (nums[j] > nums[i]) {
                length = 1;
                for (int k = i; k <= j; k++) {
                    // Condition to maintain increasing order
                    if ( nums[k] <= nums[k - 1]) {
                        break;
                    }
                    length++;
                    maxleninc = max(length, maxleninc); // Update max increasing length
                }
            }
            // Checking for decreasing subsequence
            else if (nums[j] < nums[i]) {
                length = 1;
                for (int k = i; k <= j; k++) {
                    // Condition to maintain decreasing order
                    if ( nums[k] >= nums[k - 1]) {
                        break;
                    }
                    length++;
                    maxlendec = max(length, maxlendec); // Update max decreasing length
                }
            }
        }
    }
    
    // Maximum of longest increasing or decreasing subsequence
    int maxlength = max(maxleninc, maxlendec);
    cout << maxlength << endl; // Output result
}






void better()      // Time Complexity: O(N^2)     
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int maxleninc = 1, maxlendec = 1;          // Maximum length of increasing and decreasing subarrays

    for (int i = 0; i < n; i++)
    {
        int length;

        // Increasing subarray check
        if (i + 1 < n && nums[i + 1] > nums[i])
        {
            length = 1;
            for (int k = i + 1; k < n; k++)
            {
                if (nums[k] <= nums[k - 1])    // Jab tak increasing hai tab tak count badhaenge
                {
                    break;
                }
                length++;
                maxleninc = max(length, maxleninc);    // Maximum increasing length ko update karenge
            }
        }

        // Decreasing subarray check
        if (i + 1 < n && nums[i + 1] < nums[i])
        {
            length = 1;
            for (int k = i + 1; k < n; k++)
            {
                if (nums[k] >= nums[k - 1])    // Jab tak decreasing hai tab tak count badhaenge
                {
                    break;
                }
                length++;
                maxlendec = max(length, maxlendec);    // Maximum decreasing length ko update karenge
            }
        }
    }

    int maxlength = max(maxleninc, maxlendec);   // Dono me se maximum wala lenge
    cout << maxlength << endl;
}


   

int main() {
    brute(); // Call the brute force function
    return 0;
}
