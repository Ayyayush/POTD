#include <bits/stdc++.h>
using namespace std;

void brute() // O(N^3) 
{
    int n;
    cin >> n; // Array ka size input lo
    vector<int> nums(n); // Vector create kiya array store karne ke liye
    
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array ke elements input lo
    }
    
    long long maxvalue = 0; // Maximum value track karne ke liye
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long currvalue = 0; // Current value calculate karne ke liye
            
            for (int k = j + 1; k < n; k++)
            {
                currvalue = (long long)(nums[i] - nums[j]) * nums[k]; // Formula apply karna
                
                if (currvalue > 0)
                {
                    maxvalue = max(currvalue, maxvalue); // Maximum value update karna
                }
            }
        }
    }
    cout << maxvalue << endl; // Final output print karna
}

void better() // O(N) ..S.C==O(N)
{
    int n;
    cin >> n; // Array ka size input lo
    vector<int> nums(n); // Vector create kiya array store karne ke liye
    
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array ke elements input lo
    }
    
    vector<int> leftmax(nums.size()); // Left maximum values store karne ke liye
    vector<int> rightmax(nums.size()); // Right maximum values store karne ke liye
    
    for (int i = 1; i < nums.size(); i++)
    {
        leftmax[i] = max(leftmax[i - 1], nums[i - 1]); // Left max update karna
    }
    
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        rightmax[i] = max(rightmax[i + 1], nums[i + 1]); // Right max update karna
    }
    
    long long currvalue = 0;
    long long maxvalue = 0; // Maximum value track karne ke liye
    
    for (int i = 0; i < nums.size(); i++)
    {
        currvalue = (long long)(leftmax[i] - nums[i]) * rightmax[i]; // Formula apply karna
        maxvalue = max(currvalue, maxvalue); // Maximum value update karna
    }
    
    cout << maxvalue << endl; // Final output print karna
}

void optimal() // O(N) .S.C==O(1)
{
    int n;
    cin >> n; // Array ka size input lo
    vector<int> nums(n); // Vector create kiya array store karne ke liye

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array ke elements input lo
    }
    
    long long result = 0, maxi = 0, maxdiff = 0; // Required variables initialize kiye
    
    for (int i = 0; i < nums.size(); i++)
    {
        result = max(result, maxdiff * nums[i]); // Maximum triplet value calculate karo
        maxdiff = max(maxdiff, maxi - nums[i]); // Maximum difference track karo
        maxi = max(maxi, (long long)nums[i]); // Maximum element update karo
    }
    
    cout << result << endl; // Final result print karo
}

int main()
{
    better(); // Function call karna
    return 0;
}
