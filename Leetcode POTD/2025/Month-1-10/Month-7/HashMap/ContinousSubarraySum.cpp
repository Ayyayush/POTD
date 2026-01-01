#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Time Complexity: O(N)                           // Ek pass mein pura array traverse ho raha hai
    // Space Complexity: O(K)                          // Map ke andar max K modulus values store ho sakti hain

    vector<int> nums = {23, 2, 4, 6, 7};               // Sample input
    int k = 6;                                         // Divisor value

    unordered_map<int, int> modIndexMap;              // Stores: mod value → first index seen
    modIndexMap[0] = -1;                              // Important: subarray from start needs this

    int prefixSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];                         // Update prefix sum
        int mod = prefixSum % k;                      // Modulo with k

        if (modIndexMap.count(mod)) {
            if (i - modIndexMap[mod] >= 2) {          // Subarray of length ≥ 2
                cout << "True" << endl;
                return;
            }
        } else {
            modIndexMap[mod] = i;                     // Store only first occurrence of mod
        }
    }

    cout << "False" << endl;                          // No valid subarray found
}

int main()
{
    better();
    return 0;
}
