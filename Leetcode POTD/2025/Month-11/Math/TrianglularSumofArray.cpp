/**
 * Triangular Sum of an Array 
 * 
 * n size ka array diya h 
 * tabtak aage ka process return krna h
 *  jabtak last mein ek hi elt na bache 
 * if n==1 h toh end the process
 * else 
 * perform operation 
 * 
 * 
 * Approach -1
 * for loop chala do 
 *  result.push(num[i]+num[i+1])%10
 * 
 * replace nums=result
 * 
 * isme space jyada lag rha h 
 * 
 * 
 * Approach -2 
 * baar baar naya array bnane ki jageh nums hi modify karo
 * i+1 index ki value khi rakh lo taaki use kar sako 
 * 
 * 
 */
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1) {
            vector<int> result;
            for(int i = 0; i < nums.size() - 1; i++) {
                result.push_back((nums[i] + nums[i+1]) % 10);  // sum of consecutive elements mod 10
            }
            nums = move(result);  // move the new row into nums
        }
        return nums[0];  // final triangular sum
    }
};



class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();                          // n = size of the input vector

        // Outer loop → Reduce the "size" of the array step by step
        // Each iteration will compute the new row of numbers
        for(int size = n - 1; size >= 1; size--) {   
            // Inner loop → Compute sum of consecutive elements modulo 10
            for(int i = 0; i < size; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;  // Update nums[i] with sum of nums[i] and nums[i+1] modulo 10
            }
        }

        return nums[0];                               // After all iterations, nums[0] contains the final triangular sum
    }
};

