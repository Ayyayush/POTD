#include <bits/stdc++.h>
using namespace std;

/**
 * ! Count Binary Substrings 
 * 
 * s = "00110011"
 * output should be 6
 * 
 * iss problem mein catch ye h ki:
 * substring mein 0s aur 1s equal hone chahiye
 * AND
 * wo consecutively grouped hone chahiye
 * 
 * valid examples:
 * "0011"
 * "01"
 * "1100"
 * 
 * invalid:
 * "0101"  (kyunki alternating hai)
 */



// ! ========================== BRUTE FORCE ==========================
void brute()
{
    /*
    ! Approach Name: Brute Force (All Substrings + Manual Group Check)
    ! Time Complexity: O(n^3)
    ! Space Complexity: O(1)
    */

    string s = "00110011";
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int zero = 0, one = 0;

        for (int j = i; j < n; j++)
        {
            if (s[j] == '0')
                zero++;
            else
                one++;

            if (zero == one)
            {
                bool valid = true;

                char firstChar = s[i];
                int k = i;

                while (k <= j && s[k] == firstChar)
                    k++;

                char secondChar = (firstChar == '0') ? '1' : '0';

                while (k <= j && s[k] == secondChar)
                    k++;

                if (k != j + 1)
                    valid = false;

                if (valid)
                    count++;
            }
        }
    }

    cout << "Brute Answer: " << count << endl;
}




// ! ========================== BETTER ==========================
void better()
{
    /*
    ! Approach Name: Two Group Counting (Expand Valid Window Only)

    ! Idea:
    Instead of generating all substrings,
    har index se sirf valid alternating pair banane ki koshish karenge.

    For every index i:
        Agar s[i] != s[i+1],
        toh left aur right side expand karke equal consecutive
        0s aur 1s count karenge.

    ! Time Complexity: O(n^2)
    ! Space Complexity: O(1)
    */

    string s = "00110011";
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])   // valid starting boundary
        {
            int left = i;
            int right = i + 1;

            char leftChar = s[left];
            char rightChar = s[right];

            int leftCount = 0;
            int rightCount = 0;

            // Count consecutive left group
            while (left >= 0 && s[left] == leftChar)
            {
                leftCount++;
                left--;
            }

            // Count consecutive right group
            while (right < n && s[right] == rightChar)
            {
                rightCount++;
                right++;
            }

            count += min(leftCount, rightCount);
        }
    }

    cout << "Better Answer: " << count << endl;
}




// ! ========================== OPTIMAL ==========================
void optimal()
{
    /*
    ! Approach Name: Group Length Comparison
    ! Time Complexity: O(n)
    ! Space Complexity: O(1)
    */

    string s = "00110011";
    int n = s.length();

    int result = 0;
    int prev = 0;
    int curr = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            result += min(prev, curr);
            prev = curr;
            curr = 1;
        }
        else
        {
            curr++;
        }
    }

    result += min(prev, curr);

    cout << "Optimal Answer: " << result << endl;
}



int main()
{
    brute();
    better();
    optimal();
    return 0;
}



/*
! ========================== JS Optimal ==========================

function countBinarySubstrings(s) {
    let prev = 0;
    let curr = 1;
    let result = 0;

    for (let i = 1; i < s.length; i++) {
        if (s[i] !== s[i - 1]) {
            result += Math.min(prev, curr);
            prev = curr;
            curr = 1;
        } else {
            curr++;
        }
    }

    return result + Math.min(prev, curr);
}


! ========================== Python Optimal ==========================

def countBinarySubstrings(s):
    prev = 0
    curr = 1
    result = 0

    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            result += min(prev, curr)
            prev = curr
            curr = 1
        else:
            curr += 1

    return result + min(prev, curr)

*/