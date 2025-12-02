#include <bits/stdc++.h>
using namespace std;

void optimal()                                                      // 💡 Approach: Simulation
{
    // 🕒 Time Complexity: O(n)
    // 🧠 Space Complexity: O(1)
    
    int n;                                                          // input number of days
    cout << "Enter n: ";                                            // input prompt
    cin >> n;                                                       // taking input
    
    int count = 1, flag = 1, k = 1;                                 // count -> daily increment, flag -> next week's start
    int sum = 0;                                                    // total money saved
    
    while (k <= n)                                                  // loop for all days
    {
        sum += count;                                               // add today's money
        count++;                                                    // next day increases by 1
        if (k % 7 == 0)                                             // every 7 days, start new week
        {
            count = ++flag;                                         // new week starts from next higher value
        }
        k++;                                                        // move to next day
    }
    
    cout << "Total money: " << sum << endl;                         // output final total
}

int main()
{
    optimal();
    return 0;
}
