#include <bits/stdc++.h>
using namespace std;

void brute()
{
     // using nested loops
}
void better()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    int k;
    cin >> k;
    int i = 0, j = 0, sum = 0, maxsum = INT_MIN;
    while (j < nums.size())
    {
        sum += nums[j];
        if (j - i + 1 == k)
        {
            maxsum = max(sum, maxsum);
            sum -= nums[i];
            i++;
        }

        j++;
    }
    cout<<maxsum<<endl;
}

int main()
{
    better();
    return 0;
}
