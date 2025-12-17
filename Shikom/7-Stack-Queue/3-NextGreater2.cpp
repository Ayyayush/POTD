#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   APPROACH: Brute Force
   Time Complexity: O(n * m)
   Space Complexity: O(1)
   ========================================================= */
void brute()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        int curr = nums1[i];
        int k = 0;

        // find curr element in nums2
        while (k < nums2.size() && nums2[k] != curr)
        {
            k++;
        }

        int nge = -1;

        // search for next greater element
        for (int j = k + 1; j < nums2.size(); j++)
        {
            if (nums2[j] > curr)
            {
                nge = nums2[j];
                break;
            }
        }

        ans.push_back(nge);
    }

    for (int x : ans)
        cout << x << " ";
}

/* =========================================================
   APPROACH: Better (Monotonic Stack + Hash Map)
   Time Complexity: O(n + m)
   Space Complexity: O(n)
   ========================================================= */
void better()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    unordered_map<int, int> mp;    // element -> next greater
    stack<int> st;

    // build NGE for nums2
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }

        mp[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    // answer for nums1
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << mp[nums1[i]] << " ";
    }
}

/* ================= MAIN FUNCTION ================= */
int main()
{
    better();     // change to brute() if needed
    return 0;
}
