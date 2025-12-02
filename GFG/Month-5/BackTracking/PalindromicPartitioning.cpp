
class Solution {
public:
// O(N*2^N)
    bool isPalin(string s) {  
        string s2 = s;  
        reverse(s2.begin(), s2.end());  
        return s == s2;  
    }

    void getall(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        if (s.empty()) {  
            ans.push_back(partitions);  
            return;  
        }
        for (int i = 0; i < s.size(); i++) {  
            string part = s.substr(0, i + 1);  
            if (isPalin(part)) {  
                partitions.push_back(part);  
                getall(s.substr(i + 1), partitions, ans);  
                partitions.pop_back();  
            }  
        }  
    }

    vector<vector<string>> partition(string s) {  
        vector<vector<string>> ans;  
        vector<string> partitions;  
        getall(s, partitions, ans);  
        return ans;  
    }
};