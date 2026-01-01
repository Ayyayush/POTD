#include <bits/stdc++.h>
using namespace std;

void brute()
{
    vector<int> nums = {3, 3, 3};     // Example input, aap yahan input le bhi sakte ho

    // Pehle check karo ki triangle possible hai ya nahi
    if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0])
    {
        cout << "none" << endl;                       // Triangle possible nahi hai
    }
    else if (nums[0] == nums[1] && nums[1] == nums[2])
    {
        cout << "equilateral" << endl;                // Teenon sides equal
    }
    else if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2])
    {
        cout << "isoceles" << endl;                   // Do sides equal
    }
    else
    {
        cout << "scalene" << endl;                    // Sab sides alag alag
    }
}

int main()
{
    brute();
    return 0;
}
