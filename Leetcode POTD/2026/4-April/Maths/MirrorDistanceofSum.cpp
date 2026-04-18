class Solution
{
public:
    int mirrorDistance(int n)
    {
        int num = n, revNum = 0;
        while (num)
        {
            revNum = (revNum * 10) + num % 10;
            num /= 10;
        }

        return abs(revNum - n);
    }
};



//Approach-2 (Simple reverse and find)
//T.C : O(log(n)), for reversing
//S.C : O(log(n)) storing string version of n
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));
        
        int rev = stoi(s);
        return abs(n - rev);
    }
};

