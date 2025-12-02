#include <bits/stdc++.h>
using namespace std;

void tiles(string str, string subset, int index)
{

    if (index == str.size())
    {
        cout << subset << endl;
        return;
    }

    // including
    tiles(str, subset + str[index], index + 1);

    // excluding
    tiles(str, subset, index + 1);
}

int main()
{

    string str;
    getline(cin, str);

    tiles(str, "", 0);
    return 0;
}