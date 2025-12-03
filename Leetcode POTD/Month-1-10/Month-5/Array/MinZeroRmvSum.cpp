#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n + m)         // ek loop n tak aur ek loop m tak
    // Space Complexity: O(n + m)        // do vectors banaye hain nums1 aur nums2

    int n, m;
    cin >> n >> m;

    long long sum1 = 0, sum2 = 0;
    long long zeronums1 = 0, zeronums2 = 0;

    vector<int> nums1(n);
    vector<int> nums2(m);

    // nums1 ka input lena aur uska sum nikalna
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];

        if (nums1[i] == 0)
        {
            zeronums1++;      // count karo kitne zero hain
            sum1 += 1;        // 0 ki jagah 1 lena padta hai problem ke hisaab se
        }
        else
        {
            sum1 += nums1[i]; // normal case me add karo
        }
    }

    // nums2 ka input lena aur uska sum nikalna
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];

        if (nums2[i] == 0)
        {
            zeronums2++;
            sum2 += 1;        // 0 ko 1 mana ja raha hai
        }
        else
        {
            sum2 += nums2[i];
        }
    }

    // agar sum1 chhota hai aur usme koi 0 bhi nahi hai, toh impossible
    if (sum1 < sum2 && zeronums1 == 0)
    {
        cout << "-1" << endl;
    }
    // agar sum2 chhota hai aur usme koi 0 bhi nahi hai, toh bhi impossible
    else if (sum2 < sum1 && zeronums2 == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        // dono me se max sum print karo
        cout << max(sum1, sum2) << endl;
    }
}

int main()
{
    brute();
    return 0;
}
