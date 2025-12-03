#include <bits/stdc++.h>           
using namespace std;                

#define endl '\n'                    // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long               // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;             // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1;     // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void brute()
{
    int n;
    cin>>n;
    // nested loops
    // O(N*3)
}


// O(N*2)
void better()                                   // Better approach ka function
{
    vector<int> arr = {3, 4, 5, 6, 7};          // Example input (aap input le sakte ho as needed)

    unordered_set<int> sq;                      // Set to store squares of elements

    for (int i = 0; i < arr.size(); i++) {
        sq.insert(arr[i] * arr[i]);             // Har element ka square set mein daal rahe
    }

    bool found = false;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int a2 = arr[i] * arr[i];
            int b2 = arr[j] * arr[j];
            int c2 = a2 + b2;

            if (sq.count(c2)) {                 // Agar set mein c^2 mila toh triplet mil gaya
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) cout << "Yes, Pythagorean Triplet Found" << endl;
    else cout << "No Triplet Found" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);     // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);                   // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0;                        // Program successful terminate ho raha hai
}
