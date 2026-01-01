#include <bits/stdc++.h>                       // Sabhi standard C++ libraries include karne ke liye
using namespace std;

void brute()
{
    // Time Complexity: O(n * d) → yahan n = high - low + 1 aur d = number of digits in i
    // Har number ke liye uske digits ka sum calculate ho raha hai
    // Space Complexity: O(1) → koi extra space use nahi ho rahi except fixed variables

    int low, high;
    cin >> low >> high;                        // Range input le rahe hain

    long long count = 0;                       // Lucky numbers ka count store karega

    for (int i = low ; i <= high; i++)         // Har number i check karenge range me
    {
        long long sum1 = 0, sum2 = 0;          // First half aur second half ka sum

        string str = to_string(i);             // Number ko string me convert kiya

        if (str.size() % 2 != 0)               // Agar number of digits odd hai toh skip
            continue;

        for (int j = 0; j < str.size() / 2; j++)        // First half ka sum calculate kiya
        {
            sum1 += str[j] - '0';                       // Character se digit me convert karke add kiya
        }

        for (int j = (str.size() / 2); j < str.size(); j++)    // Second half ka sum calculate kiya
        {
            sum2 += str[j] - '0';
        }

        if (sum1 == sum2)                       // Agar dono half ka sum equal hai toh lucky number
        {
            count++;
        }
    }

    cout << count << endl;                      // Final count print kiya
}

int main()
{
    brute();                                    // Brute force function call
    return 0;
}
