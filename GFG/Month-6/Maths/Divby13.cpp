#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ Approach: Basic Repeated Subtraction Method
    // ✅ T.C = O(N^2) approx (because string size shrinks but conversion and arithmetic happen repeatedly)
    // ✅ S.C = O(1)

    string s;
    cin >> s;

    // 🔸 If number is short (<=10 digits), convert directly
    if (s.size() <= 10)
    {
        long long num = stoll(s);                           // direct long long mein convert karke check
        if (num % 13 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
        return;
    }

    // 🔸 Apply the subtraction rule repeatedly:
    // remove last digit, multiply it by 4, subtract from remaining number
    while (s.length() > 2)
    {
        int last = s.back() - '0';                          // last digit ko le liya
        s.pop_back();                                       // usko remove kar diya

        long long num = stoll(s);                           // remaining number ko convert kiya
        num -= (last * 4);                                  // rule: subtract 4 × last digit
        s = to_string(num);                                 // fir us updated value ko wapas string bna diya
    }

    long long finalNum = stoll(s);                          // jab 2 digit tak aagaye toh last check
    if (finalNum % 13 == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}

void better()
{
    // ✅ Approach: Weighted Pattern Modulo 13
    // ✅ T.C = O(N), where N = length of string
    // ✅ S.C = O(1)

    string s;
    cin >> s;

    // 🔸 If number is short (<=10 digits), convert directly
    if (s.size() <= 10)
    {
        long long num = stoll(s);                          // chhoti string ko direct long long mein convert krke check
        if (num % 13 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
        return;
    }

    // 🔸 Use weight pattern from right → left
    vector<int> weights = {1, 10, 9, 12, 3, 4};             // 13 ke mod ka pattern repeat hota hai
    int w = 0;                                              // weight index
    long long sum = 0;

    for (int i = s.size() - 1; i >= 0; i--)                 // peeche se traverse karenge
    {
        int digit = s[i] - '0';                             // char ko digit mein convert
        sum += digit * weights[w];                          // weighted value add karo
        w = (w + 1) % 6;                                    // pattern cycle
    }

    if (sum % 13 == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    brute();     // 🔹 brute method call karni ho toh yeh use karo
    // better(); // 🔹 better method call karni ho toh yeh uncomment karo
    return 0;
}
