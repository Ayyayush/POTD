#include <bits/stdc++.h>
using namespace std;
void brute()
{
    vector<int> nums={9,2,10,1,10,4,8,9,7,6,8,10,8,6,5,4,3,4,2,10};
    sort(nums.begin(), nums.end());
     int maxsum = -1, pairsum;
     int i=0,j=nums.size()-1;
    while (i < j)
    {
        pairsum = nums[i] + nums[j];
        maxsum = max(pairsum, maxsum);
        i++;
        j--;
    }

    cout << maxsum << endl;
}
int main()
{
    brute();
}



/**
 * @param {number[]} nums
 * @return {number}
 */
var minPairSum = function(nums) {

    nums.sort((a, b) => a - b);        // numeric ascending sort

    let maxsum = -1;
    let i = 0, j = nums.length - 1;

    while (i < j)
    {
        let pairsum = nums[i] + nums[j];
        maxsum = Math.max(maxsum, pairsum);
        i++;
        j--;
    }

    return maxsum;
};
