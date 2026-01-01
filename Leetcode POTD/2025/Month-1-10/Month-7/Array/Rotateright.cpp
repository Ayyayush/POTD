#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(k * n)                     // Har rotation me O(n) shift karte hain, total k times
    // S.C. = O(1)                         // In-place operation, koi extra space nahi

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    k = k % n; // valid rotation range me lao

    while (k--)
    {
        int last = nums[n - 1]; // last element ko store karo

        // right shift all elements by 1
        for (int i = n - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1]; // shift each element to right
        }

        nums[0] = last; // first position par last element daalo
    }

    // Output print karo
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}




void good()
{
    // T.C. = O(n)                         // Har element ko ek baar access kar rahe hai (2 loops)
    // S.C. = O(n)                         // Ek extra result vector + temporary array use ho raha hai

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    k = k % n; // k ko valid range me le aao (agar k > n ho)

    vector<int> result; // final rotated array
    vector<int> temp;   // temporary for reversing chunks

    // Step 1: Push last k elements in reverse order
    for (int i = n - k; i < n; i++)
    {
        temp.push_back(nums[i]);
    }

    result.insert(result.end(), temp.begin(), temp.end());
    temp.clear(); // temp ko reset karo

    // Step 2: Push first n-k elements in reverse order
    for (int i = 0; i < n - k; i++)
    {
        temp.push_back(nums[i]);
    }

    result.insert(result.end(), temp.begin(), temp.end());

    // Step 3: Copy result into original array
    nums = result;

    // Output print kar do
    for (int x : nums)
        cout << x << " ";
    cout << endl;
}




void better()
{
    // T.C. = O(n)                         // poora array ek baar hi traverse ho raha hai
    // S.C. = O(n)                         // ek extra array use ho raha hai rotation ke liye

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    k = k % n; // agar k > n ho toh usse valid range me lao

    vector<int> rotated(n); // final rotated array

    int idx = 0;

    // last k elements ko pehle daalo
    for (int i = n - k; i < n; i++)
    {
        rotated[idx++] = nums[i];
    }

    // fir baaki ke first n-k elements daalo
    for (int i = 0; i < n - k; i++)
    {
        rotated[idx++] = nums[i];
    }

    // result ko original nums me copy karo
    nums = rotated;

    // final output print
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}





void optimal()
{
    // T.C. = O(n)                             // 3 baar reversal kar rahe hain => linear time
    // S.C. = O(1)                             // In-place reversal, no extra space used

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    k = k % n; // k ko valid range me le aao agar k > n ho

    // Step 1: reverse first n-k elements
    reverse(nums.begin(), nums.begin() + (n - k));

    // Step 2: reverse last k elements
    reverse(nums.begin() + (n - k), nums.end());

    // Step 3: reverse the whole array
    reverse(nums.begin(), nums.end());

    // Output print karo
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    optimal();
    return 0;
}
