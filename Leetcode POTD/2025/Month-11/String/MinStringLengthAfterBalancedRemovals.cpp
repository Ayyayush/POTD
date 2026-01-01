class Solution {
public:
    int minLengthAfterRemovals(string s) {
        if(s.find('a')==string::npos)
        return s.size();
        else if(s.find('b')==string::npos)
        return s.size();
int a=0,b=0;
        for(int i=0;i<s.size();i++){
        if(s[i]=='a')
        a++;
        else
        b++;}

        return abs(a-b);
        
    }
};