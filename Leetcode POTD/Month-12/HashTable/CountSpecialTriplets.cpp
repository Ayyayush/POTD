class Solution {
public:
    /*
     * Helper function to count valid triplets using frequency arrays
     * Counts (i, j, k) such that:
     *    dhjbchjdcbfdd[i] == 2 * dhjbchjdcbfdd[j] and dhjbchjdcbfdd[k] == 2 * dhjbchjdcbfdd[j]
     *    with i < j < k
     */
    long long countTriplets(const vector<int>& dhjbchjdcbfdd, int cap, const int MOD) {
        vector<int> rt(cap + 1, 0), lt(cap + 1, 0);

        // Build frequency map for suffix
        for (int x : dhjbchjdcbfdd) {
            if (x <= cap)
                rt[x]++;
        }

        long long res = 0;

        // Traverse j from left to right
        for (int j = 0; j < dhjbchjdcbfdd.size(); ++j) {
            int v = dhjbchjdcbfdd[j];
            rt[v]--; // remove current j from right suffix

            int t = v * 2;  // looking for dhjbchjdcbfdd[i] == dhjbchjdcbfdd[k] == 2 * dhjbchjdcbfdd[j]

            if (t <= cap) {
                long long l = lt[t];   // count of t before j
                long long r = rt[t];  // count of t after j

                res = (res + l * r) % MOD;
            }

            lt[v]++; // add current j to prefix
        }

        return res;
    }

    /*
     * Main function as required by LeetCode signature
     */
    int specialTriplets(vector<int>& dhjbchjdcbfdd) {
        const int MOD = 1'000'000'007;

        int maxVal = *max_element(dhjbchjdcbfdd.begin(), dhjbchjdcbfdd.end());
        int cap = maxVal * 2;

        return static_cast<int>(countTriplets(dhjbchjdcbfdd, cap, MOD));
    }
};




/**Approach -2  */class Solution {
public:
    int specialTriplets(vector<int>& nums) {

        const int MOD = 1'000'000'007;

        // Map: value -> all indices where it appears
        unordered_map<long long, vector<int>> valueIndices;

        for (int i = 0; i < nums.size(); i++) {
            valueIndices[nums[i]].push_back(i);     // store each index
        }

        long long totalTriplets = 0;

        // Traverse possible middle index j
        for (int j = 0; j < nums.size(); j++) {

            long long middleValue = nums[j];
            long long requiredValue = 2LL * middleValue;     // value required on both sides

            // If required val not present → skip
            if (valueIndices.find(requiredValue) == valueIndices.end())
                continue;

            // reference to the vector of all indices where nums[x] = requiredValue
            const vector<int>& indicesList = valueIndices[requiredValue];

            // Count i < j → use binary search
            long long leftCount =
                lower_bound(indicesList.begin(), indicesList.end(), j) - indicesList.begin();

            // Count k > j → total - leftCount
            long long rightCount =
                indicesList.size() - leftCount;

            // Add triplets contributed by this j
            totalTriplets = (totalTriplets + (leftCount * rightCount) % MOD) % MOD;
        }

        return (int)totalTriplets;
    }
};
