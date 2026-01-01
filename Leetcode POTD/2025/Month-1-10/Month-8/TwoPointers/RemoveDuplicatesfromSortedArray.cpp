#include <bits/stdc++.h>
using namespace std;

void brute() {
    // Approach: Create a new array and copy only unique elements
    // T.C. = O(n), S.C. = O(n)

    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};     // input array
    if (nums.size() <= 1) {
        cout << nums.size() << endl;
        return;
    }

    vector<int> arr;
    arr.push_back(nums[0]);                      // push first element

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) continue;    // skip duplicates
        arr.push_back(nums[i]);                  // push unique
    }

    nums = arr;                                  // replace original array
    cout << nums.size() << endl;                 // print result
}

void better() {
    // Approach: Erase duplicates in-place while traversing
    // T.C. = O(n^2) (due to erase), S.C. = O(1)

    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};     // input array
    if (nums.size() <= 1) {
        cout << nums.size() << endl;
        return;
    }

    int i = 1;
    while (i < nums.size()) {
        if (nums[i] == nums[i - 1]) {
            nums.erase(nums.begin() + i);        // erase duplicate
        } else {
            i++;                                  // move forward
        }
    }

    cout << nums.size() << endl;                 // print result
}




void optimal()
{
    // Approach: Two Pointer
    // -----------------------------------
    // T.C : O(n)
    // S.C : O(1)
    // -----------------------------------

    int n;
    cin >> n;                                // Input size of array
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];                      // Input array elements
    }

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    int i = 0, j = 1;

    while (j < n) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];             // Place next unique element
        }
        j++;
    }

    int newLength = i + 1;
    cout << newLength << endl;               // Output the length of unique array

    for (int k = 0; k < newLength; k++) {
        cout << nums[k] << " ";              // Output the updated array
    }

    cout << endl;
}

int main()
{
    optimal();
    return 0;
}
