class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;                                         // Missing elements store karne ke liye
        int minVal = *min_element(nums.begin(), nums.end());     // Minimum element nikal rahe hain
        int maxVal = *max_element(nums.begin(), nums.end());     // Maximum element nikal rahe hain
        
     
        for (int i = minVal + 1; i < maxVal; i++) {              // min aur max ke beech ke numbers traverse karte hain
            if (find(nums.begin(),nums.end(),i)==nums.end()) {                                  // Agar element map mein nahi hai
                ans.push_back(i);                                // To wo missing element hai
            }
        }

        return ans;                                              // Final missing elements return karte hain
    }
};
