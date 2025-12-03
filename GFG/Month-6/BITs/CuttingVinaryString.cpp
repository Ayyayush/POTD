/**
 * leading zeores nhi hone chhaiye
 * substring mein divide karo taaki uss substirng ka decimal value 5 ka power ho
 *
 *
 * *BRUTE
 * two pointer approach se shuru karenge
 * hum ek char ka substring extract krke baaki ke liye recursion call kar do
 * baaki ka kaam toh recursion kar denge
 * agar substring ka pehla character zero nhi h aur power of 5 h toh count++
 *
 *
 *
 */

class Solution
{
public:
    int cuts(string s)
    {
        string res = "101";
        int count = 0;

        size_t index = s.find(res); // Use size_t for find()
        while (index != string::npos)
        {
            s.erase(index, res.length()); // Remove "101"
            count++;
            index = s.find(res); // Find again from start
        }

        return (count == 0) ? -1 : count;
    }
};

/**
 *if(s[i]!=0)
 * 
 * {
 * power of 5 h ki nhi ab ye check krna padega
 * }
 *
 * hum ek ds mein power of 5 store karenge taaki ocnstant time pe pata kare
 * toh map use krte h kaisa
 * aur phir jo substring h usko decimal mein convetr toh kr hi skte h
 *
 */