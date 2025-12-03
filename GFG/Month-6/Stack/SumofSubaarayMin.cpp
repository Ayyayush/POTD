/**
 * SUM OF SUBARRAY MINIMUMS 
 * * AMAZON
 * 
 * 
 * *BRUTE FORCE
 * Simple nested loops
 * 
 * *OPTIMAL APPROACH
 * Mnimum element jitne bhi subarray mein aa rha h utni baar hi wo contribute kareag
 * 
 * eg:: 5,8,7,9,1,4,3,0,2
 * maan lo 1 abhi min h 
 * ab dekhte h 1 kitne subarrays mein aayega 
 * pehle toh dekho min element hai kis index pe 
 * 1 h 4th index pe toh wo 4th se leke 6th index tak contribute karega
 * jab tak 0 nhi aa jata h
 * dekhte h 1 kitne subarrays mein aa rha h
 * pehla subarray jisme 1 left se aayega wo ..
 * 5,8,7,9,1
 * 8,7,9,1
 * 7,9,1
 * 9,1
 * 
 * 1,4,3
 * 1,4
 * 
 * 1
 * 
 * 5,8,7,9,1,4,3
 * 5,8,7,9,1,4
 * 8,7,9,1,4,3
 * 8,7,9,1,4
 * 7,9,1,4,3
 * 7,9,1,4
 * 9,1,4,3
 * 9,1,4
 * 
 * toh 1 total 15 baar contribute karega
 * toh dekho direct aise kar skte h 
 * left+1  *  right+1   (left and right unless less na ho ussi se)
 * 5*3==15 ans 
 * 
 * 
 * similary for 3
 * 3 lka left h 4   kyunki 1 toh chota h
 * 3 ka right  kuch nhi 
 * so ans == (1+1)*(0+1) == 2
 * 
 * so similary har element ke liye kyun na precompute kar le 
 * har element ke liye nsr aur nsl compute kar lete h
 * 
 * nsr aur nsl mein yha indices daalenge kyunki whi kaam h 
 * 
 * 
 * Given array: {5, 8, 6, 4, 3, 0, 2}
 * Indices:       0  1  2  3  4  5  6
 *
 * NSL (Nearest Smaller to Left - index):
 * For each element, store the index of the nearest smaller element on the left.
 * If no such element exists, store -1.
 *
 * NSL = [-1, 0, 0, 2, 1, 4, 4]
 *
 * NSR (Nearest Smaller to Right - index):
 * For each element, store the index of the nearest smaller element on the right.
 * If no such element exists, store array.size().
 *
 * NSR = [2, 4, 4, 7, 6, 7, 7]
 *
 * NOTE:
 * - NSL[i] and NSR[i] give the boundaries for possible range of expansion
 *   if using this structure in histogram area problems or similar.
 * 
 * 
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// 🔹 Nearest Smaller to Left (NSL)
// Returns a vector where each element = index of previous smaller element
vector<int> getNSL(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nsl(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        nsl[i] = st.empty() ? -1 : st.top();      // -1 if no smaller on left
        st.push(i);
    }

    return nsl;
}

// 🔹 Nearest Smaller to Right (NSR)
// Returns a vector where each element = index of next smaller element
vector<int> getNSR(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nsr(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        nsr[i] = st.empty() ? n : st.top();       // n if no smaller on right
        st.push(i);
    }

    return nsr;
}

// 🔹 Main logic
void optimal()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    vector<int> nsl = getNSL(arr);
    vector<int> nsr = getNSR(arr);

    long long sum = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        int left = i - nsl[i];
        int right = nsr[i] - i;

        long long contrib = (1LL * arr[i] * left * right) % mod;
        sum = (sum + contrib) % mod;
    }

    cout << sum << endl;
}

int main()
{
    optimal();
    return 0;
}
