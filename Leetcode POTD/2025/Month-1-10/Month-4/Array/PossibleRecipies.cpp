#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<string> recipes(a);
    vector<vector<string>> ingredients(b, vector<string>(c));
    vector<string> supplies(d);
    cin.ignore();
    for(int i=0;i<a;i++)
    {
        getline(cin,recipies[i]);
    }

    for(int i=0;i<b;i++)
    {
        for(int j=0;j<c;j++)
        {
        getline(cin,ingredients[i][j]);
        }
    }

    for(int i=0;i<a;i++)
    {
        getline(cin,supplies[i]);
    }

    for(int i=0;i<supplies.size();i++)
    {
        if(supplies)
    }
}
int main()
{
}