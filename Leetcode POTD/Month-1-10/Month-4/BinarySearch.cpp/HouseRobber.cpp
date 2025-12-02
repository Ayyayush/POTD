#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    long long sum, maxsum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = 0;
        for (int j = i; j < nums.size(); j += 2)
        {
            if (j < nums.size())
                sum += nums[j];
        }
        maxsum = max(maxsum, sum);
    }
    cout << maxsum << endl;
}



void better()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long sum, maxsum = INT_MIN, previndex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = nums[i];
        maxsum = max(maxsum, sum);
        previndex = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j < nums.size() && previndex + 1 != j)
            {
                cout << nums[j] << " ";
                sum += nums[j];
                previndex = j;
            }
            maxsum = max(maxsum, sum);
        }
    }
    cout << maxsum << endl;
}


#include <bits/stdc++.h>
using namespace std;

// **Better Approach: Bottom-Up DP**
// T.C: O(N)  ---> Har house ko ek baar process kar rahe hain
// S.C: O(N)  ---> DP array use ho raha hai
void better() {
    int n;
    cin >> n; // Input le rahe hain
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array input le rahe hain

    if (n == 1) {
        cout << nums[0] << endl; // Agar sirf ek house hai, toh wahi max loot sakte hain
        return;
    }

    vector<int> t(n + 1);
    t[0] = 0;
    t[1] = nums[0];

    for (int i = 2; i <= n; i++) {
        int skip = t[i - 1];                  // Agar hum current house ko skip karte hain
        int steal = nums[i - 1] + t[i - 2];   // Agar hum current house ko loot te hain
        
        t[i] = max(skip, steal); // Max choose karna hai
    }

    cout << t[n] << endl; // Maximum profit print kar rahe hain
}

// **Optimal Approach: Space Optimized DP (Converting Better Approach)**
// T.C: O(N)  ---> Har house ko ek baar process kar rahe hain
// S.C: O(1)  ---> Sirf 2 extra variables use ho rahe hain, DP array nahi
void optimal() {
    int n;
    cin >> n; // Input le rahe hain
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array input le rahe hain

    if (n == 1) {
        cout << nums[0] << endl; // Agar sirf ek house hai, toh wahi max loot sakte hain
        return;
    }

    int prevPrev = 0;
    int prev = nums[0];

    for (int i = 2; i <= n; i++) {
        int skip = prev;                 // Current house ko skip karein
        int take = nums[i - 1] + prevPrev; // Current house ko lein aur (i-2) ka profit add karein

        int temp = max(skip, take); // Maximum choose karein

        prevPrev = prev; // Pehle wale ko update karein
        prev = temp;     // Current result update karein
    }

    cout << prev << endl; // Maximum profit print karein
}

int main() {
    better();
    optimal();
    return 0;
}

int main()
{
    better();
    return 0;
}