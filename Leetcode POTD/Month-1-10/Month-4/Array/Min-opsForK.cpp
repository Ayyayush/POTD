#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n)                    // Ek hi baar poori array traverse ho rahi hai
    // Space Complexity: O(n)                   // map mein worst case mein n elements store ho sakte hain

    vector<int> nums = {2, 5, 1, 6, 3, 7};       // Example input
    int k = 3;                                   // Given value of k

    map<int, int> mp;                            // Map to store frequency of elements not equal to k

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != k)                        // Sirf unhi elements ko count karo jo k ke equal nahi hain
            mp[nums[i]]++;
    }

    if (mp.size() == 1 && mp.begin()->first > k) {
        cout << 1 << endl;                       // Sirf ek hi unique element hai jo k se bada hai
        return;
    }
    else if (mp.size() == 1) {
        cout << -1 << endl;                      // Sirf ek unique element hai lekin wo k se bada nahi hai
        return;
    }
    else {
        cout << mp.size() << endl;               // Total unique elements ≠ k ko count karke print kar do
        return;
    }
}

void better()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    unordered_set<int>st;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int k;
    cin>>k;

    for(int i=0;i<n;i++)
    {
       if(nums[i]<k)
       {
        cout<<"-1"<<endl;
        return;
       }
       else if(nums[i]>k)
       {
        st.insert(nums[i]);
       }
    }
    cout<<st.size()<<endl;

}

int main()
{
    better();
    return 0;
}
