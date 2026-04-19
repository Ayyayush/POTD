class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int maxDist = 0 ;

            for (int i = 0; i < n1 - 1; i++) {
            for (int j = i + 1; j < n2; j++) {
                if (nums1[i] <= nums2[j]) {
                    maxDist = max(maxDist, j - i);
                }
            }
        }

        return maxDist;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int maxDist = 0;

        for (int i = 0; i < n1; i++) {
            int left = i, right = n2-1 ;

            while (left <= right) 
            {
                int mid = left + (right - left) / 2;

                if (nums2[mid] >= nums1[i])
                {
                    maxDist = max(maxDist, mid - i);
                     left = mid + 1;
                } 
                else
                {
                     right = mid - 1;
                }
            }
        }

        return maxDist;   // ❗ moved inside function
    }
};