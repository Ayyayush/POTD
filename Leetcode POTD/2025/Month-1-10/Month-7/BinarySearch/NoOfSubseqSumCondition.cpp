/**
 * *APPROACH 1
 * using bakctracking subset method
 * TLE de dega
 */

/**
 * *APPROACH 2
 * building solution
 * num binary search laga skte h kyunki order se mtlb nhi bas min max se main mtlb h
 * eg ::    3,5,6,7
 * min maan lo 3 h    max 7 h    ...3 aur 7 ke beech kuch bhi hone se fark nhi padta
 * aur agar min + max bada ho rha target se so max ko directly reject kr do
 * kyunki 7 akela bhi aaya toh 7+7 hoke reject ho jayega
 * uske left slide krke left aaye 6 mila
 * 3+6 valid h toh le lenge beech mein koi bhi ho fark nhi padta
 * permuation combination krke bhot subsequence ban skta h aise min aur max shi h toh
 * ab dekho
 * *POSSIBILITY
 * 3 fix h 5 aur 6 ko dekho
 * 5 ko 2 possibility lo ya nhi
 * 6 ko 2 possibility lo ya nhi
 * total 4 possibility  2^2
 * power kitna karna h milega r-l se
 *
 *
 * Continue Dry Run
 * 3 fix h
 * 3,5 lo    6 choro
 * 3,6 lo    5 choro
 * 3,5,6   ..total ans =4 abtak
 * ab low ko right slide karo next pe jao
 *
 *
 * ab 5 ko fix krke dekho
 * 5 min   6 max gaalt h
 * toh 6 ko toh sidhe exclude karo
 *
 * ab bas 5 bacha 5+5 bhi exclude
 *
 * aur left slide kiya
 * loop break ho gya
 *
 *
 *
 * Waise hi
 * Sort karo
 *  2,3,3,4,6,7    target ==12   ispe dryrun krke dekh lo
 *  2 ko pehle fix kiya  sidhe mil gya curr answer 32
 * ab left ko right slide karo ab 3 se krke dekho valid h toh curr+=16
 * aise end tak karo
 */

void better()
{ 
    vector<int> nums = {3, 5, 6, 7}; // 🔹 Input array
    int target = 9;                  // 🔹 Target value

    int n = nums.size();
    int M = 1e9 + 7; // 🔹 Modulo constant to prevent overflow

    sort(nums.begin(), nums.end()); // 🔸 Step 1: Sort the array in non-decreasing order

    vector<int> power(n, 1); // 🔸 Step 2: Precompute powers of 2 modulo M
    // power[i] = 2^i % M
    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i - 1] * 2) % M; // Recurrence relation: 2^i = 2^(i-1) * 2
    }

    int l = 0, r = n - 1; // 🔸 Step 3: Two pointer approach
    int result = 0;       // Result variable to store total valid subsequences

    while (l <= r)
    {
        // Check if the current pair sum is within the target
        if (nums[l] + nums[r] <= target)
        {
            // 🔹 Valid pair → nums[l] can be minimum of a valid subsequence, and any subset of elements between l & r is allowed
            // Total subsequences = 2^(r - l)
            result = (result + power[r - l]) % M;
            l++; // Try next element from the left
        }
        else
        {
            r--; // Current sum too big → reduce right pointer
        }
    }

    cout << "Number of valid subsequences: " << result << endl;
}

int main()
{
    better();
    return 0;
}
