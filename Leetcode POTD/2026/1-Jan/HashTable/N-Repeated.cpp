#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------*/
void brute()
{
    // Approach: Nested Loop (Brute Force)
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)

    vector<int> nums = {1, 2, 3, 3};
    int n = nums.size() / 2;

    for(int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        int num = nums[i];

        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == num)
                count++;
        }

        if(count == n)
        {
            cout << num;
            return;
        }
    }
}




/*--------------------------------------------------*/
void better()
{
    // Approach: Hashing using unordered_map
    // Time Complexity: O(N)
    // Space Complexity: O(N)

    vector<int> nums = {1, 2, 3, 3};
    unordered_map<int, int> mp;
    int n = nums.size() / 2;

    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for(auto x : mp)
    {
        if(x.second == n)
        {
            cout << x.first;
            return;
        }
    }
}





/*--------------------------------------------------*/
void optimal()
{
    // Approach: Vector as Frequency Map (Array Hashing)
    // Time Complexity: O(N)
    // Space Complexity: O(MaxValue)

    vector<int> nums = {1, 2, 3, 3};
    int n = nums.size() / 2;

    vector<int> freq(10001, 0);

    for(int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;

        if(freq[nums[i]] == n)
        {
            cout << nums[i];
            return;
        }
    }
}

/*--------------------------------------------------*/
int main()
{
    brute();      // try brute
    // better();  // try better
    // optimal(); // try optimal
    return 0;
}
