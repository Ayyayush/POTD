class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,maxsize=0;
        unordered_map<char,int>mp;
        while(j<s.size())
        {
            mp[s[j]]++;

              while(mp.size()<j-i+1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(s[i]);
                i++;
            }
          
            if(j-i+1==mp.size())
            {
                maxsize=max(maxsize,j-i+1);
            }
            j++;
        }
        return maxsize;
    }
};




class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        j = 0
        maxsize = 0
        mp = {}                     # hashmap for character counts

        while j < len(s):

            # add current character
            mp[s[j]] = mp.get(s[j], 0) + 1

            # shrink window if duplicate appears
            while len(mp) < (j - i + 1):     # window size > unique chars
                mp[s[i]] -= 1
                if mp[s[i]] == 0:
                    del mp[s[i]]            # remove char completely
                i += 1                      # move left pointer

            # valid window: all characters unique
            if (j - i + 1) == len(mp):
                maxsize = max(maxsize, j - i + 1)

            j += 1                           # expand window

        return maxsize
