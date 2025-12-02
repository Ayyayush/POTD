#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void brute()
{
    int n;
    cin >> n;
    vector<string> words(n);
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    char x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (words[i].find(x) != string::npos)
            vec.push_back(i);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0; // Program successful terminate ho raha hai
}
