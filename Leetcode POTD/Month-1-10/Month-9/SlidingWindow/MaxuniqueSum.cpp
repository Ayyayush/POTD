#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // 💡 Approach: Brute Force using nested loops to check for duplicates manually
    // ⏱️ T.C. = O(n^2)               (because of nested duplicate check loop)
    // 🧠 S.C. = O(1)                 (no extra space used)

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)    
        cin >> nums[i];

    bool allNegative = true;
    for(int i = 0; i < n; i++) {
        if(nums[i] >= 0) {
            allNegative = false;
            break;
        }
    }

    if(allNegative) {
        cout << *max_element(nums.begin(), nums.end()) << endl;
        return;
    }

    long long sum = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] < 0) continue;           // ignore negative numbers

        bool alreadyCounted = false;
        for(int j = 0; j < i; j++) {        // check if nums[i] appeared before
            if(nums[i] == nums[j]) {
                alreadyCounted = true;
                break;
            }
        }

        if(!alreadyCounted) {
            sum += nums[i];                // add only if not duplicate
        }
    }

    cout << sum << endl;
}


void better()
{
    // 💡 Approach: Brute Force using set to ensure unique elements
    // ⏱️ T.C. = O(n * log n)      (for set insertions)
    // 🧠 S.C. = O(n)              (set stores up to n unique elements)

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)    
        cin >> nums[i];

    set<int> st;                     // to store unique elements
    long long sum = 0;

    // Check if all elements are negative
    bool allNegative = true;
    for(int i = 0; i < n; i++) {
        if(nums[i] >= 0) {
            allNegative = false;
            break;
        }
    }

    if(allNegative) {
        cout << *max_element(nums.begin(), nums.end()) << endl;
        return;
    }

    // If not all are negative, sum all unique non-negative elements
    for(int i = 0; i < n; i++) {
        if(nums[i] >= 0 && st.find(nums[i]) == st.end()) {
            sum += nums[i];
            st.insert(nums[i]);
        }
    }

    cout << sum << endl;
}


void optimal()
{
    // ✅ Approach: Sort + Traverse from End + Skip Duplicates
    // 🔹 T.C. = O(N log N) due to sorting
    // 🔹 S.C. = O(1) extra space

    int n;                                              
    cin >> n;                                           // input size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];         // input array

    sort(nums.begin(), nums.end());                     // Step 1: Sort the array

    int sum = nums.back();                              // Step 2: Initialize sum with last (largest) element
    int prev = sum;

    for (int i = nums.size() - 2; i >= 0 && nums[i] >= 0; prev = nums[i], i--) {
        if (nums[i] != prev)                            // Step 3: Add only unique non-negative elements
            sum += nums[i];
    }

    cout << sum << endl;                                // Step 4: Output the final sum
}

int main()
{
    optimal();
    return 0;
}
