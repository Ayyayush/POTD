#include <bits/stdc++.h>
using namespace std;

// Brute Force (Check each house with all heaters)
// T.C. = O(N * M)      // N = houses, M = heaters
// S.C. = O(1)
void brute() {
    vector<int> houses = {1, 2, 3};
    vector<int> heaters = {2};

    int radius = 0;

    for (int h : houses) {
        int nearest = INT_MAX;
        for (int ht : heaters) {
            nearest = min(nearest, abs(h - ht));   // nearest heater ka distance
        }
        radius = max(radius, nearest);             // max distance among all houses
    }

    cout << "Brute answer = " << radius << endl;
}



// Better (Sort heaters + for each house check nearest heater by linear scan)
// T.C. = O(N * M) in worst case but heaters sorted
// S.C. = O(1)
void better() {
    vector<int> houses = {1, 2, 3, 4};
    vector<int> heaters = {1, 4};

    sort(heaters.begin(), heaters.end());

    int radius = 0;
    for (int h : houses) {
        int nearest = INT_MAX;
        for (int ht : heaters) {
            nearest = min(nearest, abs(h - ht));   // check all heaters
        }
        radius = max(radius, nearest);
    }

    cout << "Better answer = " << radius << endl;
}



// Optimal (Binary Search for nearest heater)
// T.C. = O(N log M)    // N = houses, M = heaters
// S.C. = O(1)
void optimal() {
    vector<int> houses = {1, 5};
    vector<int> heaters = {2};

    sort(heaters.begin(), heaters.end());

    int radius = 0;
    for (int h : houses) {
        // lower_bound -> first heater >= h
        auto it = lower_bound(heaters.begin(), heaters.end(), h);

        int dist1 = INT_MAX, dist2 = INT_MAX;
        if (it != heaters.end()) dist1 = abs(*it - h);       // right heater
        if (it != heaters.begin()) dist2 = abs(*(it - 1) - h); // left heater

        int nearest = min(dist1, dist2);
        radius = max(radius, nearest);   // sabse door house ka distance
    }

    cout << "Optimal answer = " << radius << endl;
}


int main() {
    brute();
    better();
    optimal();
    return 0;
}
