#include <bits/stdc++.h>
using namespace std;

/**
 * ✅ Approach - Brute Force (Check all subarrays)
 * 🔸 T.C. = O(n^2)
 * 🔸 S.C. = O(n)   (unordered_map used for each subarray)
 */
void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int maxcount = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<int, int> mp;
        for (int j = i; j < n; j++) {
            mp[nums[j]]++;
            if (mp.size() <= 2) {
                maxcount = max(maxcount, j - i + 1);
            } else {
                break;               // zyada distinct elements mil gaye
            }
        }
    }

    cout << maxcount << endl;
}


/**
 * ✅ Approach - Sliding Window + HashMap
 * 🔸 T.C. = O(n)
 * 🔸 S.C. = O(n)   (unordered_map stores freq of at most 2 elements)
 */
void better()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int maxcount = 0;
    int i = 0, j = 0;
    unordered_map<int, int> mp;

    while (j < n) {
        mp[nums[j]]++;

        while (mp.size() > 2 && i < n) {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
        }

        if (mp.size() <= 2) {
            maxcount = max(maxcount, j - i + 1);
        }

        j++;
    }

    cout << maxcount << endl;
}

int main()
{
    // brute();
    better();
    return 0;
}
