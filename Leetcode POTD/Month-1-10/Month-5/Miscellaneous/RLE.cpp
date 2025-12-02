#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;                  
    cin >> n;               // User se input le rahe hain n ka

    if (n == 1)
    {
        cout << "1\n";      
        return;             // Base case: agar n == 1 hai, to direct "1" print kardo
    }

    function<string(int)> countAndSay = [&](int n) -> string
    {
        if (n == 1) return "1";          // Base case: agar n == 1 hai to "1" return karo

        string say = countAndSay(n - 1); // Pehle wale number ka pattern dekhne ke liye recursive call
        string result = "";

        for (int i = 0; i < say.length(); i++)
        {
            char ch = say[i];           // Current character ko store karo
            int count = 1;              // Us character ki counting start karo

            while (i + 1 < say.length() && say[i] == say[i + 1])
            {
                count++;                // Jab tak same character milta jaaye, count badhate jaao
                i++;
            }

            result += to_string(count) + ch;   // Count aur character ko result mein jod do
        }

        return result;
    };

    cout << countAndSay(n) << endl;     // Final result ko print kar do
}
