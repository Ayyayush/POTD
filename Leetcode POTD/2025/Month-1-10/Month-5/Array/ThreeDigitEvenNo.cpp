#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^3)         // 3 nested loops for checking all permutations
    // Space Complexity: O(1) ~ O(k)   // constant space excluding output, set may store few hundred numbers

    int n;
    cin >> n;
    vector<int> digits(n);

    for (int i = 0; i < n; i++)
    {
        cin >> digits[i]; // input digits
    }

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                // indices same nahi hone chahiye
                if (i == j || j == k || i == k)
                    continue;

                int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                // number 3-digit hona chahiye, aur even hona chahiye
                if (num >= 100 && num % 2 == 0)
                {
                    st.insert(num);
                }
            }
        }
    }

    vector<int> result(st.begin(), st.end());
    sort(result.begin(), result.end());

    // print all valid even numbers
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    brute();
    return 0;
}
