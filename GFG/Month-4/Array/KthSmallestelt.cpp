#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];               // Matrix ka input le rahe hain
            vec.push_back(matrix[i][j]);       // Har element ko vector mein daal rahe hain
        }
    }

    int kth;
    cin >> kth;

    sort(vec.begin(), vec.end());              // Saare elements ko sort kar diya
    cout << vec[kth - 1] << endl;              // kth smallest element print kar diya
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    brute();
    return 0;
}
