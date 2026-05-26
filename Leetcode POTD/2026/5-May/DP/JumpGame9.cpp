/**
 * Leetcode 1340 : Jump Game V
 *
 * ---------------------------------------------------
 * ! Problem Description
 * ---------------------------------------------------
 * hume ek integer array aur integer d diya hota h
 *
 * har index se hum left ya right side mein maximum d distance tak jump kar skte h
 *
 * important condition:
 * hum sirf smaller value wale index pe hi jump kar skte h
 *
 * i.e.
 * arr[next] < arr[curr]
 *
 * agar kisi direction mein koi bada ya equal element mil gaya
 * toh us direction mein uske aage nhi ja skte
 *
 * eg:
 * arr = [6,4,14,6,8,13,9,7,10,6,12]
 * d = 2
 *
 * output:
 * 4
 *
 * ---------------------------------------------------
 * ! Dry Run Intuition
 * ---------------------------------------------------
 * constraints zyada bade nhi h isliye hum har index se
 * maximum possible jumps calculate kar skte h
 *
 * d ka matlab:
 * kisi bhi index i se hum i+1 se i+d tak
 * aur i-1 se i-d tak positions check kar skte h
 *
 * ---------------------------------------------------
 * ! Start From Index 0
 * ---------------------------------------------------
 * arr[0] = 6 aur d = 2
 *
 * right side:
 * index 1 pe value 4 h aur since 4 < 6
 * so yaha jump possible h
 *
 * index 2 pe value 14 h aur since 14 > 6
 * so yaha jump possible nhi h
 *
 * important rule:
 * agar kisi direction mein bada ya equal element mil gaya
 * toh uske aage bhi check nhi karna hota
 *
 * so index 0 se sirf index 1 pe jump possible h
 *
 * ---------------------------------------------------
 * ! Check Index 1
 * ---------------------------------------------------
 * arr[1] = 4
 *
 * left side:
 * arr[0] = 6 jo bada h so left blocked
 *
 * right side:
 * arr[2] = 14 jo bhi bada h so right blocked
 *
 * dono side blocked h
 * so index 1 se koi jump possible nhi h
 *
 * max path length from index 1 = 1
 *
 * ---------------------------------------------------
 * ! Check Index 2
 * ---------------------------------------------------
 * arr[2] = 14
 *
 * left side mein:
 * 6 < 14 aur 4 < 14
 * so left jumps possible h
 *
 * right side mein:
 * 6 < 14 aur 8 < 14
 * so right jumps bhi possible h
 *
 * ab hume wo path choose karna h
 * jisse maximum jumps mil sake
 *
 * ---------------------------------------------------
 * ! Core Observation
 * ---------------------------------------------------
 * har index ka answer dependent h
 * uske next smaller reachable indices ke answers pe
 *
 * ye recursion + dp / memoization pattern h
 *
 * ---------------------------------------------------
 * ! Recursive Thinking
 * ---------------------------------------------------
 * function(i) batayega ki index i se
 * maximum kitne indices visit kiye ja skte h
 *
 * har valid jump ke liye:
 * ans = 1 + function(nextIndex)
 *
 * aur sab valid jumps ka maximum lenge
 *
 * ---------------------------------------------------
 * ! Valid Jump Condition
 * ---------------------------------------------------
 * agar:
 * arr[next] < arr[curr]
 *
 * tabhi jump allowed h
 *
 * warna:
 * us direction mein break kar denge
 * aur aage nhi dekhenge
 *
 * ---------------------------------------------------
 * ! Why DP / Memoization?
 * ---------------------------------------------------
 * same index ka answer recursion mein
 * multiple baar calculate ho skta h
 *
 * isliye memoization use karenge
 *
 * ek baar answer calculate hone ke baad
 * usko dp array mein store kar lenge
 *
 * aur dobara recursion nhi chalayenge
 *
 * ---------------------------------------------------
 * ! Final Goal
 * ---------------------------------------------------
 * har index se maximum jumps calculate karenge
 *
 * final answer:
 * max(dp[i])
 *
 * ---------------------------------------------------
 * ! Time Complexity
 * ---------------------------------------------------
 * har index se maximum d left aur d right positions
 * check karte h
 *
 * TC:
 * O(n*d)
 *
 * ---------------------------------------------------
 * ! Space Complexity
 * ---------------------------------------------------
 * recursion stack aur dp array use hoga
 *
 * SC:
 * O(n)
 *
 */

/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
public:
    int n;
<<<<<<< HEAD
    vector<int> dpArray;

    int solve(vector<int>& arr, int d, int i) {
        if (dpArray[i] != -1)
            return dpArray[i];
=======
    vector<int> t;

    int solve(vector<int>& arr, int d, int i) {
        if (t[i] != -1)
            return t[i];
>>>>>>> e08c97c045febeaa9a372459f96b10c5f7224fd3

        int result = 1; // count current index also

        // move left
        for (int j = i - 1; j >= max(0, i - d); j--) {
<<<<<<< HEAD
            // can'dpArray jump further once taller/equal element appears
=======
            // can't jump further once taller/equal element appears
>>>>>>> e08c97c045febeaa9a372459f96b10c5f7224fd3
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        // move right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
<<<<<<< HEAD
            // can'dpArray jump further once taller/equal element appears
=======
            // can't jump further once taller/equal element appears
>>>>>>> e08c97c045febeaa9a372459f96b10c5f7224fd3
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

<<<<<<< HEAD
        return dpArray[i] = result;
=======
        return t[i] = result;
>>>>>>> e08c97c045febeaa9a372459f96b10c5f7224fd3
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
<<<<<<< HEAD
        dpArray.resize(n, -1);
=======
        t.resize(n, -1);
>>>>>>> e08c97c045febeaa9a372459f96b10c5f7224fd3

        int maxJump = 1;
        // We need to try from every index
        for (int i = 0; i < n; i++) {
            maxJump = max(maxJump, solve(arr, d, i));
        }

        return maxJump;
    }
};
