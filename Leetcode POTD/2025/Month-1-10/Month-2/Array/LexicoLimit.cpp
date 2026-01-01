#include <bits/stdc++.h>
using namespace std;

void brute() // O(N*N)
{
    int i, j, s, count, limit;
    cin >> s >> limit;

    vector<int> nums(s);
    for (i = 0; i < s; i++)
    {
        cin >> nums[i];
    }

    for (i = 0; i < nums.size(); i++)
    {
        for (j = i; j < nums.size(); j++)
        {
            // Agar dono elements limit ke andar hain aur nums[i] > nums[j], to swap kar do
            if (abs(nums[i] - nums[j] <= limit) && nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
                j = i; // Dobara start se check karo
            }
        }
    }

    for (i = 0; i < s; i++)
    {
        cout << nums[i] << " ";
    }
}

void better() // O(N*N)
{
    int i, j, s, count, limit;
    cin >> s >> limit;

    vector<int> nums(s);
    for (i = 0; i < s; i++)
    {
        cin >> nums[i];
    }

    for (i = 0; i < nums.size(); i++)
    {
        // Pehla element dhoondo jo i se bada ho
        auto it = find_if(nums.begin(), nums.end(), [i](int num) {
            return num > i;
        });

        if (it != nums.end())
        {
            for (j = i; j < nums.size(); j++)
            {
                // Agar dono elements limit ke andar hain aur nums[i] > nums[j], to swap kar do
                if (abs(nums[i] - nums[j] <= limit) && nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                    j = i; // Dobara start se check karo
                }
            }
        }
    }

    for (i = 0; i < s; i++)
    {
        cout << nums[i] << " ";
    }
}





void optimal() // O(N * log(N))
{
    int s, limit;
    cin >> s >> limit;

    vector<int> nums(s);
    for (int i = 0; i < s; i++)
    {
        cin >> nums[i];
    }

    // Step 1: Sort karo aur groups assign karo - O(N * log(N))
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end()); // Sort karna zaruri hai

    int groupCount = 0;
    unordered_map<int, int> numToGroup; // Number se uska group map
    unordered_map<int, list<int>> groupToValues; // Group se list of numbers map

    for (int i = 0; i < s; i++)
    {
        // Agar limit cross ho jaye, naya group start karo
        if (i > 0 && abs(sortedNums[i] - sortedNums[i - 1]) > limit)
        {
            groupCount++;
        }
        numToGroup[sortedNums[i]] = groupCount;
        groupToValues[groupCount].push_back(sortedNums[i]);
    }

    // Step 2: Result array banao - O(N)
    vector<int> result(s);
    for (int i = 0; i < s; i++)
    {
        int currentNum = nums[i];
        int group = numToGroup[currentNum];

        // Group ke smallest available number ko result me daalo
        result[i] = groupToValues[group].front();
        groupToValues[group].pop_front(); // Use karne ke baad nikaal do
    }

    // Step 3: Output karo
    for (int i = 0; i < s; i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    optimal(); // Call the optimal function
    return 0;
}
