#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n^2)              // Har possible subarray ke liye sum nikalna pad raha hai
// Space Complexity: O(1)               // Koi extra space use nahi ho raha

void brute()
{
    int n;
    cin >> n;                          // Size input lo

    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++) cin >> a1[i];
    for (int i = 0; i < n; i++) cin >> a2[i];

    int result = 0;

    for (int i = 0; i < n; i++)        // start index
    {
        int sum1 = 0, sum2 = 0;

        for (int j = i; j < n; j++)    // end index
        {
            sum1 += a1[j];             // a1 ka sum calculate karo
            sum2 += a2[j];             // a2 ka bhi sum karo

            if (sum1 == sum2)          // agar dono same hue
            {
                result = max(result, j - i + 1);  // maximum length update karo
            }
        }
    }

    cout << result << endl;            // Final answer print karo
}


// Time Complexity: O(n)              // Ek hi loop me pura kaam ho raha hai
// Space Complexity: O(n)             // Unordered map me diff values store ho rahi hain

void better()
{
    int n;
    cin >> n;                         // Vector size input lo

    vector<int> a1(n), a2(n);         // Dono vectors
    for (int i = 0; i < n; i++) cin >> a1[i];
    for (int i = 0; i < n; i++) cin >> a2[i];

    unordered_map<int, int> mp;      // diff -> pehli baar kis index pe mila

    int sum1 = 0, sum2 = 0, result = 0;

    for (int i = 0; i < n; i++)
    {
        sum1 += a1[i];
        sum2 += a2[i];

        int diff = sum1 - sum2;

        if (diff == 0)               // dono sums abhi tak barabar hue
        {
            result = max(result, i + 1);
        }
        else if (mp.count(diff))     // same diff pehle bhi mila tha
        {
            result = max(result, i - mp[diff]);
        }
        else
        {
            mp[diff] = i;            // diff ko pehli baar store karo
        }
    }

    cout << result << endl;          // Answer print karo
}

int main()
{
    better();                         // better function call
    return 0;
}
