#include <bits/stdc++.h>
using namespace std;

void brute() // T.C = O(N^2), S.C = O(2N)
{
    // 3 alag array mein rakho.....ek mein less ek mein equal ek mein larger....
    // firr last mein sabko merge kar do
    // Nested loop use hone ki wajah se time complexity O(N^2) ho jaayegi
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int pivot;
    cin >> pivot;

    vector<int> lessPivot, equalPivot, greaterPivot;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < pivot)
            lessPivot.push_back(nums[i]); // Pivot se chhoti values
        else if (nums[i] == pivot)
            equalPivot.push_back(nums[i]); // Pivot ke barabar values
        else
            greaterPivot.push_back(nums[i]); // Pivot se badi values
    }

    vector<int> result;
    result.insert(result.end(), lessPivot.begin(), lessPivot.end());
    result.insert(result.end(), equalPivot.begin(), equalPivot.end());
    result.insert(result.end(), greaterPivot.begin(), greaterPivot.end());

    for (auto x : result)
        cout << x << " "; // Final sorted array print kar rahe hain
    cout << endl;
}

void better() // T.C = O(N), S.C = O(N)
{
    int n;
    cin >> n; // Array ka size input le rahe hain
    vector<int> nums(n);
    vector<int> result1; // Chhoti values store karne ke liye
    deque<int> result2;  // Equal aur greater values ke liye deque use kar rahe hain

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array elements input le rahe hain
    }

    int pivot;
    cin >> pivot; // Pivot input le rahe hain

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > pivot)
            result2.push_back(nums[i]); // Pivot se bada hai toh end mein daalenge
        else if (nums[i] == pivot)
            result2.push_front(nums[i]); // Pivot ke equal hai toh front mein daalenge
        else
            result1.push_back(nums[i]); // Pivot se chhota hai toh alag vector mein store karenge
    }

    vector<int> arr = result1; // Pehle chhoti values daal diye
    for (int i = 0; i < result2.size(); i++)
        arr.push_back(result2[i]); // Fir equal aur greater values ko daal diye

    for (auto x : arr)
        cout << x << " "; // Final sorted order print kar rahe hain
    cout << endl;
}

void better() // T.C = O(N), S.C = O(N)
{
    int n;
    cin >> n; // Array ka size input le rahe hain
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int pivot;
    cin >> pivot;

    int countless = 0, countequal = 0;
    for (int &num : nums)
    {
        if (num < pivot)
            countless++; // Count kar rahe hain ki kitne numbers pivot se chhote hain
        else if (num == pivot)
            countequal++; // Pivot ke barabar kitne hain
    }

    int i = 0, j = countless, k = countless + countequal;
    vector<int> result(n);

    for (int &num : nums)
    {
        if (num < pivot)
            result[i++] = num; // Chhoti values pehle daal rahe hain
        else if (num == pivot)
            result[j++] = num; // Pivot ke equal values beech mein daal rahe hain
        else
            result[k++] = num; // Badi values last mein daal rahe hain
    }

    for (auto x : result)
        cout << x << " "; // Final sorted array print kar rahe hain
    cout << endl;
}

void optimal() // T.C = O(N), S.C = O(N)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int pivot;
    cin >> pivot;

    vector<int> result(n);
    int i = 0, j = n - 1, i_ = 0, j_ = n - 1;

    while (i < n && j >= 0)
    {
        if (nums[i] < pivot)
            result[i_++] = nums[i]; // Chhoti values ko left se daal rahe hain
        if (nums[j] > pivot)
            result[j_--] = nums[j]; // Badi values ko right se daal rahe hain
        i++;
        j--;
    }

    while (i_ <= j_)
        result[i_++] = pivot; // Beech mein pivot ko daal rahe hain

    for (auto x : result)
        cout << x << " "; // Final sorted array print kar rahe hain
    cout << endl;
}

int main()
{
    brute();
    better();
    return 0;
}
