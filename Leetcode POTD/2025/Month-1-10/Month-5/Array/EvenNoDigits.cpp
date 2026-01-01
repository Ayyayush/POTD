#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N * log10(M))     ---> M is the maximum number in array (worst case digits)
    // Space Complexity: O(N)               ---> nums vector mein input store kar rahe hain

    int n;
    cin >> n;

    vector<int> nums(n);                    // array input lene ke liye
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];                     // input lena
    }

    long long evencount = 0;                // count karne ke liye ki kitne numbers mein even digits hain

    for (int i = 0; i < nums.size(); i++)
    {
        long long num = nums[i];
        int count = 0;

        while (num)                         // har digit count karne ke liye
        {
            int rem = num % 10;             // ek digit nikaalo
            count++;                        // count badhao
            num /= 10;                      // agla digit
        }

        if (count % 2 == 0)                 // agar digits even hain toh count badhao
        {
            evencount++;
        }
    }

    cout << evencount << endl;              // final answer print
}



void better()
{
    // Time Complexity: O(N * D)             ---> D = number of digits in each number using to_string()
    // Space Complexity: O(N)               ---> nums vector + temporary string ka space

    int n;
    cin >> n;

    vector<int> nums(n);                    // input ke liye vector
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long evencount = 0;                // count for even digit numbers

    for (int i = 0; i < nums.size(); i++)
    {
        string str = to_string(nums[i]);    // number ko string mein convert karo

        if (str.size() % 2 == 0)            // agar string ka size even hai toh count badhao
        {
            evencount++;
        }
    }

    cout << evencount << endl;              // output
}



int main()
{
    brute();                                // brute function call kar rahe hain, change kar ke better() bhi try kar sakte ho
    return 0;
}
