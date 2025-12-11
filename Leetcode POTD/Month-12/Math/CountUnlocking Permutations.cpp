/**
 * Count Unlocking Permutations
 * 
 * What this problem says:
 * ------------------------
 * We have 'n' computers labelled 0 to n-1.
 * Each computer has a password with some complexity value.
 * 
 * Computer 0 is already unlocked (root machine).
 * 
 * To unlock computer 'i':
 *    → You must have already unlocked some computer 'j'
 *    → such that: j < i  AND  complexity[j] < complexity[i]
 * 
 * Meaning:
 * A computer with a higher complexity can be unlocked using
 * any previously unlocked computer that has:
 *       (1) a smaller index
 *       (2) a strictly lower complexity
 * 
 * Our job:
 * Count how many permutations of [0,1,2,...,n-1]
 * form a valid unlocking order following the above rule.
 * Return the answer modulo 1e9+7.
 * 
 * 
 * Example :: 1
 * -----------
 * Input  : complexity = [1, 2, 3]
 * Valid orders:
 *      [0, 1, 2]
 *      [0, 2, 1]
 * Explanation:
 *  - 0 is unlocked
 *  - 1 can be unlocked using 0 (1 > 0)
 *  - 2 can be unlocked using either 0 or 1 (2 > both)
 * Total valid permutations = 2
 * 
 * 
 * Example :: 2
 * -----------
 * Input  : complexity = [3, 3, 3, 4, 4, 4]
 * 
 * Computers with complexity = 3 (labels 1,2) need some j < i
 * with smaller complexity — but none exists (0 also has 3).
 * So those machines cannot ever be unlocked.
 * Therefore, number of valid permutations = 0.
 * 
 */


 class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int first = complexity[0];

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= first) return 0;
        }

        long long fact = 1;
        for (int i = 2; i < n; i++) {
            fact = (fact * i) % MOD;
        }

        return (int)fact;
    }
};


        for i in range(2, n):
            fact = (fact * i) % MOD
