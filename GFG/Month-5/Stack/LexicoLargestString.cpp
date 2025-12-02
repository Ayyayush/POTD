#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(N)                    // Har char ko dekhke stack maintain karte hain
    // S.C. = O(N)                    // Stack banate hain

    string s; cin >> s;               // String input lelo
    int k; cin >> k;                  // Kitne chars hataane hain

    stack<char> st;                   // Stack banao

    for (int i = 0; i < s.size(); i++) {      
        while (!st.empty() && st.top() < s[i] && k > 0) {   
            st.pop();                 // Top chota ho toh hatao
            k--;                      // Ek pop kiya toh k--
        }
        st.push(s[i]);                // Current char daalo
    }

    while (k--) {                     // Agar abhi bhi k bacha hai toh aur pop karo
        st.pop();
    }

    string res = "";
    while (!st.empty()) {
        res += st.top();              // Stack se nikaalte jao
        st.pop();
    }

    reverse(res.begin(), res.end());  // Reverse karke answer banao

    cout << res << endl;              // Output print karo
}

void better()
{
    // T.C. = O(N)                    // Har char ko dekhke string mein stack jaisa kaam karte hain
    // S.C. = O(N)                    // String res bana ke kaam chala lete hain

    string s; cin >> s;               // String input lo
    int k; cin >> k;                  // k input lo

    string res = "";                  // Ye hi final answer banega

    for (char c : s) {
        while (!res.empty() && k > 0 && res.back() < c) {
            res.pop_back();           // Peeche se chota char hataao
            k--;
        }
        res.push_back(c);             // Current char daal do
    }

    while (k-- > 0) res.pop_back();   // Agar abhi bhi bacha ho toh end se hataao

    cout << res << endl;              // Output print karo
}

int main()
{
    brute();                          // Pehle brute ko run karo
    better();                         // Phir better ko run karo
    return 0;
}
