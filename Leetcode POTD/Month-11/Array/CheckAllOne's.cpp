/**
 * Check if all 1's are at least k places apart
 */

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int lastPos = -1;   // last 1 kis index par mila, initially none

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)   // jab bhi ek 1 mile
            {
                if (lastPos != -1)   // agar pehle bhi 1 mila tha
                {
                    // distance check: currentIndex - lastIndex ≥ k+1  (strictly k zeros in between)
                    if (i - lastPos - 1 < k)
                        return false;   // agar distance k se kam ho, return false
                }

                lastPos = i;  // current 1 ki position ko update karo
            }
        }

        return true;  // agar koi violation nahi mila
    }
};
