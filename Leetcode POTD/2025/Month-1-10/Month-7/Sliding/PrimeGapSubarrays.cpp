#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(N^2 * logN)       // Har subarray mein multiset banake min-max check ho raha hai
    // S.C. = O(N)                // Ek multiset ban raha hai har subarray ke liye

    int n, k; 
    cin >> n >> k;               // Array size aur diff limit input lo

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];    // Array input

    // Step 1: Sieve bana lo max range tak
    const int MAX = 50000; 
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;    // Multiple ko non-prime mark karo
            }
        }
    }

    int result = 0;   // Answer

    // Step 2: Har possible subarray check karo
    for (int i = 0; i < n; ++i) {
        multiset<int> primeSet;    // Current window ka prime set
        int primeCount = 0;

        for (int j = i; j < n; ++j) {
            if (isPrime[nums[j]]) {
                primeSet.insert(nums[j]);   // Prime mila toh daal do
                primeCount++;
            }

            if (primeCount >= 2) {
                int minPrime = *primeSet.begin();
                int maxPrime = *primeSet.rbegin();

                if (maxPrime - minPrime <= k) {
                    result++;   // Valid subarray mila
                }
            }
        }
    }

    cout << result << endl;   // Final answer
}

void better()
{
    // T.C. = O(N logN)         // Sliding window + multiset operations
    // S.C. = O(N)              // Ek hi multiset chalta hai window mein

    int n, k;
    cin >> n >> k;             // Array size aur diff limit input lo

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];    // Array input

    // Step 1: Sieve bana lo max range tak
    const int MAXN = 100000;
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;   // Multiple ko non-prime mark karo
            }
        }
    }

    // Step 2: Sliding window + multiset se min-max track karo
    int l = 0, r = 0;
    int res = 0;
    int prev = -1, curr = -1;

    multiset<int> ms;

    while (r < n) {
        if (isPrime[nums[r]]) {
            prev = curr;
            curr = r;
            ms.insert(nums[r]);    // Prime mila toh window mein daal do
        }

        // Agar diff limit exceed ho rahi ho toh left se shrink karo
        while (!ms.empty() && (*ms.rbegin() - *ms.begin() > k)) {
            if (isPrime[nums[l]]) {
                ms.erase(ms.find(nums[l]));
            }
            l++;
        }

        // Agar window mein at least 2 primes hain toh count karo
        if (ms.size() >= 2) {
            res += (prev - l + 1);  // Valid left boundaries ko add karo
        }

        r++;
    }

    cout << res << endl;   // Final answer
}

int main()
{
    // brute();
    better();
    return 0;
}
