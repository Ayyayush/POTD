#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2)     ---> 2 nested loops laga ke saare pair ka XOR nikaal rahe
    // Space Complexity: O(1)      ---> Extra space use nahi ho raha

    vector<int> arr = {3, 10, 5, 25, 2, 8};         // Sample input vector
    int maxans = 0;                                 // Maximum XOR value track karne ke liye

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)    // Har pair ko check kar rahe, j = i+1 se start
        {
            int xorval = arr[i] ^ arr[j];           // XOR nikaala dono elements ka
            maxans = max(maxans, xorval);           // Maximum update kiya agar naya value bada ho
        }
    }

    cout << "Maximum XOR of any two elements = " << maxans << endl;   // Output
}


void better()
{
    int n;
    cin>>n;
    vector<int><arr(n);
    
}

int main()
{
    void brute();
    return 0;
}