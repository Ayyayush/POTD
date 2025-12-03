#include <bits/stdc++.h>
using namespace std;

// ✅ Approach: Brute Force - Try all triplets
// ✅ Time Complexity: O(n^3)
// ✅ Space Complexity: O(1)

void brute()
{
    int n;
    cin >> n;                                 // vector size input lo
    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];   // vector elements input lo

    int count = 0;                             // valid triangle triplets count

    for(long long i = 0; i < n - 2; i++) {
        for(long long j = i + 1; j < n; j++) {
            for(long long k = j + 1; k < n; k++) {
                // ✅ Triangle banne ke liye 3 conditions check karo
                if(nums[i] + nums[j] > nums[k] &&
                   nums[i] + nums[k] > nums[j] &&
                   nums[j] + nums[k] > nums[i]) 
                {
                    count++;                  // valid triangle mila
                }
            }
        }
    }

    cout << count << endl;                    // total valid triangles print karo
}



// ✅ Approach: Sorting + 2 Pointers (Greedy check from back)
// ✅ Time Complexity: O(n^2)
// ✅ Space Complexity: O(1)

void better()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());          // Sorting is must for two pointer

    int count = 0;

    for(int k = n - 1; k >= 2; k--)           // Fix third side (largest)
    {
        int i = 0, j = k - 1;                 // Two pointer from start and end

        while(i < j)
        {
            if(nums[i] + nums[j] > nums[k])  // Triangle possible
            {
                count += (j - i);            // All pairs between i and j are valid
                j--;
            }
            else
            {
                i++;                         // Move i forward to increase sum
            }
        }
    }

    cout << count << endl;                   // Print total triangle count
}

int main()
{
    better();
    return 0;
}
