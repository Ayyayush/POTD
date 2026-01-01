#include <bits/stdc++.h>
using namespace std;

/*
Approach: Brute (full double loop j = 0)
T.C. = O(n^2)
S.C. = O(1)
Fail Example (this approach can OVER-SWAP or give wrong result):
    nums = {75, 34, 30}  // expected: false (cannot swap across different-bit element that sits between)
Reason: redundant comparisons produce unintended swaps in some cases.
*/
void brute()
{
    // Example that shows wrong behavior for this brute style
    vector<int> nums = {75, 34, 30};

    for (int i = 0; i < (int)nums.size(); i++)
    {
        for (int j = 0; j < (int)nums.size(); j++)
        {
            if (nums[i] <= nums[j])
            {
                int seti = __builtin_popcount(nums[i]);
                int setj = __builtin_popcount(nums[j]);
                if (seti == setj)
                    swap(nums[i], nums[j]);
            }
        }
    }

    for (auto x : nums)
        cout << x << " ";
    cout << "\n";
    cout << (is_sorted(nums.begin(), nums.end()) ? "true" : "false") << "\n";
}

/*
Approach: Better (pairwise forward loop j = i+1)
T.C. = O(n^2)
S.C. = O(1)
Fail Example (this approach can MISS required swaps and give wrong result):
    nums = {8, 4, 2, 30, 15}  // expected: true, but this misses swaps between earlier indices sometimes
Reason: starting j = i+1 misses some valid rearrangements that require earlier comparisons/swaps chain.
*/
void better()
{
    vector<int> nums = {8, 4, 2, 30, 15};

    for (int i = 0; i < (int)nums.size(); i++)
    {
        for (int j = i + 1; j < (int)nums.size(); j++)
        {
            if (nums[i] <= nums[j])
            {
                int seti = __builtin_popcount(nums[i]);
                int setj = __builtin_popcount(nums[j]);
                if (seti == setj)
                    swap(nums[i], nums[j]);
            }
        }
    }

    for (auto x : nums)
        cout << x << " ";
    cout << "\n";
    cout << (is_sorted(nums.begin(), nums.end()) ? "true" : "false") << "\n";
}

/**
 * Approach
 * Adjacent elt
 * Swap karo if not sorted
 * If set bits are equal
 * this is the problem statement of bubble sort
 * Bubble sort ye kehta h ki
 * array pe pass karenge n-1 times
 * har ek paas mein sabse bada number last mein chala jayega
 *
 *
 */

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size() - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    int seta = __builtin_popcount(nums[j]);
                    int setb = __builtin_popcount(nums[j + 1]);
                    if (seta == setb)
                    {
                        swap(nums[j + 1], nums[j]);
                    }
                }
            }
        }

        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
        return is_sorted(nums.begin(), nums.end());
    }
};

/**
 * Approach -2
 * Better Approach
 * Ye problem solely bubble sort clear krne ke liye pucha ja sakta h
 * Hint for this approach == O(n) t.c
 * hum array ko segement mein divide kr skte h
 * jinn numbers mein set bit equal h unko ek sath rakho
 * but sorted order mein rakho
 * ab condition ye hona chahiye ki previous segement ka
 * largets elt currentr segemtn ke smallest elt se smaller hona chaiye
 *
 *
 */

// Approach-2 (Using simple segment sorting check)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        // Current Segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            if (__builtin_popcount(nums[i]) == numOfSetBits)
            {                                              // they belong to same segment
                maxOfSegment = max(maxOfSegment, nums[i]); // find max of current segment
                minOfSegment = min(minOfSegment, nums[i]); // find min of current segment
            }
            else
            { // Element belongs to a new segment

                if (minOfSegment < maxOfPrevSegment)
                { // ye bataya hai maine video me
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // new segment started now
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment)
        {
            return false;
        }
        return true;
    }
};
