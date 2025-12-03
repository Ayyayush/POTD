#include <bits/stdc++.h>
using namespace std;

void naive()
{
    // T.C. = O(n^3), S.C. = O(1)
    // Approach: Nested loops to check all subarrays of size >= 2

    vector<int> arr = {3, 1, 4, 1, 5}; // sample input
    int n = arr.size();
    int result = INT_MIN;

    for (int i = 0; i < n; i++)
    { // starting index of subarray
        for (int j = i + 1; j < n; j++)
        { // ending index of subarray (at least 2 elements)
            vector<int> temp;

            for (int k = i; k <= j; k++)
            { // collect elements of subarray arr[i...j]
                temp.push_back(arr[k]);
            }

            sort(temp.begin(), temp.end()); // sort the subarray to get smallest 2 elements
            int sum = temp[0] + temp[1];    // sum of 2 smallest
            result = max(result, sum);      // update max result
        }
    }

    cout << "Maximum sum of smallest two elements in any subarray of size ≥ 2: " << result << endl;
}




void brute() {
    // T.C. = O(n^2), S.C. = O(1)
    // Approach: For every subarray of size ≥ 2, find the two smallest elements using linear scan

    vector<int> arr = {3, 1, 4, 1, 5};             // sample input
    int n = arr.size();
    int result = INT_MIN;

    for (int i = 0; i < n; i++) {                  // start of subarray
        int firstMin = INT_MAX, secondMin = INT_MAX;

        for (int j = i; j < n; j++) {              // end of subarray
            if (arr[j] < firstMin) {
                secondMin = firstMin;
                firstMin = arr[j];
            } else if (arr[j] < secondMin) {
                secondMin = arr[j];
            }

            if (j - i + 1 >= 2) {                  // only if subarray size ≥ 2
                int sum = firstMin + secondMin;
                result = max(result, sum);
            }
        }
    }

    cout << "Maximum sum of smallest two elements in any subarray of size ≥ 2: " << result << endl;
}







void better() {
    // T.C. = O(n^2 * logn), S.C. = O(n)
    // Approach: Sliding window with multiset (auto-sorted container)

    vector<int> arr = {3, 1, 4, 1, 5};              // Sample input
    int n = arr.size();
    int result = INT_MIN;
    int i = 0, j = 0;
    multiset<int> ms;

    while (i < n) {
        ms.insert(arr[j]);

        if (j - i + 1 >= 2) {
            auto it = ms.begin();
            int first = *it;
            ++it;
            int second = *it;
            int sum = first + second;
            result = max(result, sum);
        }

        j++;

        if (j == n) {
            i++;
            j = i;
            ms.clear();
        }
    }

    cout << "Optimal (multiset) Result: " << result << endl;
}





void good() {
    // T.C. = O(n^2), S.C. = O(n)
    // Approach: Sliding window with deque (no auto-sorting)

    vector<int> arr = {3, 1, 4, 1, 5};              // Sample input
    int n = arr.size();
    int result = INT_MIN;
    int i = 0, j = 0;
    deque<int> dq;

    while (i < n) {
        dq.push_back(arr[j]);

        if (j - i + 1 >= 2) {
            deque<int> temp = dq;
            sort(temp.begin(), temp.end());
            int sum = temp[0] + temp[1];
            result = max(result, sum);
        }

        j++;

        if (j == n) {
            i++;
            j = i;
            dq.clear();
        }
    }

    cout << "Better (deque) Result: " << result << endl;

}





void better() {
    // T.C. = O(n^2 * logn), S.C. = O(n)
    // Approach: Sliding window with multiset (auto-sorted container)

    vector<int> arr = {3, 1, 4, 1, 5};              // Sample input
    int n = arr.size();
    int result = INT_MIN;
    int i = 0, j = 0;
    multiset<int> ms;

    while (i < n) {
        ms.insert(arr[j]);

        if (j - i + 1 >= 2) {
            auto it = ms.begin();
            int first = *it;
            ++it;
            int second = *it;
            int sum = first + second;
            result = max(result, sum);
        }

        j++;

        if (j == n) {
            i++;
            j = i;
            ms.clear();
        }
    }

    cout << "(multiset) Result: " << result << endl;
}




/**OPTIMAL APPROACH 
 * 2 element ho subarray mein troh sidhe dono le lo
 * aur maan lo next element aaya 
 * maan lo min h  x second min h y 
 * ab jo bhi next element aa rha h usko check krte rahenge 
 * maan lo extra elt z h jo ya toh pehle se h yaa rha h
 * yhi include nhi krna kyunki bada h 
 * 
 */



 // Approach 2: Check only adjacent pairs since the max (min + secondMin) always comes from size‑2 subarrays
// Time Complexity: O(n) – Single pass through the array
// Space Complexity: O(1) – Only constant extra variables used

class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n      = arr.size();
        int result = arr[0] + arr[1];  // initialize with first pair sum

        // scan through all adjacent pairs
        for (int i = 1; i < n - 1; i++) {
            result = max(result, arr[i] + arr[i + 1]);
        }

        return result;
    }
};

/*
 *
 * Dry Run
 * Input: arr = [4, 3, 5, 1]
 *
 * result = arr[0] + arr[1] = 4 + 3 = 7
 *
 * i = 1 → arr[1] + arr[2] = 3 + 5 = 8
 * → result = max(7, 8) = 8
 *
 * i = 2 → arr[2] + arr[3] = 5 + 1 = 6
 * → result = max(8, 6) = 8
 *
 * Final result = 8 ✅
 *
 */

