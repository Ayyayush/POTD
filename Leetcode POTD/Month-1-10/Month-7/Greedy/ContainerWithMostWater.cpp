#include <bits/stdc++.h>
using namespace std;

void better()
{
    // 💡 Approach: Two Pointer Technique (Greedy)                         
    // 📈 Time Complexity: O(n) – Single traversal from both ends
    // 🧠 Space Complexity: O(1) – No extra space used

    int n;                          
    cin >> n;                       // 🔹 Input size of the height array

    vector<int> height(n);         
    for (int i = 0; i < n; i++)    
        cin >> height[i];          // 🔹 Input the height of each line

    int i = 0;                      // 🔹 Left pointer
    int j = n - 1;                  // 🔹 Right pointer
    int maxwater = 0;              // 🔹 Variable to store the maximum area (water that can be held)

    while (i < j)                  // 🔄 While pointers do not overlap
    {
        int width = j - i;                                     // 🔹 Width between the two lines
        int ht = min(height[i], height[j]);                    // 🔹 Height is min of the two lines
        int area = ht * width;                                 // 🔹 Area = height × width
        maxwater = max(maxwater, area);                        // 🔹 Update maximum area found so far

        if (height[i] < height[j]) i++;                        // 🔁 Move the shorter line inward
        else j--;                                              // 🔁 Else move the other one
    }

    cout << maxwater << endl;      // 🖨️ Output the maximum area
}

int main()
{
    better();                      // 🔸 Call the better function
    return 0;
}
