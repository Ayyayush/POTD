#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C = O(N log N) + O(N)              // sort + find + erase
    // S.C = O(N)                           // extra nums + result

    // Hardcoded input
    int n = 7; // array size
    int k = 4; // k elements
    int x = 3; // target x

    vector<int> arr = {1,2, 3, 4, 5}; // hardcoded array

    vector<int> nums = arr; // copy banayi
    vector<int> result;     // result vector banaya

    auto it = lower_bound(nums.begin(), nums.end(), x); // iterator find

    int distance;
    bool notpresent=false;

    // Tumhara condition galat tha: agar x nahi mila toh hi insert karo
    if (it == nums.end() || *it != x)
    {
        nums.push_back(x);
        sort(nums.begin(), nums.end());
        it = find(nums.begin(), nums.end(), x);
        notpresent=true;
    }

    distance = it - nums.begin();   // distance ko har case mein calculate karo


    int i;
    if(notpresent)
     i = 1;
     else 
     i=0;
     int count = 0;

    while (distance + i < nums.size() && count < k)
    {
        result.push_back(nums[distance + i]); // right side add karo
        i++;
        count++;
    }

     i=1;
  
    count = 0; // pehle i=1 kyunki left side ke liye
    while (distance - i >= 0 && count < k)
    {
        result.push_back(nums[distance - i]);
        i++;
        count++;
    }

    sort(result.begin(), result.end());             // final sort

    if (result.size() > k) {
        result.erase(result.begin() + k, result.end()); // sirf k elements chahiye
    }

    for (auto num : result)
        cout << num << " "; // output
    cout << endl;
}

int main()
{
    brute();
    return 0;
}
