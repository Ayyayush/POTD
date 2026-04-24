/************************************************************ C++ *****************************************************/

/*******************************************************
 * 🔴 Approach 1: Brute Force
 * T.C : O(n^2)
 * S.C : O(n)
 *******************************************************/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long n = nums.size(), distance;

        vector<long long> arr(n, 0);

        for(int i = 0; i < n; i++) {
            distance = 0;

            for(int j = 0; j < n; j++) {
                if(nums[j] == nums[i] && j != i) {
                    distance += abs(i - j);
                }
            }

            arr[i] = distance;
        }

        return arr;
    }
};


/*******************************************************
 * 🟡 Approach 2: HashMap (Store Indices)
 * T.C : O(n^2) worst case
 * S.C : O(n)
 *******************************************************/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        long long n = nums.size();
        long long distance;

        unordered_map<int, vector<int>> mp;

        // Store indices of each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> arr(n, 0);

        for (int i = 0; i < n; i++) {

            distance = 0;

            vector<int> indexes = mp[nums[i]];

            for (int idx = 0; idx < indexes.size(); idx++) {

                if (i != indexes[idx]) {
                    distance += abs(i - indexes[idx]);
                }
            }

            arr[i] = distance;
        }

        return arr;
    }
};


/*******************************************************
 * 🟢 Approach 3: Prefix Sum + Map (Optimal)
 * T.C : O(n)
 * S.C : O(n)
 *******************************************************/
class Solution {
public:
    typedef long long ll;

    vector<ll> distance(vector<int>& nums) {

        int n = nums.size();
        vector<ll> arr(n, 0);

        unordered_map<int, ll> indexSum;   // nums[i] -> sum of indices
        unordered_map<int, ll> indexCount; // nums[i] -> frequency

        // Left to Right
        for(int i = 0; i < n; i++) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += freq * i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        indexSum.clear();
        indexCount.clear();

        // Right to Left
        for(int i = n - 1; i >= 0; i--) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += sum - freq * i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        return arr;
    }
};