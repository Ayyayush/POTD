#include <bits/stdc++.h>
using namespace std;

void brute() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int n=arr.size();
    
    if (n == 1) {  // ✅ Edge case: Agar ek hi element ho
        cout << "0" << endl;
        return;
    }
    
    if (arr[0] == 0) {  // ✅ Edge case: Agar first element 0 ho
        cout << "-1" << endl;
        return;
    }
    
    long long jumpcount = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        jumpcount++;
        int maxjump = -1;
        int maxindex = i;  // ✅ Fix: maxindex should start from i

        // ✅ Fix: i+j should not go out of bounds
        for (int j = 1; j <= arr[i] && i + j < arr.size(); j++) {
            if (arr[i + j] > maxjump) {
                maxjump = arr[i + j];
                maxindex = i + j;
            }
        }

        i = maxindex - 1;  // ✅ Fix: Correctly updating i

        if (i >= arr.size() - 1) {  // ✅ Fix: Check if already reached last index
            cout << jumpcount << endl;
            return;
        }
        if (i + arr[i] >= arr.size() - 1) {  // ✅ Fix: One last jump needed
            cout << jumpcount + 1 << endl;
            return;
        }
    }
    
    cout << "-1" << endl;  // ✅ If not reachable
}



void better() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxi = 0;   // ✅ Maximum reach track karega
    int choice = 0; // ✅ Current range track karega
    int jumps = 0;  // ✅ Total jumps count karega

    for (int i = 0; i < n - 1; i++) {
        maxi = max(maxi, arr[i] + i);  // ✅ Maximum kahan tak pahunch sakte hain
        
        if (i == choice) {  // ✅ Jab current choice end ho jaye to jump le lo
            choice = maxi;
            jumps++;
        }
        if (choice >= n - 1) {  // ✅ Agar destination pahunch gaye to answer return karo
            cout << jumps << endl;
            return;
        }
    }

    cout << "-1" << endl;  // ✅ Agar end tak nahi pahunch sake
}

int main() {
    better();
    return 0;
}


int main() {
    brute();
    return 0;
}
