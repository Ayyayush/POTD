#include <bits/stdc++.h>
using namespace std;

// Approach: Recursive Subset Generation (Brute Force)
// Time Complexity: O(2^n * n log n)      (2^n subsets * sorting each subset)
// Space Complexity: O(n)                 (recursive stack + temp subset)

int maxcount = 0;

void generateSubsets(vector<int>& nums, vector<int>& subset, int index)
{
    if (index == nums.size())
    {
        if (!subset.empty())
        {
            vector<int> temp = subset;                           // temp mein copy banayi subset ki
            sort(temp.begin(), temp.end());                      // sort kiya to find min and max
            if (temp.back() - temp[0] == 1)                      // agar max - min == 1
            {
                maxcount = max(maxcount, (int)temp.size());     // toh update maxcount
            }
        }
        return;
    }

    subset.push_back(nums[index]);                               // include current element
    generateSubsets(nums, subset, index + 1);                    // move to next

    subset.pop_back();                                           // exclude element (backtrack)
    generateSubsets(nums, subset, index + 1);                    // again move to next
}

void naive()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};                  // example input
    vector<int> subset;

    generateSubsets(nums, subset, 0);                            // start recursion from index 0

    cout << maxcount << endl;                                    // final answer
}



/**
 * *IQ TESTING QUESTION
 * Hashmap
 * eg ::=  1,3,2,2,5,2,3,7
 * maan lo min =1 choose kr liya ab diff chahiye 1 
 * toh kaun sa number chahiye jisme 1 ke sath diff 1 aaye
 * answer == 2 ya 0 
 * toh target hoi gya 2 abhi
 * ab dekhenge ki  kha tak 2 ya 0 mil rha h 
 * inn dono ke alawa jo bhi aayega usko nhi lenge 
 * aur slide krte rahenge 
 * max value jo le skte h wo hoga minimum+1 yha pe 2 
 * toh 2 se bada koi number nhi lenge 
 * so resultant subsequence will have two numbers only 
 * jaise yha pe 1 aur 2 honge  ya 1,0 hoga 
 * 
 * 
 * maan lo min 3 liya h toh target ban gya 2 ya 4
 * max 4 le skte h 
 * subsequence mein 2 number hi honge distinct  3,4 ya 3,2 
 * 
 * 
 * so valid subsequence mein min aur target ho skte h cahhe jitni baar 
 * kitni baar ho skte h ye unki frequncy pe depend karega
 * freq ke liye map le lo 
 * maxlength nikalega min freq + target freq se 
 * toh ans === 3,2,2,2,3
 */



// Approach: Sorting + Sliding Window (Better Approach)
// Time Complexity: O(n log n)            (due to sorting)
// Space Complexity: O(1)                 (no extra data structures used)

void better()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};       // example input

    sort(nums.begin(), nums.end());                   // Step 1: sort the array

    int result = 0;
    int start = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        while (nums[i] - nums[start] > 1)             // shift window start until diff ≤ 1
        {
            start++;
        }

        if (nums[i] - nums[start] == 1)               // valid harmonious subsequence
        {
            result = max(result, i - start + 1);      // update result if longer
        }
    }

    cout << result << endl;                           // final answer
}



// Approach: Hash Map + Frequency Count (Optimal Approach)
// Time Complexity: O(n)                  (2 linear passes over nums)
// Space Complexity: O(n)                 (unordered_map storage)

void optimal()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};         // example input

    unordered_map<int, int> mp;
    int result = 0;

    for (int &num : nums)
    {
        mp[num]++;                                      // count frequency of each number
    }

    for (int &num : nums)
    {
        int minnum = num;
        int maxnum = num + 1;

        if (mp.count(maxnum))                           // check if consecutive number exists
        {
            result = max(result, mp[num] + mp[maxnum]); // update result with length of such subset
        }
    }

    cout << result << endl;                             // print the final answer
}




int main()
{
    better();
    return 0;
}
