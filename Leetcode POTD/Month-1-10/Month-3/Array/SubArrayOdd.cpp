#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Brute force approach using nested loops                                 
    // Har subarray ka sum calculate karke check karenge ki odd hai ya nahi   
    // Time Complexity: O(N^2) (Nested loops ke wajah se)                     
}

void better()
{
    // Optimized approach using prefix sum parity tracking                    
    // Time Complexity: O(N), Space Complexity: O(1)                           
    
    int n, count = 0, currsum = 0;  // `count` stores odd sum subarrays count, `currsum` tracks prefix sum
    cin >> n;
    
    vector<int> arr(n);  // Input array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];  // Taking array input
    }
   
    int evenprefix = 1, oddprefix = 0;  // Initially, even prefix count = 1 (for sum = 0), odd prefix = 0

    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];  // Current prefix sum

        if (currsum % 2 == 0)  // Agar prefix sum even hai
        {
            count = count + oddprefix;  // Even prefix sum se sirf odd wale prefix count add honge
            evenprefix++;  // Even prefix count badha diya
        }
        else  // Agar prefix sum odd hai
        {
            count += evenprefix;  // Odd prefix sum se sirf even wale prefix count add honge
            oddprefix++;  // Odd prefix count badha diya
        }
    }
    
    cout << count << endl;  // Total odd sum subarrays ka count print kiya
}

int main()
{
    better();  // Calling the optimized function
    return 0;
}
