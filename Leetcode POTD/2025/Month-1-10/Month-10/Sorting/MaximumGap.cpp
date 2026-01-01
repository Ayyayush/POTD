#include <bits/stdc++.h>
using namespace std;

// Brute Force (Sorting)
// T.C. = O(N log N)              // sorting lag rahi hai
// S.C. = O(1)                     // constant extra space
void brute() {
    vector<int> nums = {3, 6, 9, 1};    // hardcoded input

    if (nums.size() < 2) {
        cout << "Brute answer = 0" << endl;
        return;
    }

    sort(nums.begin(), nums.end());     // sort kar diya

    int maxdiff = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++) {
        maxdiff = max(maxdiff, nums[i + 1] - nums[i]);   // consecutive diff check
    }

    cout << "Brute answer = " << maxdiff << endl;
}



// Optimal (Bucket Sort / Pigeonhole Principle)
// T.C. = O(N)                         // linear bucket filling and traversal
// S.C. = O(N)                         // buckets ke liye extra arrays
void optimal() {
    vector<int> nums = {3, 6, 9, 1};    // hardcoded input

    if (nums.size() < 2) {
        cout << "Optimal answer = 0" << endl;
        return;
    }

    int n = nums.size();
    int mini = *min_element(nums.begin(), nums.end());    // minimum element
    int maxi = *max_element(nums.begin(), nums.end());    // maximum element

    if (mini == maxi) {   // agar sab same hai
        cout << "Optimal answer = 0" << endl;
        return;
    }

    int bucketSize = max(1, (maxi - mini) / (n - 1));     // min gap size
    int bucketCount = (maxi - mini) / bucketSize + 1;     // bucket count

    vector<int> bucketMin(bucketCount, INT_MAX);          // har bucket ka min
    vector<int> bucketMax(bucketCount, INT_MIN);          // har bucket ka max
    vector<bool> bucketUsed(bucketCount, false);          // flag for used bucket

    // Buckets fill karna
    for (int num : nums) {
        int idx = (num - mini) / bucketSize;              // bucket index
        bucketMin[idx] = min(bucketMin[idx], num);
        bucketMax[idx] = max(bucketMax[idx], num);
        bucketUsed[idx] = true;
    }

    // Traverse buckets to find max gap
    int prevMax = mini, maxGap = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i]) continue;                    // empty bucket skip
        maxGap = max(maxGap, bucketMin[i] - prevMax);    // gap between buckets
        prevMax = bucketMax[i];
    }

    cout << "Optimal answer = " << maxGap << endl;
}



int main() {
    brute();
    optimal();
    return 0;
}
