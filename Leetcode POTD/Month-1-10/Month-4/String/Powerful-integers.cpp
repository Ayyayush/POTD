#include <bits/stdc++.h>
using namespace std;

void optimal()
{
    // T.C: O((n - m) * log(limit)), because har digit ke liye power calculate kar rahe (pow call)
    // S.C: O(1), koi extra space nahi use ho raha except variables

    long long start, finish;
    int limit;
    string s;

    // Input le rahe hain
    cout << "Enter start, finish, limit and suffix string: ";
    cin >> start >> finish >> limit >> s;

    // Helper function jo count karega powerful numbers upto a given string
    auto solve = [&](string str, string inputSuffix, int limit) -> long long
    {
        if(str.length() < inputSuffix.length()) return 0;                                         // Agar suffix length zyada hai to valid nahi

        long long count = 0;

        string trailString = str.substr(str.length() - inputSuffix.length());                     // End se suffix utna part le rahe
        int remainL = str.length() - inputSuffix.length();                                        // Kitne digits suffix ke alawa hain

        for(int i = 0; i < remainL; i++)
        {
            int digit = str[i] - '0';                                                              // Char to digit mein convert

            if(digit <= limit)
            {
                count += digit * pow(limit + 1, remainL - i - 1);                                  // Possible combinations for current digit
            }
            else
            {
                count += pow(limit + 1, remainL - i);                                              // Uske baad ke saare combinations valid honge
                return count;                                                                      // Early return
            }
        }

        if(trailString >= inputSuffix) count += 1;                                                // Suffix match ya bada ho to count mein le lo

        return count;                                                                             // Final count return
    };

    // Convert start - 1 and finish to strings
    string startStr = to_string(start - 1);
    string finishStr = to_string(finish);

    // Count = solve(finish) - solve(start - 1)
    long long result = solve(finishStr, s, limit) - solve(startStr, s, limit);

    cout << "Number of powerful integers: " << result << endl;                                    // Output print karo
}

int main()
{
    optimal();
    return 0;
}
