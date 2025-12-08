class Solution:
    def searchRange(self, nums, target):
        # Result array to store first and last positions
        result = [-1, -1]

        # -------------------------
        # Find the first occurrence
        # -------------------------
        for i in range(len(nums)):
            if nums[i] == target:                    # check if element matches target
                result[0] = i                        # store first index
                break                                # stop after first match

        # If first occurrence not found → target not present
        if result[0] == -1:
            return result

        # -------------------------
        # Find the last occurrence
        # -------------------------
        for i in range(len(nums) - 1, -1, -1):       # loop from end to start
            if nums[i] == target:
                result[1] = i                        # store last index
                break

        return result



        
/********************************************** C++ **********************************************/
//Approach-1 (Using Two Custom Binary Search)
//T.C : O(nlogn)
class Solution {
public:
    int find_first_position(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                result = mid; //possibly my answer
                r = mid-1;     //but lets look at left more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    
    int find_last_position(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                result = mid; //possibly my answer
                l = mid+1;   //but lets look at right more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = find_first_position(nums, target);
        int r = find_last_position(nums, target);
        
        return {l, r};
    }
};




class Solution:
    def searchRange(self, nums, target):

        # ----------------------------------------------------------
        # Helper function to find the first or last occurrence index
        # ----------------------------------------------------------
        def binarySearch(findFirst):
            left, right = 0, len(nums) - 1
            index = -1                                      # will store answer

            while left <= right:
                mid = (left + right) // 2

                if nums[mid] == target:
                    index = mid                             # store possible answer
                    if findFirst:
                        right = mid - 1                     # move left for first occurrence
                    else:
                        left = mid + 1                      # move right for last occurrence
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1

            return index

        # ----------------------------------------------------------
        # Find first and last indices using binary search
        # ----------------------------------------------------------
        first = binarySearch(True)                          # find first occurrence
        last = binarySearch(False)                          # find last occurrence

        return [first, last]
