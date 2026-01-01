#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Basic Calculator (LeetCode)
 * Link   : https://leetcode.com/problems/basic-calculator/
 * Video  : https://www.youtube.com/watch?v=3AEKyHx3tzU
 * Tags   : Google, Facebook, Airbnb
 * Logic  : Stack-based simulation of expression with signs and parentheses
 *
 * Time Complexity  : O(N)  - We iterate through the string once
 * Space Complexity : O(N)  - Stack stores result and sign for each open parenthesis
 */

/*
 * Function : void better()
 * Purpose  : Evaluate a basic arithmetic expression string containing integers,
 *            '+', '-', '(', ')', and empty spaces.
 */
void better()
{
    /*
     * Sample Input 1 : "(1+(4+5+2)-3)+(6+8)"
     * Expected Output: 23
     * Explanation     : (1+(4+5+2)-3)+(6+8) = (1+11-3)+14 = 9 + 14 = 23
     */

    string s;
    cout << "Enter expression: ";
    getline(cin, s); // To allow input with spaces

    stack<int> st;     // Stack to store intermediate results and signs
    int number = 0;    // To form multi-digit numbers
    int result = 0;    // Final result
    int sign = 1;      // +1 for positive, -1 for negative

    /*
     * Traverse each character in the input string
     */
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        /*
         * If current character is a digit, form the complete number
         */
        if (isdigit(ch))
        {
            number = number * 10 + (ch - '0');
        }

        /*
         * If '+' is encountered, add the previous number with its sign to result
         * and reset number. Set sign to +1 for upcoming number
         */
        else if (ch == '+')
        {
            result += sign * number;
            number = 0;
            sign = 1;
        }

        /*
         * If '-' is encountered, add the previous number with its sign to result
         * and reset number. Set sign to -1 for upcoming number
         */
        else if (ch == '-')
        {
            result += sign * number;
            number = 0;
            sign = -1;
        }

        /*
         * If '(' is encountered, push the current result and sign into stack
         * and reset them to start a new sub-expression
         */
        else if (ch == '(')
        {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        }

        /*
         * If ')' is encountered, complete the inner expression by first
         * adding the last number, then multiplying with the sign and
         * finally adding with the result before '('
         */
        else if (ch == ')')
        {
            result += sign * number;
            number = 0;

            int prevSign = st.top(); st.pop();     // sign before '('
            int prevRes  = st.top(); st.pop();     // result before '('

            result = prevRes + (prevSign * result);
        }

        /*
         * If space is encountered, ignore it
         */
    }

    /*
     * Finally, add any leftover number
     */
    result += sign * number;

    cout << "Evaluated Result = " << result << endl;
}

/*
 * Driver Code
 */
int main()
{
    better();
    return 0;
}
