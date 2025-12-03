#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

void brute() // sorted type
{
    int n;
    cin >> n;
    vector<int> deadline(n);      
    vector<int> profit(n);         
    vector<pair<int, int>> result;

    for (int i = 0; i < n; i++)
    {
        cin >> deadline[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> profit[j];
        result.push_back(make_pair(deadline[j], profit[j])); // ✅ Fixed: deadline[j], profit[j] लिया
    }

    sort(result.begin(), result.end(), compare); // ✅ Fixed: Sorting सही से apply की

    int safedeadline = 1;
    int total_profit = result[0].second; // ✅ Fixed: Variable का नाम बदला क्योंकि profit पहले से ही vector है

    for (int i = 1; i < n; i++)
    {
        if (result[i].first > safedeadline) // ✅ Fixed: arr की जगह result इस्तेमाल किया
        {
            safedeadline = result[i].first;
            total_profit += result[i].second;
        }
    }

    cout << total_profit << endl; // ✅ Fixed: सही variable से print किया
}

int main()
{
    brute();
    return 0;
}
