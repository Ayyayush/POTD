class Solution {
public:
    char processStr(string s, long long k) {
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                temp += s[i];
            } else if (s[i] == '*') {
                if (temp.size() != 0)
                    temp.pop_back();
            } else if (s[i] == '#') {
             
                if(temp.size()!=0)
                temp +=temp;
            } else {
                if(temp.size()!=0)
                reverse(temp.begin(), temp.end());
            }
        }
        if (k >=s.size() || k<0)
            return '.';
        else if(k-1>=0)
            return s[k];
        else
            return '.';
    }
};