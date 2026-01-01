#include <bits/stdc++.h>
using namespace std;

void brute()  // O(N)      for string 
{
    string s;
    int k;
    cin >> s >> k;

    stack<pair<char, int>> st;        // character + uska count

    for (char ch : s)
    {
        if (!st.empty() && st.top().first == ch)
        {
            st.top().second++;        // same char mila to count++
        }
        else
        {
            st.push({ch, 1});         // nahi mila to new pair
        }

        if (st.top().second == k)
        {
            st.pop();                 // k times ho gaya to hata do
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans.append(st.top().second, st.top().first);  // char ko count times add karo
        st.pop();
    }
    reverse(ans.begin(), ans.end());  // stack se reverse ho gaya hota hai

    cout << ans << endl;
}



void bruteArray()        // O(N)
{
    
}
int main()
{
    brute();
    return 0;
}
