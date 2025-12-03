#include <bits/stdc++.h>
using namespace std;
void brute()
{
    string s1,s2;
    cin>>s1>>s2; 
    long long prod=stoll(s1)*stoll(s2);
    cout<<prod<<endl;

}



string multiplyStrings(string s1, string s2) 
{
    // Step 1: Handle negative numbers
    bool neg = false;
    if (s1[0] == '-') {
        neg = !neg;              // Agar pehla number negative hai toh neg ko flip karo
        s1 = s1.substr(1);       // '-' hatado
    }
    if (s2[0] == '-') {
        neg = !neg;              // Agar dusra number negative hai toh neg ko flip karo
        s2 = s2.substr(1);       // '-' hatado
    }

    // Step 2: Remove leading zeros
    while (s1.length() > 1 && s1[0] == '0') s1.erase(0, 1);
    while (s2.length() > 1 && s2[0] == '0') s2.erase(0, 1);

    // Special Case: Agar koi number 0 hai
    if (s1 == "0" || s2 == "0") return "0";

    int n = s1.size();
    int m = s2.size();
    vector<int> result(n + m, 0);     // Maximum size n+m ho sakti hai multiplication ke baad

    // Step 3: Multiply karna start karo digit by digit
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');    // Characters ko integer mein convert karke multiply karo
            int sum = mul + result[i + j + 1];          // Pehle se jo result tha usme add karo

            result[i + j + 1] = sum % 10;               // Current position mein unit digit daal do
            result[i + j] += sum / 10;                  // Carry ko previous position mein add kar do
        }
    }

    // Step 4: Result ko string mein convert karo
    string ans = "";
    int i = 0;

    // Leading 0s ko ignore karo
    while (i < result.size() && result[i] == 0) i++;

    while (i < result.size()) ans.push_back(result[i++] + '0');

    // Step 5: Agar answer negative hona chahiye toh '-' add karo
    if (neg) ans = '-' + ans;

    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << multiplyStrings(s1, s2) << endl;
    return 0;
}
