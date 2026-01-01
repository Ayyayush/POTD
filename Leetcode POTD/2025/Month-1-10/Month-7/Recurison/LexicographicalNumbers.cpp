#include <bits/stdc++.h>           
using namespace std;                

#define endl '\n'                    // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long               // Har jagah 'int' ko 'long long' maana jaayega (bade values ke liye)
const int MOD = 1e9 + 7;             // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1;     // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)


// 📌 Recursive DFS jaise function jo lexicographical numbers generate karta hai
void solve(int curr, int n, vector<int>& result)
{
    if (curr > n) {
        return;                     // Agar current number n se bada ho gaya toh wapas aa jao
    }

    result.push_back(curr);        // Current number ko result mein daal do

    for (int append = 0; append <= 9; append++) {
        int newnum = (curr * 10) + append;      // Ek digit aur append karke new number banao

        if (newnum > n) return;    // Agar new number n se bada hai toh us branch ko chhodo

        solve(newnum, n, result);  // Warna uske aage jaake explore karo (DFS)
    }
}


void better()
{
    int n;
    cin >> n;

    // pehle 1 se leke n numbers socho 
    // ab dekho 1 lo ..range mein h rakh lo 
    // a mein numbers append karna shuru karo
    // jaise 1+0 , 1+0+0...
    // 1+1..1+1+1...1+1+2
    // append krne ke baad dekhenge ki range mein h ya nhi 
    // digit jyada ho gye n ke digit se toh false udhar mat jao 
    // ek number lo aur jitne depth mein ja skte ho jao 
    // ek solve function likho 
    // chote number se start karo unke tree mein neeche jaate jaate bade number bhi cover honge
    // solve(currnum,int n ,vector<int>&result)
    // agar currnum > n           ...wapas return kar jayenge
    // for append ( 0 se 9 tak loop chala skte h )
    // ek numbe append akrke explore karne jayenge 
    // int newnum= (currnum*10)+append;
    // if new num > n ....return
    // if newnum<n    .... go futher deepdown
    // isko recursion aur dfs ka mixture keh skte h
    // limit mein utne digit tak hi jana h jitne n ke digits ho
    // depth == digit of n 

    vector<int> result;

    for (int startnum = 1; startnum <= 9; startnum++) {
        solve(startnum, n, result);     // Har digit se start karke DFS jaisa tree explore kar rahe hain
    }

    // Output result print karna (lexicographical order mein)
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}


signed main()
{
    ios::sync_with_stdio(false);     // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);                   // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye

    better();                        // better() function call kar rahe hain (currently logic explanation + implementation)

    return 0;                        // Program safalta se terminate ho raha hai
}
