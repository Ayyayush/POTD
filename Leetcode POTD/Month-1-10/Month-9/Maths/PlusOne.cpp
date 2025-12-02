#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ Approach: Convert digits to number, add 1, then break digits again
    // T.C = O(n)      // loop to convert digits + loop to extract digits
    // S.C = O(1)      // no extra space other than long long

    vector<int> digits = {9, 9, 9};     // input vector
    long long sum = 0;

    // Step 1: Convert vector to number
    for (int i = 0; i < digits.size(); i++)
    {
        sum = sum * 10 + digits[i];    // number banana
    }

    sum += 1;    // plus one

    // Step 2: Convert back to vector
    digits.clear();

    if (sum == 0)
    {
        digits.push_back(0);    // edge case
    }

    while (sum)
    {
        digits.push_back(sum % 10);     // last digit push
        sum /= 10;                      // number chhota karo
    }

    reverse(digits.begin(), digits.end());    // correct order

    for (int d : digits)
        cout << d << " ";    // output
    cout << endl;
}

void better()
{
    // ✅ Better Approach: Check last digit, if not 9 → just increment it
    // Else, use brute logic
    // T.C = O(n)      // worst case when all 9s → convert to number
    // S.C = O(1)

    vector<int> digits = {9, 9, 9};

    if (digits[digits.size() - 1] != 9)
    {
        digits[digits.size() - 1] += 1;
    }
    else
    {
        long long sum = 0;

        for (int i = 0; i < digits.size(); i++)
        {
            sum = sum * 10 + digits[i];    // convert to number
        }

        sum += 1;

        digits.clear();

        if (sum == 0)
            digits.push_back(0);

        while (sum)
        {
            digits.push_back(sum % 10);
            sum /= 10;
        }

        reverse(digits.begin(), digits.end());
    }

    for (int d : digits)
        cout << d << " ";
    cout << endl;
}

void optimal()
{
    // ✅ Optimal Approach: Carry-based reverse loop (no overflow risk)
    // T.C = O(n)        // Single pass from right to left
    // S.C = O(1)        // In-place manipulation

    vector<int> digits = {9, 9, 9};
    int carry = 1;

    for (int i = digits.size() - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0)
            break;
    }

    if (carry)
    {
        digits.insert(digits.begin(), carry);    // leftmost carry insert
    }

    for (int d : digits)
        cout << d << " ";
    cout << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}
