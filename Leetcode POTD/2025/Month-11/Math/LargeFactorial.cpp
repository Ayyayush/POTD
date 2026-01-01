// ✅ User function template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to compute factorial of a large number
    vector<int> factorial(int n)
    {
        long long prod = 1;                              // Initial product ko 1 set kiya
        while (n >= 1)                                   // Jab tak n >= 1
        {
            prod *= n;                                   // Multiply karte jao → prod = prod * n
            n--;                                         // n ko decrement karte jao
        }

        vector<int> ans;                                 // Result store karne ke liye vector
        while (prod)                                     // Jab tak prod > 0
        {
            int rem = prod % 10;                         // Last digit nikal lo
            ans.push_back(rem);                          // Use vector me daal do
            prod /= 10;                                  // Last digit hata do
        }

        reverse(ans.begin(), ans.end());                 // Digits reverse kar do (kyunki humne ulta push kiya)
        return ans;                                      // Final factorial digits return kar do
    }
};



/****************************************************
 🧠 APPROACH - 2 (Manual Multiplication Approach)
 ----------------------------------------------------
 ⚡ Idea:
  Jab factorial bada hota hai (e.g. 100!, 200!),
  to uska result long long me fit nahi hota.
  Isliye hum har step par digits ko array me store karte hain.

 🔹 Step-by-step example for n = 5:
    5! = 5 × 4 × 3 × 2 × 1 = 120

 ----------------------------------------------------
 Let's simulate factorial(5):

 Initially:
     res[] = {1}            // Starting value 1
     res_size = 1

 Multiply by 2:
     → 1 × 2 = 2
     res[] = {2}
     res_size = 1

 Multiply by 3:
     → 2 × 3 = 6
     res[] = {6}
     res_size = 1

 Multiply by 4:
     → 6 × 4 = 24
     → Write 4, carry = 2
     → Append carry to array
     res[] = {4, 2}
     res_size = 2

 Multiply by 5:
     Step 1: 5 × 4 = 20 → write 0, carry = 2
     Step 2: 5 × 2 + 2 = 12 → write 2, carry = 1
     Step 3: Add remaining carry
     res[] = {0, 2, 1}
     res_size = 3

 ----------------------------------------------------
 🔹 Final answer: 120

 To print in correct order:
     reverse(res)
     → {1, 2, 0}

 ✅ Output: 120

 ----------------------------------------------------
 ⏱️ Time Complexity:  O(n^2)
 💾 Space Complexity: O(n)
 ****************************************************/

 // ✅ User function template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔹 Multiply function → ek particular number (multiplier) ko array me stored number se multiply karega
    int multiply(vector<int>& arr, int size, int multiplier)
    {
        int carry = 0;                                              // Starting carry 0
        for (int i = 0; i < size; i++)                              // ❌ pehle '<=' tha, par correct '<' hoga
        {
            int res = arr[i] * multiplier + carry;                  // Multiply + carry
            arr[i] = res % 10;                                      // Last digit store kar lo
            carry = res / 10;                                       // Carry update kar lo
        }

        // 🔹 Agar carry bacha hai, to uske digits bhi array me daal do
        while (carry > 0)
        {
            arr[size] = carry % 10;                                 // Last digit daalo
            carry /= 10;                                            // Carry reduce karo
            size++;                                                 // Array size badhao
        }

        return size;                                                // Naya size return karo
    }

    vector<int> factorial(int n)
    {
        vector<int> arr(10000, 0);                                  // Large array to hold digits
        arr[0] = 1;                                                 // Initially factorial(0 or 1) = 1
        int size = 1;                                               // Abhi number ka size 1 hai

        // 🔹 Multiply array number by each value from 2 to n
        for (int multiplier = 2; multiplier <= n; multiplier++)
        {
            size = multiply(arr, size, multiplier);                 // Size update hota rahega
        }

        // Ab result reverse order me hai → isliye reverse karo
        vector<int> ans;
        for (int i = size - 1; i >= 0; i--)                         // Sirf used digits reverse order me copy karo
        {
            ans.push_back(arr[i]);
        }

        return ans;                                                 // Final factorial as digit vector
    }
};
