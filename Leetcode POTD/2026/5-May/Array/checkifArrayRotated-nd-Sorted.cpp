// method -1 
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])   // Agar current element next se bada hai to count++
            {
                count++;
            }
        }

        return count <= 1;
    }
};


// method -2 
// method -2

class Solution
{
public:
    bool check(vector<int>& nums)
    {
        int n = nums.size();

        int breakPoint = -1;

        // ! Find first decreasing point
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                // ! More than one break point
                if(breakPoint != -1)
                {
                    return false;
                }

                breakPoint = i;
            }
        }

        // ! If already sorted
        if(breakPoint == -1)
        {
            return true;
        }

        // ! Last element should be <= first element
        return nums[n - 1] <= nums[0];
    }
};