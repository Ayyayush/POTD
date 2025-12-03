#include <bits/stdc++.h>
using namespace std;
void brute()
{
    long long  n;
    cin>>n;
    vector<long long >candies(n);
    for(long long  i=0;i<n;i++)
    {
        cin>>candies[i];
    }
    long long  k;
    cin>>k;

    auto it=max_element(candies.begin(),candies.end());
    long long  maximum=*it;
    if(maximum<k)
    {
        cout<<"0"<<endl;
        return ;
    }
    else
    {
        auto it=min_element(candies.begin(),candies.end());
        long long  minimum=*it;
        if(maximum>=minimum)
        {
            cout<<minimum<<endl;
            return ;
        }
    }
}


// Brute Force Approach
// T.C : O(n * maxC), maxC = maximum candy value
// S.C : O(1)
void better() {
    vector<int> candies = {5, 8, 6}; // Input le sakte ho yahaan
    long long k = 3; // Total children
    int n = candies.size();

    int maxC = 0;
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        total += candies[i]; // Total candies ka sum nikal rahe hain
        maxC = max(maxC, candies[i]); // Max candy value find kar rahe hain
    }

    if (total < k) {
        cout << 0 << endl; // Agar total candies k se kam hain toh 0 return hoga
        return;
    }

    // Brute force approach: maxC se lekar 1 tak check karenge
    for (int c = maxC; c >= 1; c--) {
        long long count = 0;
        for (int i = 0; i < n; i++) {
            count += candies[i] / c; // Har pile se c candies kitne bachon ko mil sakti hain
        }
        if (count >= k) { // Agar required bachon ko candies mil gayi toh return
            cout << c << endl;
            return;
        }
    }

    cout << 0 << endl; // Agar koi valid distribution nahi mila toh 0 return
}






// Optimized Approach (Binary Search on Answer)
// T.C : O(n * log(maxC)), maxC = maximum candy value
// S.C : O(1)
bool canDistr(vector<int>& candies, int mid, long long k) {
    int n = candies.size();

    for (int i = 0; i < n; i++) {
        k -= candies[i] / mid; // Har bachay ko mid candies dene ki koshish kar rahe hain

        if (k <= 0) return true; // Agar sare bachon ko mil gayi toh return true
    }

    return false; // Agar sabko nahi mili toh return false
}

void optimal() {
    vector<int> candies = {5, 8, 6}; // Input le sakte ho yahaan
    long long k = 3; // Total children
    int n = candies.size();

    int maxC = 0;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += candies[i]; // Total candies ka sum nikal rahe hain
        maxC = max(maxC, candies[i]); // Max candy value find kar rahe hain
    }

    if (total < k) {
        cout << 0 << endl; // Agar total candies kam hain toh return 0
        return;
    }

    int l = 1, r = maxC, result = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2; // Mid value calculate kar rahe hain

        if (canDistr(candies, mid, k)) { // Check kar rahe hain ki ye mid value feasible hai ya nahi
            result = mid;
            l = mid + 1; // Agar possible hai toh aur bada answer dhoondho
        } else {
            r = mid - 1; // Agar nahi possible hai toh chhota answer dhoondho
        }
    }

    cout << result << endl; // Maximum possible candies jo distribute ki ja sakti hain
}

int main() {
    brute();
    optimal();
    return 0;
}
