#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // 💡 Approach: Brute Force
    // T.C. = O(n1 * n2^2)
    // S.C. = O(n1)

    vector<int> nums1 = {4, 1, 2};            // hardcoded input
    vector<int> nums2 = {1, 3, 4, 2};         // hardcoded input

    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> res(n1, -1);                  // result array initialized with -1

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2 - 1; j++)
        {
            if (nums2[j] == nums1[i])
            {
                for (int k = j + 1; k < n2; k++)
                {
                    if (nums2[k] > nums1[i])
                    {
                        res[i] = nums2[k];
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n1; i++)
        cout << res[i] << " ";
    cout << endl;
}

void better()
{
    // 💡 Approach: Hash Map + Nested Loop
    // T.C. = O(n2^2 + n1)
    // S.C. = O(n2 + n1)

    vector<int> nums1 = {4, 1, 2};            // hardcoded input
    vector<int> nums2 = {1, 3, 4, 2};         // hardcoded input

    int n1 = nums1.size(), n2 = nums2.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n2; i++)
    {
        int nextGreater = -1;
        for (int j = i + 1; j < n2; j++)
        {
            if (nums2[j] > nums2[i])
            {
                nextGreater = nums2[j];
                break;
            }
        }
        mp[nums2[i]] = nextGreater;          // store next greater for each element
    }

    vector<int> res;
    for (int i = 0; i < n1; i++)
    {
        res.push_back(mp[nums1[i]]);
    }

    for (int val : res)
        cout << val << " ";
    cout << endl;
}

void optimal()
{
    // 💡 Approach: Monotonic Stack + Hash Map
    // T.C. = O(n1 + n2)
    // S.C. = O(n2 + n1)

    vector<int> nums1 = {4, 1, 2};            // hardcoded input
    vector<int> nums2 = {1, 3, 4, 2};         // hardcoded input

    int n1 = nums1.size(), n2 = nums2.size();
    unordered_map<int, int> mp;
    stack<int> st;

    for (int i = n2 - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();                         // pop smaller elements
        }

        if (!st.empty())
            mp[nums2[i]] = st.top();          // next greater found
        else
            mp[nums2[i]] = -1;                // no greater element found

        st.push(nums2[i]);                    // push current element
    }

    vector<int> res;
    for (int i = 0; i < n1; i++)
    {
        res.push_back(mp[nums1[i]]);
    }

    for (int val : res)
        cout << val << " ";
    cout << endl;
}

int main()
{
    cout << "Brute Output: ";
    brute();

    cout << "Better Output: ";
    better();

    cout << "Optimal Output: ";
    optimal();

    return 0;
}
