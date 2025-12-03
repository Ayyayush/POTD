#include <bits/stdc++.h>
using namespace std;


void brute()        //sorted type
{
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};
    
     cout<<"A0"<<endl;   // printing A0 as it is always selected
    int count=1;
    int currend=end[0];

    for(int i=1;i<=end.size();i++)
    {
        if(start[i]>=currend)
        {
            count++;
            cout<<"A"<<i<<endl;
            currend=end[i];
        }
    }

    cout<<count<<endl;
}

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

void better()
{
    int n;
    cin >> n;
    vector<int> start(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    vector<int> finish(n);
    for (int i = 0; i < n; i++)
    {
        cin >> finish[i];
    }
    vector<pair<int, int>> act; // Pair को vector में रखना होगा

    for (int i = 0; i < n; i++)
    {
        act.push_back(make_pair(start[i], finish[i])); // सही variable नाम
    }

    // not needed if already sorted 
    sort(act.begin(), act.end(), compare); // `compare()` नहीं, सिर्फ `compare` पास करना है

    int count = 1;
    int currend = act[0].second;
    for (int i = 1; i < n; i++)
    {
        int currstart = act[i].first;
        if (currstart > currend)
        {
            count++;
            currend = act[i].second;
        }
       
    }
    cout << count << endl;
}


void optimal()
{
    int n;
    cin >> n;
    vector<int> start(n), finish(n);
    
    for (int i = 0; i < n; i++) cin >> start[i];
    for (int i = 0; i < n; i++) cin >> finish[i];

    vector<pair<int, int>> act;
    for (int i = 0; i < n; i++) act.emplace_back(finish[i], start[i]);

    sort(act.begin(), act.end()); // Finish time के अनुसार sorting

    int count = 0, finishtime = -1;
    for (auto &activity : act) 
        if (activity.second > finishtime) 
            finishtime = activity.first, count++;

    cout << count << endl;
}

int main()
{
    optimal();
    return 0;
}