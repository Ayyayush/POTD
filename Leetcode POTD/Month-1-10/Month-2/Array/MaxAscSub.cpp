#include <bits/stdc++.h>
using namespace std;

// Brute force approach to find the longest increasing or decreasing subsequence
void brute() // O(N^3)
{
    int s;
    cin >> s; // Input size of array
    vector<int> nums(s);

    // Input array elements
    for (int i = 0; i < s; i++)
    {
        cin >> nums[i];
    }

    int maxsum = -1;

    // Checking for longest increasing or decreasing subsequence
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            // Checking for decreasing subsequence
            if (nums[j] > nums[i])
            {
                int sum = nums[i]; // Initialize sum with the first element
                for (int k = i + 1; k <= j; k++)
                {
                    // Condition to maintain increasing order
                    if (nums[k] <= nums[k - 1])
                    {
                        break;
                    }
                   
                    sum += nums[k];
                    maxsum = max(sum, maxsum);
                }
            }
        }
    }

    cout << maxsum << endl; // Output result
}


void better() // Time Complexity: O(N^2)
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int maxsum=0;

    for (int i = 0; i < n; i++)
    {
        int sum=nums[i];

        // Increasing subarray check
        if (i + 1 < n   && nums[i + 1] > nums[i])
        {
            sum = nums[i];
            for (int k = i + 1; k < n; k++)
            {
                if (nums[k] <= nums[k - 1]) // Jab tak increasing hai tab tak count badhaenge
                {
                    break;
                }
                 sum=sum+nums[k];
                 maxsum = max(sum, maxsum); 
               
               
            }
        }
maxsum = max(sum, maxsum); 
    }
cout<<maxsum<<endl;
   
}



int main()
{
    brute(); // Call the brute force function
    return 0;
}
