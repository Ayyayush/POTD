class Solution {
public:

    // ! Approach : Digit Extraction + Reverse
    // ! T.C. : O(total digits)
    // ! S.C. : O(total digits)

    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> result;

        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            vector<int> temp;

            // ! Extract digits
            while(num)
            {
                temp.push_back(num % 10);
                num /= 10;
            }

            // ! Reverse because digits were extracted backwards
            reverse(temp.begin(), temp.end());

            // ! Push digits into final result
            for(int j = 0; j < temp.size(); j++)
            {
                result.push_back(temp[j]);
            }
        }

        return result;
    }
};

class Solution {
public:

    // ! Approach : String Conversion
    // ! T.C. : O(total digits)
    // ! S.C. : O(total digits)

    vector<int> separateDigits(vector<int>& nums) {

        int n = nums.size();

        vector<int> result;

        for(int i = 0; i < n; i++)
        {
            string str = to_string(nums[i]);

            for(int j = 0; j < str.size(); j++)
            {
                result.push_back(str[j] - '0');
            }
        }

        return result;
    }
};