#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE ===================== */
void brute()
{
    // APPROACH: Brute Force (Circular Traversal using Nested Loops)
    // For each element, check to the right; if not found, wrap around

    // TIME COMPLEXITY: O(N^2)
    // SPACE COMPLEXITY: O(1)   (excluding output array)

    vector<int> nums = {1, 2, 1};                 // sample input
    int n = nums.size();

    vector<int> result(n, -1);

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        // check elements to the right
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                result[i] = nums[j];
                found = true;
                break;
            }
        }

        // circular check from beginning
        if (!found)
        {
            for (int j = 0; j <= i; j++)
            {
                if (nums[j] > nums[i])
                {
                    result[i] = nums[j];
                    break;
                }
            }
        }
    }

    for (int x : result) cout << x << " ";
}

/* ===================== OPTIMAL ===================== */
void optimal()
{
    // APPROACH: Monotonic Stack + Circular Traversal
    // Traverse array twice from right to left using modulo

    // TIME COMPLEXITY: O(N)
    // SPACE COMPLEXITY: O(N)

    vector<int> nums = {1, 2, 1};                 // sample input
    int n = nums.size();

    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;

        while (!st.empty() && st.top() <= nums[idx])
        {
            st.pop();
        }

        if (!st.empty())
        {
            res[idx] = st.top();
        }

        st.push(nums[idx]);
    }

    for (int x : res) cout << x << " ";
}

int main()
{
    brute();
    cout << "\n";
    optimal();
    return 0;
}
