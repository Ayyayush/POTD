#include <bits/stdc++.h>
using namespace std;

/**
 * ! Minimum Swaps to Arrange a Binary Grid
 * ! Leetcode 1536
 *
 * Hume main diagonal ke upar wale saare elements 0 karne hain.
 *
 * Example:
 * Input: grid = [[0,0,1],
 *                [1,1,0],
 *                [1,0,0]]
 *
 * Output: 3
 *
 * ! Thought Process:
 *
 * Row 0 ko diagonal ke upar n-1-0 = 2 zeros chahiye
 * Row 1 ko n-1-1 = 1 zero chahiye
 * Row 2 ko n-1-2 = 0 zero chahiye
 *
 * Hum sirf adjacent row swap kar sakte hain.
 * Isliye greedy tarike se nearest valid row ko upar laayenge.
 */



// ! ========================== OPTIMAL ==========================
void optimal()
{
    /*
    ! Approach Name: Greedy + Bubble Sort Style Swapping

    ! Idea:
    Har row ke liye count karo ki end se kitne consecutive zeros hain.
    Kyunki diagonal ke upar wale cells ka matlab hai:
    Row i ko kam se kam (n - i - 1) trailing zeros chahiye.

    Agar current row satisfy nahi karti,
    toh neeche wali rows mein search karo jo satisfy karti ho.

    Jo first valid row mile usko adjacent swaps se upar le aao.

    ! Time Complexity:
    endZeros banana → O(n^2)
    Har row ke liye search + swap → O(n^2)
    Total → O(n^2)

    ! Space Complexity:
    O(n)  (endZeros array)
    */

    vector<vector<int>> grid = {
        {0,0,1},
        {1,1,0},
        {1,0,0}
    };                                  // Hardcoded input

    int n = grid.size();

    vector<int> endZeros(n, 0);          // endZeros[i] = trailing zero count of row i

    // ! Step 1: Har row ke end se consecutive zeros count karo
    for(int i = 0; i < n; i++)
    {
        int j = n - 1;
        int count = 0;

        while(j >= 0 && grid[i][j] == 0)
        {
            count++;
            j--;
        }

        endZeros[i] = count;             // Store trailing zeros
    }

    int steps = 0;

    // ! Step 2: Har row ko correct position pe laana
    for(int i = 0; i < n; i++)
    {
        int need = n - i - 1;            // Row i ko itne zeros chahiye

        int j = i;

        // Neeche search karo first row j jisme trailing zeros >= need
        while(j < n && endZeros[j] < need)
        {
            j++;
        }

        if(j == n)                       // Agar koi valid row nahi mila
        {
            cout << "Answer: -1" << endl;
            return;
        }

        steps += (j - i);                // Itne swaps lagenge

        // ! Bubble style swapping (row ko upar lao)
        while(j > i)
        {
            swap(endZeros[j], endZeros[j-1]);
            j--;
        }
    }

    cout << "Answer: " << steps << endl;
}



int main()
{
    optimal();
    return 0;
}



/*
! ========================== JS Optimal ==========================

function minSwaps(grid) {
    const n = grid.length;
    const endZeros = [];

    for (let i = 0; i < n; i++) {
        let count = 0;
        for (let j = n - 1; j >= 0 && grid[i][j] === 0; j--) {
            count++;
        }
        endZeros.push(count);
    }

    let steps = 0;

    for (let i = 0; i < n; i++) {
        let need = n - i - 1;
        let j = i;

        while (j < n && endZeros[j] < need) j++;

        if (j === n) return -1;

        steps += j - i;

        while (j > i) {
            [endZeros[j], endZeros[j-1]] = [endZeros[j-1], endZeros[j]];
            j--;
        }
    }

    return steps;
}


! ========================== Python Optimal ==========================

def minSwaps(grid):
    n = len(grid)
    endZeros = []

    for row in grid:
        count = 0
        j = n - 1
        while j >= 0 and row[j] == 0:
            count += 1
            j -= 1
        endZeros.append(count)

    steps = 0

    for i in range(n):
        need = n - i - 1
        j = i

        while j < n and endZeros[j] < need:
            j += 1

        if j == n:
            return -1

        steps += j - i

        while j > i:
            endZeros[j], endZeros[j-1] = endZeros[j-1], endZeros[j]
            j -= 1

    return steps

*/