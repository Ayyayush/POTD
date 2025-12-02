class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string str1="";
        for(int i=0;i<s.size();i++)
        {
            if(isalnum(s[i]))
            {
                
              str1 += tolower(s[i]);

            }
        }
        string str2=str1;
        reverse(str2.begin(),str2.end());
        return str1==str2;
    }
};