#include <bits/stdc++.h>
using namespace std;

// Merge function to merge two sorted halves
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp; // Temporary array to store merged elements

    int left = low;     // Start of left half
    int right = mid+1;  // Start of right half

    // Jab tak dono halves me elements hain
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Agar left half me elements bache hain
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Agar right half me elements bache hain
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back merged elements to original array
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Merge sort function (Recursive)
void mergeSort(vector<int>& arr, int low, int high) {
    if(low >= high) return; // Base case

    int mid = low + (high - low) / 2;

    // Left half ko sort karo
    mergeSort(arr, low, mid);

    // Right half ko sort karo
    mergeSort(arr, mid+1, high);

    // Merge the sorted halves
    merge(arr, low, mid, high);
}

void solve() {
    vector<int> arr = {6, 3, 9, 5, 2, 8};

    cout << "Original Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: "; 
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    solve();
    return 0;
}
