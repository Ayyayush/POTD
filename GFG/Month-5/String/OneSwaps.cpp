#include <bits/stdc++.h>
using namespace std;



void brute()
{
    // T.C. = O(n^2 * log n)         // Har unique swap ke liye ek n-length string insert ho rahi hai set me
    // S.C. = O(n^2)                 // Set me worst case me har swap se n-length string store ho sakti hai

    string s;
    cin >> s;

    set<string> st;

    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] != s[j])                                      // agar same characters hai to swap ka koi faida nahi
            {
                string temp = s;
                swap(temp[i], temp[j]);                             // ek baar swap karo
                st.insert(temp);                                    // set me daal do (unique handle ho jayega)
            }
        }
    }

    cout << st.size() << endl;                                      // kitne unique strings ban sakte hain
}



void brute()
{
    // T.C. = O(n^2 )         // Har unique swap ke liye ek n-length string insert ho rahi hai set me
    // S.C. = O(n^2)                 // Set me worst case me har swap se n-length string store ho sakti hai

    string s;
    cin >> s;

    unordered_set<string> st;

    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] != s[j])                                      // agar same characters hai to swap ka koi faida nahi
            {
                string temp = s;
                swap(temp[i], temp[j]);                             // ek baar swap karo
                st.insert(temp);                                    // set me daal do (unique handle ho jayega)
            }
        }
    }

    cout << st.size() << endl;                                      // kitne unique strings ban sakte hain
}


#include <bits/stdc++.h>
using namespace std;

void optimal()
{
    // T.C. = O(n)                 // Har character pe sirf ek baar loop chal raha hai
    // S.C. = O(1)                 // 26 size ki vector use ho rahi hai (constant space)

    string s;
    cin >> s;

    vector<int> m(26, 0);                             // 26 lowercase characters ke liye frequency tracker
    int ans = 0;                                      // Final answer yeh store karega

    for (int i = 0; i < s.size(); ++i)
    {
        // 'i' tak ke characters mein, kitne unique swaps possible hai with s[i]
        // i total characters hai piche, m[s[i]-'a'] usi character ke repeat count hai
        ans += i - m[s[i] - 'a'];                     // i - freq => unique swaps jo ab tak ke characters ke sath ho sakte hain

        ++m[s[i] - 'a'];                              // ab current character ka frequency badha do
    }

    // Agar koi bhi character repeat ho raha hai (i.e. freq > 1)
    // toh original string bhi ek valid possibility hogi (swap same characters)
    for (int x : m)
    {
        if (x > 1)
        {
            ++ans;                                    // original string ko bhi count kar lo
            break;                                    // ek baar mil gaya toh aur check karne ki zarurat nahi
        }
    }

    cout << ans << endl;                              // Final distinct strings count after exactly one swap
}

int main()
{
    optimal();
    return 0;
}



int main()
{
    brute();
    return 0;
}
