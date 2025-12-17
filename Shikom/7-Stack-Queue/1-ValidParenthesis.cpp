class Solution {
public:
    bool isValid(string s) {
         int i,j,bracOpen=0,bracClose=0,braceleft=0,braceright=0,leftp=0,rightp=0;
    for(i=0;i<s.size();i++)
    { 
        if(s[i]=='(')
        bracOpen++;
        else if(s[i]==')')
        bracClose++;
        else if(s[i]=='[')
        braceleft++;
        else if(s[i]==']')
        braceright++;
        else if(s[i]=='{')
        leftp++;
        else if(s[i]=='}')
        rightp++;
        
    } 
    if(bracOpen==bracClose && leftp==rightp && braceleft==braceright)
    {
       return true;
    }
    else
    {
    return false;
    }

}
    
};


class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(let i= i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                while(!st.empty())
                {
                    
                }
            }


        }


return st.empty();
        
    }
}; 