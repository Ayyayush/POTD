class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        # merge nums2 into nums1
        for x in nums2:
            nums1.append(x)

        nums1.sort()
        n = len(nums1)

        # if odd length → return middle element
        if n % 2 != 0:
            return float(nums1[n // 2])

        # if even length → average of two middle elements
        else:
            mid1 = nums1[n // 2 - 1]
            mid2 = nums1[n // 2]
            return (mid1 + mid2) / 2




#include <bits/stdc++.h>
using namespace std;

void optimal() 
{
    /*  
        APPROACH → Binary Search on Smaller Array
        -------------------------------------------------
        We partition both arrays such that:
            - Left half has (n+m+1)/2 elements
            - All elements in left_half <= right_half

        T.C. → O(log(min(n1, n2)))
        S.C. → O(1)
    */

    // ---------------- HARD CODED INPUT ----------------
    vector<int> a = {1, 3, 8, 9, 15};           // hardcoded array 1
    vector<int> b = {7, 11, 18, 19};            // hardcoded array 2
    // --------------------------------------------------

    // Ensuring binary search runs on the smaller array
    if(a.size() > b.size()) swap(a, b);

    int n = a.size();
    int m = b.size();

    int low = 0, high = n;

    while(low <= high)
    {
        int cut1 = (low + high) / 2;                    // partition in a
        int cut2 = (n + m + 1) / 2 - cut1;              // partition in b

        int left1  = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int left2  = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int right1 = (cut1 == n) ? INT_MAX : a[cut1];
        int right2 = (cut2 == m) ? INT_MAX : b[cut2];

        // Check if we found the perfect partition
        if(left1 <= right2 && left2 <= right1)
        {
            if((n + m) % 2 == 1)
            {
                cout << max(left1, left2);              // median for odd length
                return;
            }

            double median = (max(left1, left2) + min(right1, right2)) / 2.0;
            cout << median;                              // median for even length
            return;
        }
        else if(left1 > right2)
        {
            high = cut1 - 1;                             // take fewer elements from a
        }
        else
        {
            low = cut1 + 1;                              // take more elements from a
        }
    }
}

int main()
{
    optimal();
    return 0;
}
