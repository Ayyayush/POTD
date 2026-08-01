class Solution {
public:
    bool bt(int turn, int p1Score, int p2Score, int left, int right, vector<int>& nums) {
        if(left > right)
            return p1Score >= p2Score;

        if((turn & 1) == 0) {
            return bt(turn ^ 1, p1Score + nums[left], p2Score, left + 1, right, nums) ||
                   bt(turn ^ 1, p1Score + nums[right], p2Score, left, right - 1, nums);
        }

        return bt(turn ^ 1, p1Score, p2Score + nums[left], left + 1, right, nums) &&
               bt(turn ^ 1, p1Score, p2Score + nums[right], left, right - 1, nums);
    }

    bool PredictTheWinner(vector<int>& nums) {
        return bt(0, 0, 0, 0, nums.size() - 1, nums);
    }
};