#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Brute force (check all subarrays for disorder)
    // T.C. = O(n^2), S.C. = O(1)

    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int n = nums.size();
    int left = n, right = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[i])
            {
                left = min(left, i);   // left boundary of unsorted
                right = max(right, j); // right boundary
            }
        }
    }

    if (right > left)
        cout << "Length: " << right - left + 1 << endl;
    else
        cout << "Length: 0" << endl;
}

void better()
{
    // Approach: Sort and compare with original
    // T.C. = O(n log n), S.C. = O(n)

    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    vector<int> sorted = nums;

    sort(sorted.begin(), sorted.end());

    int first = -1, last = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != sorted[i])
        {
            first = i;
            break;
        }
    }

    for (int j = nums.size() - 1; j >= 0; j--)
    {
        if (nums[j] != sorted[j])
        {
            last = j;
            break;
        }
    }

    if (first == -1)
        cout << "Length: 0" << endl;
    else
        cout << "Length: " << last - first + 1 << endl;
}

void optimal()
{
    // Approach: Traverse to find out-of-order min and max
    // T.C. = O(n), S.C. = O(1)

    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int n = nums.size();
    int maxOutOfPlace = INT_MIN;
    int minOutOfPlace = INT_MAX;

    // Find max in unsorted region
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
            maxOutOfPlace = max(maxOutOfPlace, nums[i - 1]);
    }

    // Find min in unsorted region
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
            minOutOfPlace = min(minOutOfPlace, nums[i + 1]);
    }

    if (maxOutOfPlace == INT_MIN)
    {
        cout << "Length: 0" << endl; // Already sorted
        return;
    }

    int left = 0, right = n - 1;

    while (left < n && nums[left] <= minOutOfPlace)
        left++; // Find left boundary
    while (right >= 0 && nums[right] >= maxOutOfPlace)
        right--; // Find right boundary

    cout << "Length: " << right - left + 1 << endl;
}

int main()
{
    brute();
    cout << "----------------\n";
    better();
    cout << "----------------\n";
    optimal();
    return 0;
}
