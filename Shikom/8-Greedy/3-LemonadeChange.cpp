#include <bits/stdc++.h>
using namespace std;

void optimal()
{
    // APPROACH: Greedy
    // We try to give change using available ₹5 and ₹10 bills optimally
    // Always prefer giving ₹10 + ₹5 for a ₹20 bill if possible

    // TIME COMPLEXITY: O(n)
    // SPACE COMPLEXITY: O(1)

    vector<int> bills = {5, 5, 5, 10, 20};      // sample input

    int five = 0, ten = 0;                      // count of ₹5 and ₹10 bills

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            five++;                             // no change required
        }
        else if (bills[i] == 10)
        {
            if (five <= 0)                      // need one ₹5 as change
            {
                cout << "false";
                return;
            }
            five--;
            ten++;
        }
        else                                    // bill == 20
        {
            if (ten >= 1 && five >= 1)          // best option: ₹10 + ₹5
            {
                ten--;
                five--;
            }
            else if (five >= 3)                 // fallback: three ₹5 bills
            {
                five -= 3;
            }
            else                                // no valid change possible
            {
                cout << "false";
                return;
            }
        }
    }

    cout << "true";                             // change possible for all customers
}

int main()
{
    optimal();
    return 0;
}
