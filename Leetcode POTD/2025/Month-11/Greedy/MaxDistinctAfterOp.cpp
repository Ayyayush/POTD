#include <bits/stdc++.h>
using namespace std;

/**
 * Approach: Brute Force
 * ------------------------------------
 * Har element ke liye try karte hain usse -k se +k tak adjust karne ka
 * goal ye hai ki jitne zyada distinct elements possible ho sake utne ban jayein.
 *
 * Time Complexity:  O(n * k)          // har element ke liye max k range check
 * Space Complexity: O(n)              // unordered_map use hua hai
 */

void brute()
{
    vector<int> nums = {8, 7, 8, 7, 10}; // ✅ Hardcoded input
    int k = 1;                           // Example value for k
    unordered_map<int, int> mp;          // distinct elements track karne ke liye

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int value = -k; // starting offset -k se

        // Jab tak current adjusted number map me mil raha hai, value badhate jao
        while (mp.count(nums[i] + value))
        {
            value++;
        }

        // Agar abhi bhi value allowed range ke andar hai toh store karo
        if (value <= k)
            mp[nums[i] + value]++;
    }

    cout << "Maximum distinct elements: " << mp.size() << endl; // ✅ output print karo
}


/**
 * T.c == 
 * S.c == 
 * 
 */
void better()
{

}

int main()
{
    brute();
    return 0;
}
