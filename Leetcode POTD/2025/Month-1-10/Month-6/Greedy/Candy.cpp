#include <bits/stdc++.h>           
using namespace std;                

#define endl '\n'                    // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long               // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;             // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1;     // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)


void brute()
{
    // ye iss case pe galat ho jata arr={1,2,10m,10,10,2,1}
    vector<int> ratings = {1, 0, 2};  // Sample input, aap apne input se replace kar sakte ho
    int count = ratings.size();       // Initial candies = number of kids

    for (int i = 0; i < (int)ratings.size(); i++)
    {
        // Agar next rating current se different hai (badi ya chhoti), toh candies ek aur badhao
        if (i + 1 < (int)ratings.size() && (ratings[i + 1] > ratings[i] || ratings[i + 1] < ratings[i]))
        {
            count += 1;
        }
    }

    cout << count << endl;  // Final candies count print karo
}



void good()
{
    vector<int> ratings = {1, 0, 2};  // Sample input, aap apne input se replace kar sakte ho
    int n = ratings.size();
    vector<int> L2R(n, 1), R2L(n, 1);  // Left to Right aur Right to Left candy counts initialize 1 se

    // Left to Right pass: agar current rating previous se badi hai toh candy badhao
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            L2R[i] = max(L2R[i], L2R[i - 1] + 1);
    }

    // Right to Left pass: agar current rating next se badi hai toh candy badhao
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            R2L[i] = max(R2L[i], R2L[i + 1] + 1);
    }

    long long sum = 0;
    // Maximum candies dono passes se leke sum karo
    for (int i = 0; i < n; i++)
    {
        int candies = max(L2R[i], R2L[i]);
        sum += candies;
    }

    cout << sum << endl;  // Final answer print karo
}


void better()
{
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++) cin >> ratings[i];

    vector<int> count(n, 1);     // Sabko 1 candy minimum milti hai initially

    // Left to Right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            count[i] = count[i - 1] + 1;    // agar current rating zyada hai, toh ek candy zyada
    }

    // Right to Left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1])
            count[i] = max(count[i], count[i + 1] + 1);    // left ka already diya hua ya right ka +1
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += count[i];     // total candies add kar rahe hain
    }

    cout << (int)sum << endl;
}


void optimal()
{
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];       // input ratings of all students
    }

    int candy = n;               // har student ko ek candy initially

    int i = 1;
    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            i++;                 // agar rating same hai to aage badho
            continue;
        }

        int peak = 0;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;              // increasing pattern => peak
            candy += peak;
            i++;
        }

        int dip = 0;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            dip++;               // decreasing pattern => dip
            candy += dip;
            i++;
        }

        candy -= min(peak, dip); // peak aur dip ke beech common child ke candies double count hue honge
    }

    cout << candy << endl;       // final answer print karo
}



signed main()
{
    ios::sync_with_stdio(false);     // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);                   // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0;                        // Program successful terminate ho raha hai
}
