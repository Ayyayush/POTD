#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // nested loops i,j,k use krke 
}

void better()
{
    // Time Complexity: O(n)                 // 2 loops lag rahe hain - outer loop n-2 times, inner loop fixed 3 times
    // Space Complexity: O(n)                 // vector 'nums' ke liye extra space use ho raha hai

    int n;                                    
    cin >> n;                                 // n input le rahe hain (size of array)

    vector<int> nums(n);                      
    for (int i = 0; i < n; i++)               
    {
        cin >> nums[i];                       // array ke elements input kar rahe hain
    }

    int count = 0;                             // valid triplet ka count rakhne ke liye

    for (int i = 0; i < nums.size() - 2; i++)  // i ko 0 se n-3 tak iterate karenge
    {
        long long sum = 0, summid = 0, k = 0;  // sum -> corner elements ka sum, summid -> middle element ka sum (basically 1 element), k -> index control ke liye

        for (int j = i; j < i + 3; j++)         // current index se leke 3 elements ka group banayenge
        {
            if (k == 0 || k == 2)               // agar pehla ya teesra element hai
                sum += nums[j];                 // sum mein add karenge
            else
                summid += nums[j];              // beech ka element summid mein jaayega
            k++;                                // next element ke liye k badhayenge
        }

        cout << sum << " " << summid << endl;   // har group ka sum aur summid print karenge (debugging ke liye)

        if (sum == (summid / 2) && sum * 2 == summid)   // yaha condition check kar rahe hain ki sum = middle_element/2 hona chahiye
            count++;                           // agar haan to count badha denge
    }

    cout << count << endl;                      // final count print karenge
}


void optimal()
{
    
}


int main()
{
    brute();                                    // brute function call karenge
    return 0;
}
