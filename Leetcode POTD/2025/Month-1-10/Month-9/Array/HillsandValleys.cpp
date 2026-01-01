#include <bits/stdc++.h>
using namespace std;

void better()
{
    // 💡 Approach: Skip same adjacent elements and check if element is hill or valley
    // ⏱️ T.C. = O(n)
    // 🧠 S.C. = O(1)

    int n;                        
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)    
        cin >> nums[i];

    int count = 0;

    for (int i = 1; i < n - 1; i++) {
        if (nums[i] == nums[i - 1]) continue;          // Skip duplicates

        int left = i - 1;
        while (left >= 0 && nums[left] == nums[i])     // Find actual left different
            left--;

        int right = i + 1;
        while (right < n && nums[right] == nums[i])    // Find actual right different
            right++;

        if (left >= 0 && right < n) {
            if (nums[i] > nums[left] && nums[i] > nums[right]) count++;       // Hill
            else if (nums[i] < nums[left] && nums[i] < nums[right]) count++;  // Valley
        }
    }

    cout << count << endl;
}
