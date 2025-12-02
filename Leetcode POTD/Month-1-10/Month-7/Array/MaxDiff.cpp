#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C: O(N^2)           // Brute force approach
    // S.C: O(1)

    int n;
    cin >> n;                // Array size input lo

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];   // Array elements input lo

    int maxdiff = -1;        // Maximum difference ka answer

    for (int i = 0; i < n - 1; i++) {          // Har i ke liye
        for (int j = i + 1; j < n; j++) {      // Sab possible j > i check karo
            if (nums[i] < nums[j]) {           // Agar nums[i] chhota hai
                int diff = nums[j] - nums[i];  // Difference nikalo
                maxdiff = max(maxdiff, diff);  // Max diff update karo
            }
        }
    }

    cout << maxdiff << endl;   // Answer print karo
}




void better()
{
    // Time Complexity: O(N)                      // Ek hi pass mein min aur max track kar rahe hain
    // Space Complexity: O(1)                      // Sirf kuch variables use ho rahe hain

    int n; cin >> n;                              // Array size input
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];                           // Array elements input

    int minindex = 0;                             // Pehla index ko min index maan lo
    int maxindex = 0;                             // Pehla index ko max index bhi maan lo
    int maxdiff = -1;                             // Answer initialise karo -1 se (agar koi diff nahi banta to -1 hi rahega)

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < nums[minindex])
        {
            /*
             * Agar current number previous min se chhota hai
             * to minindex update karo aur maxindex bhi isi pe set karo
             * kyunki naye chhote point ke baad ka hi max dekhna hai
             */
            minindex = i;
            maxindex = i;
        }

        if (nums[i] > nums[maxindex])
            maxindex = i;                         // Agar current number pehle wale max se bada hai to maxindex update karo

        if (maxindex > minindex)
        {
            /*
             * Jab tak maxindex minindex ke baad ho
             * difference calculate karo aur maxdiff update karo
             */
            maxdiff = max(maxdiff, abs(nums[maxindex] - nums[minindex]));
        }
    }

    cout << maxdiff << endl;                      // Final answer print karo
}

int main()
{
    brute();
    return 0;
}
