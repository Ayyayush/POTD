#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n!)
// Space Complexity: O(n) (for recursion stack and extra space used)
void brute()
{
    int n;
    cin >> n;                          // Input lena hai n ka
    vector<int> result(2 * n - 1, -1); // Result vector initialize kar rahe hain -1 se
    vector<bool> used(n + 1, false);   // Used array track karega kon kon se number use ho chuke hain

    function<bool(int)> solve = [&](int i)
    {
        if (i >= result.size())
            return true; // Agar pura fill ho gaya to true return karenge
        if (result[i] != -1)
            return solve(i + 1); // Agar current index pe number hai to next index check karenge

        for (int num = n; num >= 1; num--)
        { // Reverse order me check kar rahe hain taki bada number pehle aaye
            if (used[num])
                continue; // Agar number already use ho chuka hai to skip karenge

            used[num] = true; // Current number ko use mark karenge
            result[i] = num;  // Us number ko result me rakh rahe hain

            if (num == 1)
            { // Agar num 1 hai to seedha agle index pe jayenge
                if (solve(i + 1))
                    return true;
            }
            else
            {
                int j = result[i] + i; // Position calculate kar rahe hain
                if (j < result.size() && result[j] == -1)
                {                    // Check kar rahe hain ki position valid hai ya nahi
                    result[j] = num; // Us position pe num assign karenge
                    if (solve(i + 1))
                        return true; // Recursively agla index solve karenge
                    result[j] = -1;  // Agar nahi bana to undo karenge
                }
            }

            used[num] = false; // Undo karenge agar solution nahi bana
            result[i] = -1;    // Backtrack kar rahe hain
        }
        return false;
    };

    solve(0); // Solve function ko call karenge

    for (int num : result)
        cout << num << " "; // Output print karenge
    cout << endl;
}

int main()
{
    brute();
    return 0;
}