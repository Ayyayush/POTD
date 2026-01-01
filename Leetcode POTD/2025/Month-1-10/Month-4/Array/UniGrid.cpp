#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;
    cin >> n; // Number of pairs input le rahe hain

    vector<vector<int>> grid(n, vector<int>(2)); // 2D vector banaya n rows aur 2 columns ka

    // Input lena har row ke liye
    for (int i = 0; i < grid.size(); i++)
    {
        cin >> grid[i][0] >> grid[i][1]; // Har row ke dono elements input le rahe hain
    }

    int x;
    cin >> x; // Increment/Decrement value input le rahe hain

    // O(1)
    if (x == 0) // Agar x zero hai toh koi operation possible nahi hai
    {
        cout << "-1" << endl;
        return;
    }

    // Maximum element find karna puri 2D array me se
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++) // O(N)
    {
        maximum = max(maximum, max(grid[i][0], grid[i][1])); // Max update kar rahe hain
    }

    int mid = (maximum + 1) / 2; // Mid-point nikal rahe hain (odd number ke case me round up)
    int count = 0;               // Step count track karne ke liye

    // 2D vector ko modify karne ka loop
    // O(N^2)
    for (int i = 0; i < grid.size(); i++) // O(N)
    {
        for (int j = 0; j < 2; j++) // O(N)
        {
            int curr = grid[i][j]; // Current element store kar rahe hain
            int old = curr;        // Original value store ki taaki check kar sakein

            // Mid value tak pohonchne ka process
            while (curr != mid)
            {
                if (curr < mid)
                {
                    curr = curr + x; // Agar chhota hai toh x add kar rahe hain
                }
                else
                {
                    curr -= x; // Agar bada hai toh x minus kar rahe hain
                }
                count++;

                // Agar opposite direction mein chala gaya toh -1 print karke exit karenge
                if ((old < mid && curr > mid) || (old > mid && curr < mid))
                {
                    cout << "-1" << endl;
                    return;
                }

                if (curr == mid)
                {
                    grid[i][j] = mid; // Agar mid ban gaya toh update karke break
                    break;
                }
            }
        }
    }

    // Final check: Agar koi bhi value mid ke equal nahi hai toh -1 print karna
    for (int i = 0; i < grid.size(); i++) // O(N^2)
    {
        for (int j = 0; j < 2; j++)
        {
            if (grid[i][j] != mid)
            {
                cout << "-1" << endl;
                return;
            }
        }
    }

    cout << count << endl; // Final steps ka count print karna
}

/*
    Time Complexity: O(N^2)
    - Maximum element find karna: O(N)
    - 2D matrix traverse karna aur values modify karna: O(N^2)
    - Final check karna: O(N^2)

    Space Complexity: O(1)
    - Sirf constant space use ho raha hai (mid, count, maximum).
*/

void better()
{
    int n, m, x;
    cin >> n >> m >> x; // Grid size and x input lena

    vector<int> elements; // 1D array to store all grid elements

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            elements.push_back(num); // 2D grid ko 1D array me store karna
        }
    }

    sort(elements.begin(), elements.end()); // Sorting for median calculation
    int median = elements[(n * m) / 2];    // Median ka calculation

    int count = 0; // Step count ke liye

    for (int num : elements)
    {
        int diff = abs(num - median); // Median se difference nikalna

        if (diff % x != 0) // Agar x ke multiple me nahi hai toh impossible hai
        {
            cout << -1 << endl;
            return;
        }

        count += diff / x; // Steps required to convert num into median
    }

    cout << count << endl; // Minimum operations print karna
}

/*
    Time Complexity: O(N*M log(N*M))
    - 2D grid ko 1D me convert karna: O(N*M)
    - Sorting: O(N*M log(N*M))
    - Traverse karna aur steps calculate karna: O(N*M)

    Space Complexity: O(N*M)
    - Ek extra vector use ho raha hai jo grid ke elements store kar raha hai.
*/

int main()
{
    brute();
    return 0;
}