class Solution {
public:
    /* =========================================================
       APPROACH: Brute Force XOR from l to r
       Time Complexity: O(r - l + 1)
       Space Complexity: O(1)
       ========================================================= */
    int findXOR(int l, int r)
    {
        int ans = l;                    // initialize with l

        for (int i = l + 1; i <= r; i++)
        {
            ans = ans ^ i;              // XOR current number
        }

        return ans;
    }
};



class Solution {
public:
    /* =========================================================
       APPROACH: Mathematical XOR Pattern
       Time Complexity: O(1)
       Space Complexity: O(1)
       ========================================================= */

    int xorTillN(int n)
    {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0;
    }

    int findXOR(int l, int r)
    {
        return xorTillN(r) ^ xorTillN(l - 1);
    }
};
