#include <bits/stdc++.h>
using namespace std;

void brute()        // 🔹 Time Complexity: O(N)  → Ek baar string ko reverse traverse kar rahe hain  
// 🔹 Space Complexity: O(1)  → Koi extra space use nahi ho raha, bas ek variable "num"  

{
    string num;  
    getline(cin, num);      // Pura line input lene ke liye getline use kiya  

    

    for(int i = num.size() - 1; i >= 0; i--)     // String ko reverse traverse kar rahe hain  
    {
        int n = num[i] - '0';    // Character ko integer me convert kar rahe hain  

        

        if(n%2!= 0)    // Agar non-zero digit mil jaye toh baaki string hata deni hai  
        {
            num.erase(num.begin() + i+1, num.end());     // i index se end tak ka part delete kar rahe hain  

            
            cout << num << endl;    // Updated string print kar rahe hain  
            return;     // Function se exit ho rahe hain kyunki ek hi change karna hai  
        }
        else
        {
            if(i==0)
            {
                num.erase(num.begin() + i, num.end());     // i index se end tak ka part delete kar rahe hain     
            }
            num.erase(num.begin() + i+1, num.end());     // i index se end tak ka part delete kar rahe hain   
        }
    }
    cout<<num<<endl;
}


void betterGreedy()
{
      // 🔹 Time Complexity: O(N)  → Ek baar traverse kar rahe hain  
        // 🔹 Space Complexity: O(1)  → Koi extra space use nahi ho raha  
    
        string num;  
    cin >> num;     // Input string le rahe hain  

    

    for(int i = num.size() - 1; i >= 0; i--)     // Right to left traverse kar rahe hain  
    {
        int digit = num[i] - '0';    // Character ko integer me convert kar rahe hain  

        

        if(digit % 2 == 1)    // Agar digit odd hai toh wahi largest odd number hai  
        {
            cout << num.substr(0, i + 1) << endl;    // i tak ka substring return kar rahe hain  
            return;     // Function se exit  
        }
    }

    

    cout << "" << endl;    // Koi odd digit nahi mila toh empty string return  
}




int main()
{
    betterGreedy();    // brute function call kiya  
    return 0;
}
