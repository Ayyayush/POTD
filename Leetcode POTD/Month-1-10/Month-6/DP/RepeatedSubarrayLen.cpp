#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);                     // Dono arrays input le liye
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];

    int maxlen = INT_MIN;                               // Maximum common subarray length store karne ke liye

    for (int i = 0; i < n; i++)                         // nums1 ke har index se start karo
    {
        int count = 0;
        for (int j = 0; j < m; j++)                     // nums2 ke har index se match check karo
        {
            int a = i, b = j;

            if (nums1[i] == nums2[j])                   // Jab starting point pe elements match karein
            {
                while (a < n && b < m && nums1[a] == nums2[b])   // Tab tak match karo jab tak elements equal hain
                {
                    a++;
                    b++;
                    count++;
                    maxlen = max(maxlen, count);        // Maximum length update karo
                }
            }
            count = 0;                                  // Count reset karo har match ke baad
        }
    }

    cout << maxlen << endl;                             // Final result print karo
}

int main()
{
    brute();
    return 0;
}
