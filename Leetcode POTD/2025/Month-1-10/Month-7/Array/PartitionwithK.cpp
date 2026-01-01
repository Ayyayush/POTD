#include <bits/stdc++.h>
using namespace std;

void better()
{
    // T.C = O(N*logN)        // sorting ke wajah se
    // S.C = O(1)             // extra space nahi lag raha

    int n, k;                                              // array size aur k ka input
    cin >> n >> k;

    vector<int> nums(n);                                   // array input lena
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());                        // pehle sort karo

    int i = 0, j = 0;                                      // do pointer logic
    int subcount = 1;                                      // kam se kam ek subarray toh hoga

    while (j < n) {                                        // pura array traverse karo
        if (abs(nums[j] - nums[i]) > k) {                  // agar difference k se zyada ho
            i = j;                                         // naye subarray ka start point
            subcount++;                                    // count badhao
        }
        j++;                                               // pointer aage badhao
    }

    cout << subcount << endl;                              // answer print karo
}

int main()
{
    better();
    return 0;
}
