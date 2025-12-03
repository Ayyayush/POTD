#include <bits/stdc++.h>
using namespace std;

bool found = false;

void subset(vector<int>& nums, vector<int>& subs, int i, long long sum)
{
    if(found) return;    // agar answer mil gaya toh aur aage check mat karo

    if(i == nums.size())
    {
        long long s = accumulate(subs.begin(), subs.end(), 0);
        if(s * 2 == sum)
        {
            cout << "True" << endl;
            found = true;  // ek baar hi print karega
        }
        return;
    }

    subs.push_back(nums[i]);
    subset(nums, subs, i + 1, sum);

    subs.pop_back();
    subset(nums, subs, i + 1, sum);
}

void better()
{
    // Time Complexity: O(n * x)              // n = number of elements, x = sum/2
    // Space Complexity: O(n * x)             // recursion + dp array

    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int total = accumulate(nums.begin(), nums.end(), 0);       // poora sum nikaal liya

    if(total % 2 != 0) {
        cout << "false\n";                                     // agar sum odd hai toh equal partition possible hi nahi
        return;
    }

    int x = total / 2;
    int t[201][20001];                                         // DP array for memoization
    memset(t, -1, sizeof(t));                                  // saare values -1 se initialize

    function<bool(int, int)> solve = [&](int i, int x) -> bool {
        if(x == 0) return true;                                // base case: agar x 0 ho gaya toh solution mil gaya
        if(i >= n) return false;                               // agar end tak pahuch gaye aur x bacha ho toh fail

        if(t[i][x] != -1) return t[i][x];                       // memoized answer agar pehle se hai

        bool take = false;
        if(nums[i] <= x)
            take = solve(i + 1, x - nums[i]);                  // element leke solve karna

        bool not_take = solve(i + 1, x);                       // element skip karke solve karna

        return t[i][x] = take || not_take;                     // dono mein se koi bhi true ho toh answer true
    };

    bool ans = solve(0, x);                                    // recursive call
    cout << (ans ? "true\n" : "false\n");
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> subs;
    subset(nums, subs, 0, sum);

    if(!found) cout << "False" << endl;


    // better();

    return 0;
}
