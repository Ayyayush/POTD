class Solution
{
public:

    // ! APPROACH : Triple Loop Brute Force
    // ! T.C. : O(N^3)
    // ! S.C. : O(1)

    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> C;

        for (int i = 0; i < A.size(); i++)
        {
            int count = 0;

            for (int j = 0; j <= i; j++)
            {
                int k = 0;

                while (k <= i)
                {
                    if (B[j] == A[k])
                    {
                        count++;
                    }

                    k++;
                }
            }

            C.push_back(count);
        }

        return C;          // always give if exists
    }
};

class Solution {
public:

    // ! APPROACH : HashMap
    // ! T.C. : O(N^2)
    // ! S.C. : O(N)

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();

        vector<int> C(n, 0);

        for(int i = 0; i < n; i++)
        {
            unordered_map<int,int> mp;

            int count = 0;

            for(int j = 0; j <= i; j++)
            {
                mp[A[j]]++;
            }

            for(int j = 0; j <= i; j++)
            {
                if(mp.count(B[j]))
                {
                    count++;
                }
            }

            C[i] = count;
        }

        return C;          // always give if exists
    }
};