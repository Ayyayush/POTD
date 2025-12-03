#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    long long subcount = 0, sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            count++;
            sum += nums[j];
            if (sum * count < k)
            {
                subcount++;
            }
        }
    }

    cout << subcount << endl;
}

void better()
{
    // Time complexity: O(n), Space complexity: O(1)

    long long k = 10;                   // Given k value
    vector<int> nums = {2, 1, 3, 4, 5}; // Given nums array

    long long sum = 0, i = 0, j = 0, result = 0;

    while (j < nums.size())
    {
        sum += nums[j]; // Add current number to sum

        while (i <= j && sum * (j - i + 1) >= k)
        {                   // Check if the subarray satisfies condition
            sum -= nums[i]; // Remove the first element of the window
            i++;            // Move left pointer rightwards
        }

        result += (j - i + 1); // Add the number of subarrays to the result
        j++;                   // Move right pointer to the next element
    }

    cout << result << endl; // Print the final result
}

int main()
{
    better(); // Call the better function
    return 0;
}
