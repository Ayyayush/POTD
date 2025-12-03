#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;
    cin >> n;																// input le liya

    vector<int> res;														// ugly numbers ko store karne ke liye

    for (int i = 1; i <= pow(1690, 2); i++)									// 1690^2 tak iterate kar rahe
    {
        int num = i;

        while (num % 2 == 0) num /= 2;										// 2 se divide karte raho
        while (num % 3 == 0) num /= 3;										// 3 se divide karte raho
        while (num % 5 == 0) num /= 5;										// 5 se divide karte raho

        if (num == 1) res.push_back(i);										// agar num 1 ban gaya toh ugly number hai

        if (res.size() >= n) break;											// nth ugly tak hi jana hai
    }

    cout << res[n - 1] << endl;												// nth ugly number print kar diya
}

// 🔹 Time Complexity: O(N * logM)
// 🔹 Space Complexity: O(N)


void better()
{
    int n;
    cin >> n;																// input le liya

    vector<int> res;														// ugly numbers ko store karne ke liye
    res.push_back(1);														// 1 is ugly number

    int i2 = 0, i3 = 0, i5 = 0;												// pointers for 2, 3, 5
    int next2 = 2, next3 = 3, next5 = 5;

    while (res.size() < n)
    {
        int next = min({next2, next3, next5});								// next smallest ugly number choose karo
        res.push_back(next);

        if (next == next2) next2 = res[++i2] * 2;							// pointer badhao aur next multiple set karo
        if (next == next3) next3 = res[++i3] * 3;
        if (next == next5) next5 = res[++i5] * 5;
    }

    cout << res[n - 1] << endl;												// nth ugly number print
}

// 🔹 Time Complexity: O(N)
// 🔹 Space Complexity: O(N)


void optimal()
{
    int n;
    cin >> n;																// input le liya

    unordered_set<long long> seen;											// duplicates avoid karne ke liye
    priority_queue<long long, vector<long long>, greater<long long>> pq;	// min-heap

    pq.push(1);																// 1 is the first ugly number
    seen.insert(1);

    long long curr = 1;

    for (int i = 1; i <= n; i++)											// nth ugly number tak
    {
        curr = pq.top();
        pq.pop();

        if (seen.insert(curr * 2).second) pq.push(curr * 2);				// 2 se multiply karke dal do agar new hai
        if (seen.insert(curr * 3).second) pq.push(curr * 3);				// 3 se multiply
        if (seen.insert(curr * 5).second) pq.push(curr * 5);				// 5 se multiply
    }

    cout << curr << endl;													// nth ugly number
}

// 🔹 Time Complexity: O(N log N)
// 🔹 Space Complexity: O(N)


int main()
{
    // brute();
    // better();
    optimal();	// call the version you want to run
    return 0;
}
