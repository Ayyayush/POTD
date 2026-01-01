#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2)
    // Kyuki har subarray ke liye loop chala rahe hain (i to j), toh nested loops O(n^2)
    // Space Complexity: O(n) for the input array

    int n;
    cin >> n;                                       // Input size of array

    vector<int> nums(n);                            // Array declaration
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];                             // Input array elements
    }

    int k, subcount = 0;
    cin>>k;
   

  
    for(int i = 0; i < nums.size(); i++)
    {
      long long sum=0;

        for(int j = i; j < nums.size(); j++)
        {
          sum+=nums[j];
           if(sum%k==0)
           {
            subcount++;
           }
        }
    }

    cout << subcount << endl;                       // Print final count
}


void better()
{
    
}
int main()
{
    brute();
    return 0;
}


