#include < bits/stdc++.h>
using namespace std;

// T.c == O(N)
// S.c ==O(N+N)

void brute()
{

    sort(nums.rbegin(), nums.rend());
    if (nums.size() < 3)
    {
        return nums[0];
    }

    vector<int> result;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            result.push_back(nums[i]);
        }
    }
    result.push_back(nums[nums.size() - 1]);
    if (result.size() < 3)
    {
        return result[0];
    }
    return result[2];
}



// T.c == O(N)
// S.c ==O(N+N)
void better()
{
    vector<int> result;
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }

    for (auto it : st)
    {
        result.push_back(it);
    }

    sort(result.rbegin(), result.rend());
    if (result.size() < 3)
    {
        return result[0];
    }
    return result[2];
}
int main()
{
}