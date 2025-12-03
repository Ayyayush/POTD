#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C = O(N^2) in worst case (due to repeated erase shifting elements)
    // S.C = O(1) (no extra space used)

    int n;                         // number of elements
    cin >> n;

    vector<int> color(n), radius(n);
    for (int i = 0; i < n; i++) cin >> color[i];
    for (int i = 0; i < n; i++) cin >> radius[i];

    int i = 0;
    while (i < (int)color.size() - 1)
    {
        if (color[i] == color[i + 1] && radius[i] == radius[i + 1])
        {
            // Consecutive identical pair found, erase both
            color.erase(color.begin() + i);              // erase first of the pair
            color.erase(color.begin() + i);              // erase the second (now at same index)
            radius.erase(radius.begin() + i);
            radius.erase(radius.begin() + i);

            if (i > 0) i--;                               // step back to recheck new pair
        }
        else
        {
            i++;                                          // move forward
        }
    }

    cout << color.size() << endl;                         // final size after all erasures
}



void better()
{
    // Time Complexity: O(n)                       // Har element sirf ek baar stack mein daala/nikala jaa raha hai
    // Space Complexity: O(n)                      // Stack ke barabar auxiliary space lag raha hai

    int n; cin >> n;                              // Array size input
    vector<int> color(n), radius(n);              // Input arrays

    for(int i = 0; i < n; i++) cin >> color[i];   // color array input
    for(int i = 0; i < n; i++) cin >> radius[i];  // radius array input

    vector<pair<int, int>> st;                    // Pair stack simulate kar rahe hain

    for (int i = 0; i < n; ++i)
    {
        // Agar top pe same color & radius ho toh pair hata do
        if (!st.empty() && st.back().first == color[i] && st.back().second == radius[i])
        {
            st.pop_back();                        // Same pair mila toh dono hata do
        }
        else
        {
            st.push_back({color[i], radius[i]});  // Naya pair push karo
        }
    }

    cout << st.size() << endl;                    // Final length after all removals
}

int main()
{
    better();
    return 0;
}
