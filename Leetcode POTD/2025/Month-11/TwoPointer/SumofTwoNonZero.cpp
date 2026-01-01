class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int i = 1, j = n - 1;
        vector<int> arr;
        int sum = 0;
        while (i <= j)
        {
            int numi = i, numj = j;
            while (numi)
            {
                int rem = numi % 10;
                if (rem == 0)
                {
                    i++;
                    numi = i;
                    continue;
                }
                numi /= 10;
            }

            while (numj)
            {
                int rem = numj % 10;
                if (rem == 0)
                {
                    j--;
                    numj = j;
                    continue;
                }
                numj /= 10;
            }

            sum = i + j;
            if (sum == n)
            {
                arr.push_back(i);
                arr.push_back(j);
                break;
            }
            if (sum < n)
                i++;
            else
                j--;
        }

        return arr;
    }
};