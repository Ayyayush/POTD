#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // group by key: mp[key] -> list of values
        unordered_map<int, vector<int>> mp;
        for (size_t i = 0; i < buildings.size(); ++i) {
            mp[buildings[i][0]].push_back(buildings[i][1]);  // push_back value into vector for key
        }

        int count = 0;

        // For every building entry, check the two conditions you specified
        for (size_t i = 0; i < buildings.size(); ++i) {
            int x = buildings[i][0];                          // current key to check

            // Condition 1: current x has more than 3 values in its vector
            bool cond1 = (mp[x].size() > 3);

            if (cond1) {
                int flag = 0;                                // reset counter for each i

                // iterate through all (key, vector) pairs in the map
                for (auto &p : mp) {
                    // p.first = key, p.second = vector<int>
                    // check whether x appears inside this vector
                    if (find(p.second.begin(), p.second.end(), x) != p.second.end()) {
                        ++flag;                              // found x in this key's vector
                    }
                }

                // Condition 2 (as you described): at least 3 keys contain x in their vectors
                if (flag >= 3) {
                    ++count;
                }
            }
        }

        return count;
    }
};




class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, vector<int>> rows;  // row → all cols in that row
        unordered_map<int, vector<int>> cols;  // col → all rows in that col

        // Build row and column lists
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }

        // Sort each row & column list
        for (auto &p : rows) sort(p.second.begin(), p.second.end());
        for (auto &p : cols) sort(p.second.begin(), p.second.end());

        int count = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // row → list of y values
            auto &rowList = rows[x];

            // col → list of x values
            auto &colList = cols[y];

            // Check left & right buildings
            bool hasLeft = false, hasRight = false;
            auto it1 = lower_bound(rowList.begin(), rowList.end(), y);

            if (it1 != rowList.begin()) hasLeft = true;
            if (next(it1) != rowList.end()) hasRight = true;

            // Check above & below buildings
            bool hasAbove = false, hasBelow = false;
            auto it2 = lower_bound(colList.begin(), colList.end(), x);

            if (it2 != colList.begin()) hasAbove = true;
            if (next(it2) != colList.end()) hasBelow = true;

            if (hasLeft && hasRight && hasAbove && hasBelow)
                count++;
        }

        return count;
    }
};
