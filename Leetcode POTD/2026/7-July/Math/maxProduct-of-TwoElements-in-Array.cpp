class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int Largest = 0, secondLargest = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > Largest) {
                secondLargest = Largest;
                Largest = nums[i];
            }
            else if (nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }

        return (Largest - 1) * (secondLargest - 1);
    }
};