#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(vector<int> &ranks, ll mid, int cars)
{
    ll carsFixed = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        carsFixed += sqrt(mid / ranks[i]); // Yeh part ignore kiya ja raha hai
    }
    return carsFixed >= cars;
}

void better()
{
    int n;
    cin >> n; // Number of mechanics
    vector<int> ranks(n);
    for (int i = 0; i < n; i++)
        cin >> ranks[i]; // Mechanics ke ranks input lo

    int cars;
    cin >> cars; // Total number of cars jo repair karni hain

    ll l = 1;
    int maxR = *max_element(begin(ranks), end(ranks));
    ll r = 1LL * maxR * cars * cars; // Maximum possible time calculate kar rahe hain

    ll result = -1;

    while (l <= r)
    { // Binary search O(log(maxR * cars * cars))
        ll mid = l + (r - l) / 2;
        if (isPossible(ranks, mid, cars))
        { // O(n) check karne ke liye ki possible hai ya nahi
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << result << endl; // Minimum time print karo
}

int main()
{
    better();
    return 0;
}
