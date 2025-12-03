#include <bits/stdc++.h>
using namespace std;

void brute()
{
    vector<int> nums = {12, -1, -7, 8, -15, 30, 16, 28};     // Example input
    int k = 3;                                               // Window size

    int i = 0, j = 0;
    vector<int> result;

    while (j < nums.size()) {
        if (j - i + 1 == k) {
            bool found = false;

            for (int idx = i; idx <= j; idx++) {
                if (nums[idx] < 0) {
                    result.push_back(nums[idx]);            // Pehla negative mil gaya
                    found = true;
                    break;
                }
            }

            if (!found) result.push_back(0);                // Agar koi negative nahi mila

            i++;                                            // Window slide karo
        }
        j++;
    }

    // Output
    for (int x : result)
        cout << x << " ";
    cout << endl;

    // Time Complexity: O(n * k)                            // Har window mein k elements ko check kar rahe
    // Space Complexity: O(1)                               // Extra space constant hai (except output)
}

void optimal()
{
    vector<int> nums = {12, -1, -7, 8, -15, 30, 16, 28};     // Example input
    int k = 3;                                               // Window size

    deque<int> dq;                                           // Store negative number ke indices
    vector<int> result;

    int i = 0, j = 0;

    while (j < nums.size())
    {
        if (nums[j] < 0)                                     // Negative mila toh push karo
            dq.push_back(j);

        if (j - i + 1 == k)                                  // Jab window full ho jaye
        {
            if (!dq.empty() && dq.front() >= i)              // Pehla negative window ke andar hai
                result.push_back(nums[dq.front()]);
            else
                result.push_back(0);                         // Window mein koi negative nahi mila

            if (!dq.empty() && dq.front() == i)              // i waala element agar deque ke front mein hai
                dq.pop_front();                              // Toh usse hata do

            i++;                                             // Window slide karo
        }

        j++;
    }

    // Output
    for (int x : result)
        cout << x << " ";
    cout << endl;

    // Time Complexity: O(n)                                 // Har element ek baar hi push/pop hota hai
    // Space Complexity: O(k)                                // Deque mein max k elements ho sakte hain
}

int main()
{
    brute();   // Brute force run karo
    optimal(); // Optimal run karo
    return 0;
}
