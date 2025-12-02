#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Time Complexity: O(N + 1000)                   // N trips aur fir max 1000 locations scan
    // Space Complexity: O(1001)                       // 1001 size ka passengers array

    vector<vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };
    int capacity = 4;

    vector<int> passengers(1001, 0);                  // 0 to 1000 tak array banao

    for (auto &trip : trips)
    {
        int num = trip[0];
        int from = trip[1];
        int to = trip[2];

        passengers[from] += num;                      // pickup location pe log chadh gaye
        passengers[to] -= num;                        // drop location pe log utar gaye
    }

    int curr = 0;
    bool possible = true;                             // initially assume karo ho jayega

    for (int i = 0; i <= 1000; i++)
    {
        curr += passengers[i];                        // har location ka prefix sum lo
        if (curr > capacity)                          // agar kabhi capacity exceed hui
        {
            possible = false;                         // possible false kar do
            break;
        }
    }

    if (possible)
        cout << "Car pooling possible within capacity!" << endl;
    else
        cout << "Capacity exceeded! Car pooling NOT possible!" << endl;
}

int main()
{
    better();
    return 0;
}
