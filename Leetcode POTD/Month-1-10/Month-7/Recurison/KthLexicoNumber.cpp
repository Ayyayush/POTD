#include <bits/stdc++.h>
using namespace std;

#define endl '\n'                    // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long               // Har jagah 'int' ko 'long long' maana jaayega (bade values ke liye)
const int MOD = 1e9 + 7;             // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1;     // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)


void brute()
{
     // ab dekho hum jo tree diagram mein niche ja rhe the wha hume lexico wise chote mil rhe the
     // par 
}










// ✅ T.C. = O(log n * log n) approx (due to DFS traversal over lexicographical tree)
// ✅ S.C. = O(log n) stack height in worst case + O(1) extra variables (excluding result vector used for tracking)

void solve(int curr, int n, vector<int>& result, int &ans, int k, int &count)
{
    if (curr > n) return;                          // Agar current number n se bada ho gaya toh wapas aa jao

    result.push_back(curr);                        // current number ko result mein daal do
    count++;                                       // count increase karo

    if (count == k) {
        ans = curr;                                // ✅ yehi correct assignment hai
        return;
    }

    for (int a = 0; a <= 9; a++) {
        int newn = curr * 10 + a;

        if (newn > n) break;                       // ✅ return nahi, break (no point going forward)

        solve(newn, n, result, ans, k, count);     // recursively call

        if (count == k) return;                    // ✅ already found, to no need to go further
    }

    result.pop_back();                             // ✅ backtracking
}


void brute()
{
     // ye lexiconumbers ki tarah hio karenge pura store kar lenge
     // last mein vec[k-1] de denge
     // but isme MLE aayge coz 10^9 hai constraint
}

void better()
{
    // ye approach hai toh shi but constraint bhot high h  
    // isme tle aayega
    int n, k;
    cin >> n >> k;

    vector<int> result;
    int ans = -1;
    int count = 0;

    for (int start = 1; start <= 9; start++) {
        solve(start, n, result, ans, k, count);    // DFS jaise lexicographical explore kar rahe hain

        if (count == k) break;                     // Agar k-th number mil gaya to ruk jao
    }

    cout << ans << endl;                           // Final answer output
}



void optimal() {
    // Better version agar ho toh yahaan likh sakte hain
}


signed main()
{
    ios::sync_with_stdio(false);     // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);                   // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye

    optimal();                       // optimal() function call kar rahe hain

    return 0;                        // Program safalta se terminate ho raha hai
}
