class Solution
{
public:
    bool hasSameDigits(string s)
    {

        while (s.size() >= 2)
        {
            long long ans = 0;
            string str = "";

            for (int i = 0; i < s.size(); i++)
            {
                if (i + 1 < s.size())
                {
                    ans = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                    str += to_string(ans);
                }
            }
            s = str;
            if (s.size() == 2 && s[0] == s[1])
            {

                return true;
            }
        }

        return false;
    }
};



class Solution
{
public:
    bool hasSameDigits(string s)
    {

        while (s.size() > 2)
        {
            string str = "";
            for (int i = 0; i < s.size() - 1; i++)
            {
                str += to_string(((int)s[i] + (int)s[i + 1]) % 10);
            }

            s = str;
        }

        return s[0] == s[1];
    }
};