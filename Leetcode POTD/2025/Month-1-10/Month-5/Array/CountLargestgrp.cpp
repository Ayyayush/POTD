#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Input lena hoga yahan pe
    int n;
    cout << "Enter n: ";
    cin >> n;

    map<int, int> mp;                              // Digit sum -> frequency ka map

    for (int i = 1; i <= n; i++)                   
    {
        int num = i;
        int sum = 0;                                // Har number ka digit sum calculate karenge

        while (num)                                 
        {
            int rem = num % 10;                     // Last digit nikaalo
            sum += rem;                             // Digit sum mein add karo
            num /= 10;                              // Number chhota karo
        }

        mp[sum]++;                                  // Is digit sum ke count ko badhao
    }

    int largest = 0;                                // Sabse bada group size nikaalne ke liye
    for (auto it : mp)
    {
        largest = max(largest, it.second);         // Max group size track kar rahe hain
    }

    int count = 0;                                  // Count of groups with max size
    for (auto it : mp)
    {
        if (it.second == largest)                  // Jinke paas max size hai, unhe count karo
            count++;
    }

    cout << count << endl;                         // Final answer print karo
}


void better()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    unordered_map<int, int> mp;                  // Digit sum -> frequency map
    int maxsize = 0;                             // Sabse bada group size track karenge
    int count = 0;                               // Max size wale groups ka count

    for (int i = 1; i <= n; i++)
    {
        int num = i;
        int sum = 0;

        while (num)
        {
            int rem = num % 10;                  // Last digit lo
            sum += rem;                          // Sum mein add karo
            num /= 10;                           // Digit hatao
        }

        mp[sum]++;                               // Us sum wale group mein count badhao

        if (mp[sum] == maxsize)                  // Agar current group size max ke barabar hai
            count++;                             // To max count bhi badhao
        else if (mp[sum] > maxsize)              // Agar naye group ka size max se bada ho gaya
        {
            maxsize = mp[sum];                   // Max size ko update karo
            count = 1;                           // Naya max mila, to count ko 1 se shuru karo
        }
    }

    cout << count << endl;                       // Answer print karo
}

int main()
{
    better();
    return 0;
}
