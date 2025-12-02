#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int sum, count = 0;
    cin >> sum;
    sort(coins.begin(), coins.end());

    for (int i = coins.size() - 1; i >= 0; i--)
    {
        if (coins[i] <= sum)
        {
            count++;
            sum -= coins[i];
            i++;
        }
        if (sum == 0)
        {
            cout << count << endl;
            break;
        }
    }
}

void better()   // using greedy
{

}
int main()
{
    brute();
    return 0;
}