#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N)                   // ek loop for input + ek loop for sum => O(N)
    // Space Complexity: O(N)                  // vector answers mein N elements store kar rahe hain

    int n;
    cin >> n;

    vector<int> answers(n);                    // sabhi input answers ko store karne ke liye vector

    for (int i = 0; i < n; i++)
    {
        cin >> answers[i];                    // input lena
    }

    // Check kar rahe hain ki kya saare elements same hain
    bool allSame = all_of(answers.begin(), answers.end(), [&](int x)
                          {
                              return x == answers[0];            // har element answers[0] ke barabar hai ya nahi
                          });

    if (allSame)
    {
        // agar sab same hain toh simply ek aur add kar do (answers[0] + 1)
        cout << answers[0] + 1 << endl;
        return;
    }
    else
    {
        long long sum = 0;
        for (int i = 0; i < answers.size(); i++)
        {
            if (answers[i] == 1)
            {
                sum += answers[i];                               // agar 1 hai toh uska contribution 1 hi hoga
            }
            else
            {
                sum += 1 + answers[i];                           // agar x hai toh group size x+1 hota hai
            }
        }

        cout << sum << endl;                                     // final total print kar do
    }
}


void better()
{
    // Time Complexity: O(N)                    // ek baar input le rahe hain + ek baar map traverse kar rahe hain
    // Space Complexity: O(N)                   // map mein sabhi unique answers ka frequency store kar rahe hain

    int n;
    cin >> n;

    vector<int> answers(n);                   // input answers
    unordered_map<int, int> mp;              // har answer ki frequency store karne ke liye
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> answers[i];
        mp[answers[i]]++;                    // frequency badha rahe hain
    }

    for (auto it : mp)
    {
        int x = it.first;                    // answer value
        int count = it.second;               // kitni baar aaya hai

        int groupSize = x + 1;               // ek group mein x+1 elements ho sakte hain
        int groups = ceil((double)count / groupSize);    // minimum kitne groups chahiye honge
        total += groups * groupSize;         // har group ka contribution = groupSize
    }

    cout << total << endl;                   // final total print
}


int main()
{
    better();                                // better function call ho raha hai
    return 0;
}
