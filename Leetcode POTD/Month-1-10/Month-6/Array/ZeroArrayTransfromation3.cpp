#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        for (int j = l; j <= r; j++)
        {
            if (nums[j] > 0)
                nums[j] -= 1;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            cout << "False" << endl;
            return;
        }
    }
    cout << "True" << endl;
}



void better()
{
    // aise range wale question krne ke 2 methods h 
    // segement tree method          .. ye complex h aur input bhi update krna ho toh use krte h 
    // difference array method

    // step 1 
    // difference array of size n+1 bnao
    /*
        query ke index ke 1st value pe nums mein +1 karo aur 2nd value pe -1 
        -1 tbhi krna h jab wo index nums mein last index na ho
    */

     int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

        int n = nums.size();                                    // Array ka size
    vector<int> diff(n, 0);                                 // Difference array of size n

    for(auto &query:queries)
    {
        int start=query[0];
        int end=query[1];

        int x=1;
        diff[start]+=x;
        if(end+1<n)
        {
            diff[end]-=x;
        }

    }

    for(int i=0;i<diff.size();i++)
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    brute();         // 🔁 isko call karo agar brute force test karna ho

    return 0;
}
