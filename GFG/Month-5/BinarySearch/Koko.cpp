#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>& arr, int mid, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % mid == 0)
        {
            count += arr[i] / mid;                  // Agar poora divide ho gaya
        }
        else
        {
            count += (arr[i] / mid) + 1;            // Agar bacha kucha hai toh 1 aur add
        }
    }
    return count <= k;                              // Agar ban gaye toh valid hai
}

void better()
{
    // Time Complexity: O(N log M)               // Binary Search over possible mid (1 to max)
    // Space Complexity: O(1)

    int n, k;
    cin >> n >> k;                                 // Input: number of piles + allowed total eating time

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());                  // Sort kar diya, though yahan zarurat nahi bhi hai

    int l = 1;                                     // l = 1 kyunki mid zero nahi ho sakta
    int r = arr[n - 1];                            // r = max pile
    int result = r;                                // Initialize karo max se

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (ispossible(arr, mid, k))
        {
            result = mid;                          // Possible hai toh result store karo
            r = mid - 1;                           // aur chhota try karo
        }
        else
        {
            l = mid + 1;                           // Nahi bana toh bada try karo
        }
    }

    cout << result << endl;                        // Final answer print karo
}

int main()
{
    better();
    return 0;
}
