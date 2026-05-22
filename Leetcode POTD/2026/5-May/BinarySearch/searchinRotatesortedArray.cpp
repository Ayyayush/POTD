class Solution {
public:
    int search(vector<int>& nums, int target) {

        auto index=find(nums.begin(),nums.end(),target)-nums.begin();
        return index!=nums.size()?index:-1;
        
    }
};

class Solution {
public:

    /*
        ! Approach : Binary Search on Rotated Sorted Array
        ! T.C. -> O(log n)
        ! S.C. -> O(1)
    */

    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target)
            {
                return mid;                           // target found
            }

            // ! Left half is sorted
            if(nums[l] <= nums[mid])
            {
                // ! Target lies in left sorted half
                if(target >= nums[l] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            // ! Right half is sorted
            else
            {
                // ! Target lies in right sorted half
                if(target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;                                    // always give if exists
    }
};