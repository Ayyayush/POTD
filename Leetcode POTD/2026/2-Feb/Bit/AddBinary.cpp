#include <bits/stdc++.h>
using namespace std;

/*
============================================================
PROBLEM: Add Binary
LeetCode 67
============================================================

Interview Steps:
1) Binary addition like school math (right → left)
2) Handle carry properly
3) Reverse final answer
*/


void brute()
{
    /*
    ------------------------------------------------------------
    Approach: Convert to Decimal → Add → Convert back
    Time Complexity: O(n)
    Space Complexity: O(1)
    NOTE: May overflow for large inputs
    ------------------------------------------------------------
    */

    string a = "1010";
    string b = "1011";

    long long num1 = 0, num2 = 0;

    for (char c : a)
        num1 = num1 * 2 + (c - '0');

    for (char c : b)
        num2 = num2 * 2 + (c - '0');

    long long sum = num1 + num2;

    if (sum == 0)
    {
        cout << "Brute Output: 0" << endl;
        return;
    }

    string ans = "";

    while (sum > 0)
    {
        ans += char((sum % 2) + '0');
        sum /= 2;
    }

    reverse(ans.begin(), ans.end());

    cout << "Brute Output: " << ans << endl;
}


void better()
{
    /*
    ------------------------------------------------------------
    Approach: Simulate Binary Addition (Extra String Reverse)
    Time Complexity: O(n)
    Space Complexity: O(n)
    ------------------------------------------------------------
    */

    string a = "1010";
    string b = "1011";

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string ans = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        ans += char((sum % 2) + '0');
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());

    cout << "Better Output: " << ans << endl;
}


void optimal()
{
    /*
    ------------------------------------------------------------
    Approach: Same as Better (Binary Addition)
    But Build Result Efficiently
    Time Complexity: O(n)
    Space Complexity: O(n)
    ------------------------------------------------------------
    */

    string a = "1010";
    string b = "1011";

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string ans;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }

        ans.push_back(char((sum % 2) + '0'));
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());

    cout << "Optimal Output: " << ans << endl;
}


int main()
{
    brute();
    better();
    optimal();
    return 0;
}


/*
============================================================
Optimal Approach in JavaScript
============================================================

function addBinary(a, b) {
    let i = a.length - 1;
    let j = b.length - 1;
    let carry = 0;
    let result = "";

    while (i >= 0 || j >= 0 || carry) {
        let sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result = (sum % 2) + result;
        carry = Math.floor(sum / 2);
    }

    return result;
}
*/


/*
============================================================
Optimal Approach in Python
============================================================

def addBinary(a, b):
    i = len(a) - 1
    j = len(b) - 1
    carry = 0
    result = []

    while i >= 0 or j >= 0 or carry:
        total = carry

        if i >= 0:
            total += int(a[i])
            i -= 1

        if j >= 0:
            total += int(b[j])
            j -= 1

        result.append(str(total % 2))
        carry = total // 2

    return ''.join(reversed(result))
*/