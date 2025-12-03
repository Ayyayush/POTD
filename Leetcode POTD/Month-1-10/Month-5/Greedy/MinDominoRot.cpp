// two 
// whenver a problem has a small limited set of values ...
//iska mtlb hint h ki hum brute force afford kr skte h unn values pe
// jo ki hint deta h greedy ka
//eg: dominoes,card,dice,directions,vowels,digit based


// aisa karo top aur bottom dono mein se union le lo ...aur unn union ki values pe swap karo
// jis union value pe sabswe kam swap lage wo hi answer h 


#include <bits/stdc++.h>
using namespace std;

void brute()
{
    vector<int> tops = {2,1,2,4,2,2};             // sample input
    vector<int> bottoms = {5,2,6,2,3,2};          // sample input
    int n = tops.size();

    int minRotations = INT_MAX;

    for(int val = 1; val <= 6; val++)             // 1 se 6 check karenge
    {
        int swapTop = 0;
        int swapBottom = 0;
        bool possible = true;

        for(int i = 0; i < n; i++)
        {
            if(tops[i] != val && bottoms[i] != val)
            {
                possible = false;
                break;
            }
            else if(tops[i] != val)  swapTop++;   // top mein nahi mila toh upar se neeche laaenge
            else if(bottoms[i] != val) swapBottom++;  // bottom mein nahi mila toh neeche se upar laaenge
        }

        if(possible)
        {
            minRotations = min(minRotations, min(swapTop, swapBottom));
        }
    }

    if(minRotations == INT_MAX) cout << -1 << endl;
    else cout << minRotations << endl;
}

void better()
{
    vector<int> tops = {2,1,2,4,2,2};             // sample input
    vector<int> bottoms = {5,2,6,2,3,2};          // sample input
    int n = tops.size();

    int val1 = tops[0];                           // first value from top
    int val2 = bottoms[0];                        // first value from bottom

    // try both candidates: val1 and val2
    for(int val : {val1, val2})
    {
        int swapTop = 0, swapBottom = 0;
        bool possible = true;

        for(int i = 0; i < n; i++)
        {
            if(tops[i] != val && bottoms[i] != val)
            {
                possible = false;
                break;
            }
            else if(tops[i] != val) swapTop++;
            else if(bottoms[i] != val) swapBottom++;
        }

        if(possible)
        {
            cout << min(swapTop, swapBottom) << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    brute();
    better();

    return 0;
}
