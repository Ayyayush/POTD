/**
 * Count Distinct Integers After Removing Zeroes
 * 
 * Idea:
 * 1) 1 se n tak saare numbers iterate karenge.
 * 2) Agar number mein '0' hai → saare zero hata kar new number banao.
 * 3) Jo final number banega, usse unordered_set mein daal do (distinct ke liye).
 * 4) Last mein set ka size return kar do.
 */

class Solution
{
public:
    long long countDistinct(long long n)
    {
        unordered_set<long long> st;                         // distinct values store karne ke liye

        for (long long i = 1; i <= n; i++)                   // 1 se n tak iterate
        {
            string num = to_string(i);                       // current number ko string mein convert

            if (num.find('0') != string::npos)               // check: agar number mein kahin '0' hai
            {
                string str = "";                             // zero remove karke new string banayenge

                for (int j = 0; j < num.size(); j++)         // har character check karenge
                {
                    if (num[j] != '0')                       // agar zero nahi hai
                        str += num[j];                       // toh new number string mein add
                }

                st.insert(stoll(str));                       // string → long long convert karke set mein daal do
            }
            else
            {
                st.insert(i);                                // agar zero nahi tha, original number daal do
            }
        }

        return st.size();                                    // total distinct numbers return
    }
};
