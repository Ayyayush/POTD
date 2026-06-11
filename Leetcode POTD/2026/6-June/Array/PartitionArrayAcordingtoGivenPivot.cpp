/**
 * =====================================================================
 * ! PARTITION ARRAY ACCORDING TO GIVEN PIVOT
 * =====================================================================
 *
 * Given an array nums and a pivot value:
 *
 * 1. All elements smaller than pivot should appear on the left.
 * 2. All elements equal to pivot should appear in the middle.
 * 3. All elements greater than pivot should appear on the right.
 *
 * IMPORTANT:
 * - Relative order of elements < pivot must be maintained.
 * - Relative order of elements > pivot must be maintained.
 *
 * ---------------------------------------------------------------------
 * Approaches arranged in DESCENDING order of Space Complexity
 * (Higher S.C first)
 * ---------------------------------------------------------------------
 *
 * Approach 1 : Three Separate Vectors
 * T.C : O(n)
 * S.C : O(3n) ≈ O(n)
 *
 * Approach 2 : Count + Direct Placement
 * T.C : O(n)
 * S.C : O(n)
 *
 * Approach 3 : Two Pointers From Both Ends
 * T.C : O(n)
 * S.C : O(n)
 *
 * Approach 4 : Count Pivot + Single Result Vector
 * T.C : O(n)
 * S.C : O(n)
 *
 */

 /**
 * ---------------------------------------------------------------------
 * Approach 1 : Using 3 Separate Vectors
 * ---------------------------------------------------------------------
 *
 * Idea:
 *
 * lessPivot    -> stores elements < pivot
 * equalPivot   -> stores elements = pivot
 * greaterPivot -> stores elements > pivot
 *
 * Finally merge:
 *
 * lessPivot + equalPivot + greaterPivot
 *
 * Stable Partition
 * Order is preserved automatically.
 *
 * T.C : O(n)
 * S.C : O(3n) ≈ O(n)
 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        vector<int> lessPivot;
        vector<int> equalPivot;
        vector<int> greaterPivot;

        for(int i = 0; i < n; i++) {

            if(nums[i] < pivot) {
                lessPivot.push_back(nums[i]);
            }
            else if(nums[i] == pivot) {
                equalPivot.push_back(nums[i]);
            }
            else {
                greaterPivot.push_back(nums[i]);
            }
        }

        for(int &num : equalPivot) {
            lessPivot.push_back(num);
        }

        for(int &num : greaterPivot) {
            lessPivot.push_back(num);
        }

        return lessPivot;
    }
};


/**
 * ---------------------------------------------------------------------
 * Approach 2 : Count Frequencies Then Place Directly
 * ---------------------------------------------------------------------
 *
 * Step 1:
 * Count:
 * - elements < pivot
 * - elements = pivot
 *
 * Step 2:
 * Determine starting positions:
 *
 * i -> start of smaller elements
 * j -> start of pivot elements
 * k -> start of greater elements
 *
 * Step 3:
 * Traverse array once and place elements directly.
 *
 * Stable Partition
 * Relative ordering preserved.
 *
 * T.C : O(n)
 * S.C : O(n)
 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        int countless  = 0;
        int countequal = 0;

        for(int &num : nums) {

            if(num < pivot)
                countless++;

            else if(num == pivot)
                countequal++;
        }

        int i = 0;
        int j = countless;
        int k = countless + countequal;

        vector<int> result(n);

        for(int &num : nums) {

            if(num < pivot) {

                result[i] = num;
                i++;
            }
            else if(num == pivot) {

                result[j] = num;
                j++;
            }
            else {

                result[k] = num;
                k++;
            }
        }

        return result;
    }
};


/**
 * ---------------------------------------------------------------------
 * Approach 3 : Two Pointers From Both Ends
 * ---------------------------------------------------------------------
 *
 * Idea:
 *
 * Left scan:
 * Place all elements < pivot
 *
 * Right scan:
 * Place all elements > pivot
 *
 * Remaining middle positions:
 * Fill with pivot.
 *
 * Stable for both partitions because:
 * - Left side processed left -> right
 * - Right side processed right -> left
 *
 * T.C : O(n)
 * S.C : O(n)
 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        vector<int> result(n);

        int i = 0;
        int j = n - 1;

        int i_ = 0;
        int j_ = n - 1;

        while(i < n && j >= 0) {

            if(nums[i] < pivot) {

                result[i_] = nums[i];
                i_++;
            }

            if(nums[j] > pivot) {

                result[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        while(i_ <= j_) {

            result[i_] = pivot;
            i_++;
        }

        return result;
    }
};


/**
 * ---------------------------------------------------------------------
 * Approach 4 : Count Pivot + Single Result Vector
 * ---------------------------------------------------------------------
 *
 * Idea:
 *
 * Pass 1:
 * Store all elements smaller than pivot.
 * Count pivot occurrences.
 *
 * Pass 2:
 * Insert pivot count times.
 *
 * Pass 3:
 * Insert all elements greater than pivot.
 *
 * Stable Partition
 * Relative ordering preserved naturally.
 *
 * T.C : O(n)
 * S.C : O(n)
 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> result;

        int countPivot = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(nums[i] == pivot)
                countPivot++;

            if(nums[i] < pivot)
                result.push_back(nums[i]);
        }

        while(countPivot--) {
            result.push_back(pivot);
        }

        for(int i = 0; i < n; i++) {

            if(nums[i] > pivot)
                result.push_back(nums[i]);
        }

        return result;
    }
};