#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    // Method: Brute Force (Nested while loop)
    // T.C. = O(n^2)      (worst case jab saare elements 0 ho)
    // S.C. = O(1)        (constant space)

    int n;
    cin >> n;                             // input size
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];   // input array

    long long count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (nums[i] == 0) 
        {
            int j = i;
            while (j < n && nums[j] == 0)   // consecutive zeros count
            {
                count++;
                j++;
            }
        }
    }

    cout << count << endl;   // output
}

void better() 
{
    // Method: Improved Counting (prefix contribution method)
    // T.C. = O(n)         (single pass)
    // S.C. = O(1)         (constant space)

    int n;
    cin >> n;                             // input size
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];   // input array

    long long count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (nums[i] == 0) 
        {
            int k = 0;
            while (i < n && nums[i] == 0)   // consecutive zero stretch
            {
                k++;            
                count += k;     // har naye 0 par naye subarrays add hote hain
                i++;
            }
        }
    }

    cout << count << endl;   // output
}

int main() 
{
    brute();
    better();
    return 0;
}
