#include <bits/stdc++.h>
using namespace std;



void brute()
{
    // Time Complexity: O(N^3)                 // Teen nested loops: i, j, k
    // Space Complexity: O(N^3) (approx)       // Saare sums ko store kiya arr mein

    vector<int> nums = {-1, 2, 1, -4};         // Example input
    int target = 1;                             // Target sum

    vector<int> arr;                            // Har possible sum ko store karega
    int mindiff = INT_MAX;                      // Minimum difference track karne ke liye
    int minsum;                                 // Answer store karega

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];   // Triplet ka sum
                arr.push_back(sum);                      // Array mein push karo
            }
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (abs(arr[i] - target) < mindiff) {
            mindiff = abs(arr[i] - target);              // Naya min diff mila to update karo
            minsum = arr[i];                             // Answer bhi update karo
        }
    }

    cout << minsum << endl;                              // Final answer print karo
}


void better()
{
    // Time Complexity: O(N^3)                     // Teen nested loops
    // Space Complexity: O(1)                       // Sirf variables, no extra arrays

    vector<int> nums = {-1, 2, 1, -4};             // Example input
    int target = 1;                                 // Target value

    int mindiff = INT_MAX;                          // Minimum diff store karne ke liye
    int minsum;                                     // Closest sum store karega
    int n = nums.size();

    // Brute force triplets
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < mindiff) {
                    mindiff = abs(sum - target);   // Naya min diff mila toh update karo
                    minsum = sum;                  // Sum bhi update karo
                }
            }
        }
    }

    cout << minsum << endl;                        // Answer print karo
}


void optimal()
{
    // Time Complexity: O(N^2)           // Sorting + nested loop + two-pointer
    // Space Complexity: O(1)             // No extra space except variables

    vector<int> nums = {-1, 2, 1, -4};   // Example input
    int target = 1;

    sort(nums.begin(), nums.end());      // Pehle sort karo array ko

    int n = nums.size();
    int closestSum = INT_MAX;             // Answer store karega
    int mindiff = INT_MAX;                // Minimum difference track karega

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;                 // Do pointer bacha hua array ke liye
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(sum - target);

            if (diff < mindiff)
            {
                mindiff = diff;           // Naya min difference mile to update karo
                closestSum = sum;         // Aur sum bhi update karo
            }

            if (sum < target)
                left++;                   // Chhota hai to bada banane ke liye left++
            else
                right--;                  // Bada hai to chhota banane ke liye right--
        }
    }

    cout << closestSum << endl;           // Final answer print karo
}

int main()
{
    better();
    return 0;
}
