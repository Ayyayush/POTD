#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // 🔹 Time Complexity: O(N) → Ek pass me string traverse kar rahe hain  
    // 🔹 Space Complexity: O(1) → Koi extra space use nahi ho raha  

    string str;
    getline(cin, str);    // Input pura line lena hai  

    

    int countL = 0, countR = 0, totalCount = 0;    // `countL` = 'L' ka count, `countR` = 'R' ka count  

    

    for (char ch : str)    // Har character traverse karenge  
    {
        if (ch == 'L')    // Agar 'L' hai toh `countL++`  
            countL++;
        else if (ch == 'R')    // Agar 'R' hai toh `countR++`  
            countR++;

        

        if (countL == countR)    // ✅ Jab bhi 'L' aur 'R' equal ho jaye, ek balanced substring mil gayi  
        {
            totalCount++;    // Balanced substring count badhaya  
            countL = 0, countR = 0;    // Count reset kiya nayi substring ke liye  
        }
    }

    

    cout << totalCount << endl;    // Final answer print kar rahe hain  
}

int main()
{
    brute();    // Function call kiya  
    return 0;
}
