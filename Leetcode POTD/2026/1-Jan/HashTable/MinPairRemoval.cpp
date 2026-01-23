#include <bits/stdc++.h>
using namespace std;

void brute()
{
    /**
     * ! LeetCode - 3507 (Minimum Pair Removal)
     *
     * 💭 Thought Process (Brute Force / Simulation):
     *
     * - Constraints chhote hain, so brute-force simulation allowed hai
     * - Jab tak array sorted nahi ho jata:
     *     1) adjacent elements ke pair ka minimum sum dhundo
     *     2) us pair ko merge karo (sum bana do)
     *     3) second element ko remove kar do
     *     4) operation count increase karo
     *
     * - End mein count return / print kar do
     */

    vector<int> arr = {5, 2, 3, 1};
    int count = 0;

    // Jab tak array sorted nahi ho jaata
    while (!is_sorted(arr.begin(), arr.end()))
    {
        int minSum = INT_MAX;
        int index = -1;

        // Step 1: minimum adjacent pair sum dhundhna
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] + arr[i + 1] < minSum)
            {
                minSum = arr[i] + arr[i + 1];
                index = i;
            }
        }

        // Step 2: selected pair ko merge karna
        arr[index] = arr[index] + arr[index + 1];

        // Step 3: second element ko remove karna
        arr.erase(arr.begin() + index + 1);

        // Step 4: operation count badhao
        count++;
    }

    cout << "Minimum operations = " << count << endl;
}



class Solution {
public:

    // Finds the index of the adjacent pair with minimum sum
    int minpairsum(vector<int>& nums) {
        int minsum = INT_MAX;
        int index = -1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] + nums[i + 1] < minsum)
            {
                minsum = nums[i] + nums[i + 1];
                index = i;
            }
        }
        return index;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        // Loop until array becomes sorted
        while (!is_sorted(nums.begin(), nums.end())) {

            // Safety check: need at least 2 elements
            if (nums.size() < 2) break;

            int index = minpairsum(nums);

            // Merge the minimum-sum adjacent pair
            nums[index] = nums[index] + nums[index + 1];

            // ❌ ERROR FIX: remove ONLY the second element of the pair
            nums.erase(nums.begin() + index + 1);

            ops++;
        }
        return ops;
    }
};



// javascript code 
/**
 * @param {number[]} nums
 * @return {number}
 */

// Finds index of adjacent pair with minimum sum
function minpairsum(nums) {
    let minsum = Infinity;          // stores minimum sum
    let index = -1;                // stores index of pair

    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] + nums[i + 1] < minsum) {
            minsum = nums[i] + nums[i + 1];
            index = i;
        }
    }
    return index;
}

var minimumPairRemoval = function(nums) {
    let ops = 0;

    // Helper function to check if array is sorted
    function isSorted(arr) {
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    }

    // Keep merging until array becomes sorted
    while (!isSorted(nums)) {

        // Safety check
        if (nums.length < 2) break;

        let index = minpairsum(nums);

        // Merge the minimum-sum adjacent pair
        nums[index] = nums[index] + nums[index + 1];

        // Remove the second element of the merged pair
        nums.splice(index + 1, 1);

        ops++;
    }

    return ops;
};


int main()
{
    brute();
    return 0;
}
