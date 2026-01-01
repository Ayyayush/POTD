#include <bits/stdc++.h>
using namespace std;

// Approach - 1 (Closest L and R tracking)
// Time Complexity: O(n)     // Ek baar L aur R ki closest position nikal rahe hain
// Space Complexity: O(n)    // 2 vectors bana rahe hain rightClosestL aur leftClosestR
void brute()
{
    string dominoes = ".L.R...LR..L.."; // Example input
    int n = dominoes.length();

    vector<int> rightClosestL(n);
    vector<int> leftClosestR(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (dominoes[i] == 'L')
            rightClosestL[i] = i;
        else if (dominoes[i] == '.')
            rightClosestL[i] = i < n - 1 ? rightClosestL[i + 1] : -1;
        else
            rightClosestL[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (dominoes[i] == 'R')
            leftClosestR[i] = i;
        else if (dominoes[i] == '.')
            leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
        else
            leftClosestR[i] = -1;
    }

    string result(n, ' ');

    for (int i = 0; i < n; i++)
    {
        int distRightL = abs(i - rightClosestL[i]);
        int distLeftR = abs(i - leftClosestR[i]);

        if (rightClosestL[i] == leftClosestR[i])
            result[i] = '.';
        else if (rightClosestL[i] == -1)
            result[i] = 'R';
        else if (leftClosestR[i] == -1)
            result[i] = 'L';
        else if (distLeftR == distRightL)
            result[i] = '.';
        else
            result[i] = distRightL < distLeftR ? 'L' : 'R';
    }

    cout << result << endl;
}

// Approach - 2 (Force Simulation)
// Time Complexity: O(n)       // Ek baar left to right aur ek baar right to left traverse kar rahe hain
// Space Complexity: O(n)      // Force array bana rahe hain
void better()
{
    string dominoes = ".L.R...LR..L.."; // Example input
    int n = dominoes.length();

    vector<int> forces(n, 0);
    int force = 0;

    for (int i = 0; i < n; i++)
    {
        if (dominoes[i] == 'R')
            force = n;
        else if (dominoes[i] == 'L')
            force = 0;
        else
            force = max(force - 1, 0);

        forces[i] += force;
    }

    force = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dominoes[i] == 'L')
            force = n;
        else if (dominoes[i] == 'R')
            force = 0;
        else
            force = max(force - 1, 0);

        forces[i] -= force;
    }

    string result(n, '.');
    for (int i = 0; i < n; i++)
    {
        if (forces[i] > 0)
            result[i] = 'R';
        else if (forces[i] < 0)
            result[i] = 'L';
    }

    cout << result << endl;
}

// Approach - 3 (Two Pointer Technique)
// Time Complexity: O(n)        // Har element ko ek baar dekh rahe hain with two-pointer
// Space Complexity: O(n)       // Ek auxiliary string bana rahe hain result ke liye
void optimal()
{
    string dominoes = ".L.R...LR..L.."; // Example input
    string s = "L" + dominoes + "R";
    int n = s.length();
    string result = "";

    for (int i = 0, j = 1; j < n; j++)
    {
        if (s[j] == '.')
            continue;

        int midLen = j - i - 1;

        if (i > 0)
            result.push_back(s[i]);

        if (s[i] == s[j])
            result += string(midLen, s[i]);
        else if (s[i] == 'L' && s[j] == 'R')
            result += string(midLen, '.');
        else
            result += string(midLen / 2, 'R') + string(midLen % 2, '.') + string(midLen / 2, 'L');

        i = j;
    }

    cout << result << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}
