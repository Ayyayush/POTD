#include <bits/stdc++.h>
using namespace std;

void brute()
 {
    int i, s;
    cin >> s; // Number of buses
    vector<int> time(s);
    for (i = 0; i < s; i++) {
        cin >> time[i]; // Time taken by each bus for one trip
    }

    int totalTrips;
    cin >> totalTrips;

    long long currentTime = 1; // Start from the first unit of time

    while (true) {
        long long actualTrips = 0;

        // Calculate the total trips that can be completed at the current time
        for (i = 0; i < s; i++) {
            actualTrips += currentTime / time[i];
        }

        // Check if the total trips are sufficient
        if (actualTrips >= totalTrips) {
            cout << currentTime << endl; // Output the minimum time
            return;
        }

        currentTime++; // Increment time to check the next step
    }
  
}


void better()
{
    
}




int main()
{
    brute();
    return 0;
}











