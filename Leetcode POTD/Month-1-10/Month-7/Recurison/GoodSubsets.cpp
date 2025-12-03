class Solution {
public:


define MOD=100000
// Function to check if product has any prime factor dividing n
bool hasDistinctPrimeFactors(long long n)
{
    if (n == 1)
        return false; // 1 has no prime factors

    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (long long i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (long long j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    long long temp = n;
    for (long long i = 2; i <= n; i++)
    {
        if (!primes[i])
            continue;
        long long count = 0;
        while (temp % i == 0)
        {
            temp /= i;
            count++;
            if (count > 1)
                return false; // repeated prime factor found
        }
        if (temp == 1)
            break;
    }
    return true;
}



// Recursive function to generate all subsets and count 'good' subsets
void GoodSubsets(vector<long long> &nums, vector<long long> &subsets, long long idx, long long &count)
{
    // Base case: agar index array size ke barabar ho gaya, toh subset check karo
    if (idx >= nums.size())
    {
        long long prod = 1;
        for (long long i = 0; i < (long long)subsets.size(); i++)
        {
            prod *= subsets[i];
        }
        if (hasDistinctPrimeFactors(prod))
            count++;
        return;
    }

    // Recursive case 1: include current element
    subsets.push_back(nums[idx]);               // current element subset mein daalo
    GoodSubsets(nums, subsets, idx + 1, count); // next index ke liye recursive call

    // Recursive case 2: exclude current element
    subsets.pop_back();                         // backtrack: current element hatao
    GoodSubsets(nums, subsets, idx + 1, count); // next index ke liye recursive call
}

    long long numberOfGoodSubsets(vector<long long>& nums) {

            vector<long long> temp;                // Temporary vector to store current subset

    long long count = 0;
    GoodSubsets(nums, temp, 0, count); // Recursion call for subset generation

return count;
        
    }
};