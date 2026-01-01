#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int s, i, j, sum ;
    int maxsum = INT_MIN;
    cin >> s;
    vector<int> nums(s);
    vector<int> arr;
    for (i = 0; i < s; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin>>k;
    for (i = 0; i < nums.size(); i++)
    {
        sum=0;
        for (j = i + 1; j < (i + k),j<nums.size(); j++)
        {
            sum = nums[i] + nums[j];
            if (sum > maxsum)
            {
                maxsum=sum;
                arr.push_back(i);
            }
            i++;
        }
    }

    int size = arr.size();
    for (i = max(0, size - 3); i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}



       vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
       {
        int n = nums.size();
        vector<int> sum(n + 1, 0); // Prefix sum array
        
        // Compute prefix sums
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        // Arrays to store the best indices
        vector<int> left(n, 0);
        vector<int> right(n, n - k);

        // Compute `left` array
        int maxSum = sum[k] - sum[0];
        for (int i = k; i < n; ++i) {
            if (sum[i + 1] - sum[i + 1 - k] > maxSum) {
                maxSum = sum[i + 1] - sum[i + 1 - k];
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }

        // Compute `right` array
        maxSum = sum[n] - sum[n - k];
        for (int i = n - k - 1; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= maxSum) {
                maxSum = sum[i + k] - sum[i];
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }

        // Find the best combination
        vector<int> result(3, -1);
        maxSum = 0;
        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int l = left[mid - 1];
            int r = right[mid + k];
            int currentSum = (sum[mid + k] - sum[mid]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result = {l, mid, r};
            }
        }

        return result;
    }



int main() {
    // Example input
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;

    
    vector<int> result = maxSumOfThreeSubarrays(nums, k);

    // Output the result
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

