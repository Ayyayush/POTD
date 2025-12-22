#include <bits/stdc++.h>
using namespace std;

/*
============================================================
BRUTE FORCE APPROACH
Approach Name: Recursive Backtracking
Time Complexity: O(2^N)  (Exponential)
Space Complexity: O(N)   (Recursion stack)

Idea:
- From each index, try all possible jumps
- If any path reaches last index → return true
- Very slow, only for understanding
============================================================
*/
bool solveBrute(int idx, vector<int> &nums)
{
    if(idx >= nums.size() - 1)
        return true;                            // reached or crossed last index

    int maxJump = nums[idx];

    for(int jump = 1; jump <= maxJump; jump++)
    {
        if(solveBrute(idx + jump, nums))
            return true;                        // if any path works
    }

    return false;
}

void brute()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << solveBrute(0, nums);
}

/*
============================================================
BETTER APPROACH
Approach Name: Dynamic Programming (Bottom-Up)
Time Complexity: O(N^2)
Space Complexity: O(N)

Idea:
- dp[i] = can we reach the end starting from index i
- Start from last index and move backwards
============================================================
*/
void better()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<bool> dp(n, false);
    dp[n - 1] = true;                           // last index is always reachable

    for(int i = n - 2; i >= 0; i--)
    {
        int maxJump = nums[i];
        for(int jump = 1; jump <= maxJump && i + jump < n; jump++)
        {
            if(dp[i + jump])
            {
                dp[i] = true;
                break;
            }
        }
    }

    cout << dp[0];
}

/*
============================================================
OPTIMAL APPROACH
Approach Name: Greedy (Max Reach)
Time Complexity: O(N)
Space Complexity: O(1)

Core Idea:
- Maintain the farthest index reachable so far
- If at any index i > maxReach → cannot proceed
- Update maxReach greedily

This is the most optimal and interview-preferred solution
============================================================
*/
void optimal()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int maxReach = 0;                           // farthest index reachable

    for(int i = 0; i < n; i++)
    {
        if(i > maxReach)
        {
            cout << false;                      // cannot reach this index
            return;
        }

        maxReach = max(maxReach, i + nums[i]);  // update reach

        if(maxReach >= n - 1)
        {
            cout << true;                       // already can reach end
            return;
        }
    }

    cout << false;
}

int main()
{
    // Uncomment the approach you want to run

    // brute();
    // better();
    optimal();

    return 0;
}
