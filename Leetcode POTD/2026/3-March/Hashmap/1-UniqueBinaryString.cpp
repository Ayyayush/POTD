#include <bits/stdc++.h>
using namespace std;

/*
=====================================================================
PROBLEM: Find Unique Binary String
LeetCode 1980
=====================================================================

Given:
- An array nums containing n unique binary strings.
- Each string has length n.

Task:
- Return any binary string of length n that does NOT appear in nums.

Example:
nums = ["01","10"]
Possible answers = "00" or "11"

Key Idea:
Total possible binary strings of length n = 2^n
Given only n strings → at least one string must be missing.

=====================================================================
APPROACH ORDER (Descending Time Complexity)
1. Brute Force (Manual Binary Conversion + HashMap)
2. HashMap + STL Conversion
3. Simple Conversion using Set
4. Improved Conversion using Set
5. Optimal (Cantor's Diagonalization Trick)
=====================================================================
*/


/*
=====================================================================
APPROACH 1: Brute Force using HashMap + Manual Binary Conversion
=====================================================================

Idea:
1. Generate all possible numbers from 0 → (2^n - 1) and store in map.
2. Convert each binary string manually to decimal.
3. Reduce count in hashmap.
4. Any number still having count > 0 means it was missing.
5. Convert that number back to binary.

Time Complexity:
Generating numbers = O(2^n)
Manual conversion of each string = O(n) per string
Total = O(2^n + n^2)

Space Complexity:
O(2^n) for hashmap
*/

class Solution1 {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_map<int,int> mp;

        int n = nums[0].size();

        /*
         * Insert all possible decimal numbers that
         * correspond to binary strings of length n
         * Example (n=3):
         * 000 → 0
         * 001 → 1
         * ...
         * 111 → 7
         */
        for(int i = 0; i < (1 << n); i++)
        {
            mp[i]++;
        }

        /*
         * Convert each binary string into decimal manually
         * using base-2 conversion
         */
        for(int i = 0; i < nums.size(); i++)
        {
            string s = nums[i];
            int value = 0;

            for(int j = 0; j < s.size(); j++)
            {
                /*
                 * Binary to Decimal conversion
                 * Example: "101"
                 * value = (value * 2) + current_bit
                 */
                value = (value * 2) + (s[j] - '0');
            }

            mp[value]--;
        }

        /*
         * Find a number still remaining in map
         * meaning that binary string was not present
         */
        int ans = 0;

        for(auto m : mp)
        {
            if(m.second > 0)
            {
                ans = m.first;
                break;
            }
        }

        /*
         * Convert decimal answer back to binary string
         */
        string result = "";

        while(ans > 0)
        {
            result = char('0' + (ans % 2)) + result;
            ans /= 2;
        }

        /*
         * Ensure binary string length becomes n
         * by adding leading zeroes if needed
         */
        while(result.size() < n)
        {
            result = "0" + result;
        }

        return result;
    }
};



/*
=====================================================================
APPROACH 2: HashMap + STL Binary Conversion
=====================================================================

Idea:
Same as previous approach but uses STL functions:
- stoi() → converts binary string to decimal
- bitset → converts decimal back to binary

Time Complexity:
O(2^n + n)

Space Complexity:
O(2^n)
*/

class Solution2 {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_map<int,int> mp;

        int n = nums[0].size();

        /*
         * Insert all possible decimal numbers
         */
        for(int i = 0; i < (1 << n); i++)
        {
            mp[i]++;
        }

        /*
         * Convert binary string → decimal
         * using stoi with base = 2
         */
        for(int i = 0; i < nums.size(); i++)
        {
            int val = stoi(nums[i], nullptr, 2);
            mp[val]--;
        }

        int ans = 0;

        for(auto m : mp)
        {
            if(m.second > 0)
            {
                ans = m.first;
                break;
            }
        }

        /*
         * Convert decimal → binary string using bitset
         */
        bitset<16> b(ans);
        string result = b.to_string();

        /*
         * Extract last n bits
         */
        return result.substr(16 - n);
    }
};



/*
=====================================================================
APPROACH 3: Simple Conversion using Set
=====================================================================

Idea:
1. Convert each binary string → decimal
2. Store in set
3. Check numbers sequentially until we find a missing one

Time Complexity:
O(n^2)

Space Complexity:
O(n)
*/

class Solution3 {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<int> st;

        /*
         * Convert each binary string to decimal
         * and insert into set
         */
        for(string &num : nums)
        {
            st.insert(stoi(num, 0, 2));    //stoi(string, position_pointer, base)
        }

        int n = nums.size();
        string result = "";

        /*
         * Search for a number not present in set
         */
        for(int number = 0; number <= 65536; number++)
        {
            if(st.find(number) == st.end())
            {
                bitset<16> b(number);
                result = b.to_string();
                break;
            }
        }

        return result.substr(16 - n);
    }
};



/*
=====================================================================
APPROACH 4: Improved Set Approach
=====================================================================

Optimization:
Instead of checking up to 65536,
we only check from 0 → n

Because there are n numbers,
there must exist a missing number within this range.

Time Complexity:
O(n^2)

Space Complexity:
O(n)
*/

class Solution4 {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<int> st;

        for(string &num : nums)
        {
            st.insert(stoi(num, 0, 2));
        }

        int n = nums.size();
        string result = "";

        for(int number = 0; number <= n; number++)
        {
            if(st.find(number) == st.end())
            {
                bitset<16> b(number);
                result = b.to_string();
                break;
            }
        }

        return result.substr(16 - n);
    }
};



/*
=====================================================================
APPROACH 5: OPTIMAL (Cantor's Diagonalization Trick)
=====================================================================

Key Idea:
Construct a string such that it differs from every string
at least at one index.

Method:
Take i-th bit of i-th string and flip it.

Example:
nums = ["010", "111", "000"]

i=0 → nums[0][0] = 0 → flip → 1
i=1 → nums[1][1] = 1 → flip → 0
i=2 → nums[2][2] = 0 → flip → 1

Result = "101"

This guarantees the new string differs from every string
in at least one position.

Time Complexity:
O(n)

Space Complexity:
O(n)

*/

class Solution5 {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        string result = "";

        for(int i = 0; i < nums.size(); i++)
        {
            char ch = nums[i][i];

            /*
             * Flip the diagonal bit
             */
            result += (ch == '0') ? '1' : '0';
        }

        return result;
    }
};



#include <bits/stdc++.h>
using namespace std;

/*
=====================================================================
PROBLEM: Find Unique Binary String
LeetCode 1980
=====================================================================

Given:
An array nums containing n unique binary strings of length n.

Task:
Return any binary string of length n that does NOT appear in nums.

Example:
nums = ["01","10"]

Possible answers:
"00"
"11"

---------------------------------------------------------------------
Idea (Recursion + Backtracking)
---------------------------------------------------------------------

1. Generate all possible binary strings of length n using recursion.

2. At each index we have 2 choices:
   - Put '0'
   - Put '1'

3. Once the generated string length becomes n:
      check if it exists in the given set.

4. If it does NOT exist → return it as answer.

5. Stop recursion once answer is found.

---------------------------------------------------------------------
Total Binary Strings = 2^n
Checking each string in set = O(1)

Time Complexity  : O(2^n)
Space Complexity : O(n) recursion stack
=====================================================================
*/

class Solution {

public:

    /*
     * Backtracking function to generate binary strings
     *
     * index  -> current position we are filling
     * temp   -> currently constructed string
     * st     -> set containing existing binary strings
     * result -> stores answer when found
     * n      -> required string length
     */
    void generate(int index,
                  string &temp,
                  unordered_set<string> &st,
                  string &result,
                  int n)
    {

        /*
         * Base Case
         * When string length becomes n
         */
        if(index == n)
        {
            /*
             * If generated string does not exist in nums
             * then this is our answer
             */
            if(st.find(temp) == st.end())
            {
                result = temp;
            }
            return;
        }

        /*
         * If answer already found
         * stop further recursion
         */
        if(result != "") return;


        /*
         * Choice 1 → Place '0'
         */
        temp.push_back('0');
        generate(index + 1, temp, st, result, n);
        temp.pop_back();     // Backtrack


        /*
         * Choice 2 → Place '1'
         */
        temp.push_back('1');
        generate(index + 1, temp, st, result, n);
        temp.pop_back();     // Backtrack
    }


    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();

        /*
         * Store all given strings in a set
         * for O(1) lookup
         */
        unordered_set<string> st(nums.begin(), nums.end());

        string temp = "";
        string result = "";

        /*
         * Start recursion from index 0
         */
        generate(0, temp, st, result, n);

        return result;
    }
};