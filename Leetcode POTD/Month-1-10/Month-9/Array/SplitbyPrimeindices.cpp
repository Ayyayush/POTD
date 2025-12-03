class Solution {
public:
    long long n = 1000000;
    vector<bool> prime;

    Solution() {
        prime.resize(n, true);          // Resize prime vector to size 'n' (index range: 0 to n-1)
        sieve();                        // Call sieve during construction
    }

    void sieve() {
        prime[0] = prime[1] = false;    // 0 and 1 are not prime
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;   // Mark all multiples of i as not prime
                }
            }
        }
    }

    long long splitArray(vector<int>& nums) {
        vector<int> a, b;
        for (int i = 0; i < nums.size(); i++) {
            if (prime[i]) {
                a.push_back(nums[i]);   // If index is prime
            } else {
                b.push_back(nums[i]);   // If index is not prime
            }
        }

        long long s1 = accumulate(a.begin(), a.end(), 0LL);  // Long long sum
        long long s2 = accumulate(b.begin(), b.end(), 0LL);

        return abs(s1 - s2);            // Return absolute difference
    }
};
