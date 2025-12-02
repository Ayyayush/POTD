#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// 🧠 Approach: Simulation + Brute Force Checking
// T.C. = O(N^2)              --> Har zero ke liye complete traversal kar rahe hain
// S.C. = O(N)                --> Temporary array copy ke liye
//////////////////////////////////////////////////////////////
int simulate(vector<int> &nums, int idx)
{
    vector<int> arr = nums;                              // Original array ka ek copy le rahe hain
    int count = 0;                                       // Valid selection count
    
    bool left,right;
    // 🔹 Pehla simulation
    int i = idx + 1;                                     // Start right se karte hain
    while (i < arr.size() && i >= 0)
    {
        if (arr[i] != 0)                                 // Agar element zero nahi hai
        {
            arr[i] -= 1;                                 // Ek decrease karte hain
            if (i > idx)  {                               // Agar right side se aaye hain
                left=true;
                right=false;
            }
            else{
                right=true;
                left=false;
        }}
        if(left)
        {
            i--;
        }
        else
        {
            i++;
        }
    }

    bool zero = true;                                    // Sab zero hue ya nahi check karte hain
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            zero = false;
            break;
        }
    }
    if (zero) count++;                                   // Agar sab zero hue to count++

    // 🔹 Dusra simulation
    arr = nums;                                          // Array firse reset karte hain
    i = idx - 1;                                         // Ab left se start karte hain
    while (i < arr.size() && i >= 0)
    {
        if (arr[i] != 0)                                 // Agar element zero nahi hai
        {
            arr[i] -= 1;                                 // Ek decrease karte hain
            if (i > idx)  {                               // Agar right side se aaye hain
                left=true;
                right=false;
            }
            else{
                right=true;
                left=false;
        }}
        if(left)
        {
            i--;
        }
        else
        {
            i++;
        }
    }

    zero = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            zero = false;
            break;
        }
    }
    if (zero) count++;                                   // Agar sab zero hue to count++

    return count;                                        // Total valid selection count return
}


//////////////////////////////////////////////////////////////
// 🧩 Main Function: countValidSelections()
// Har index jahan nums[i] == 0 hota hai, uske liye simulate() call karte hain
//////////////////////////////////////////////////////////////
void brute()
{

    // this approach fails for the following example nums
    vector<int> nums = {16,0,0,12,5};                     // Example input
    int count = 0;                                       // Valid selections count
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)                                 // Sirf zero positions pe simulate karte hain
            count += simulate(nums, i);                  // Dono directions ka check
    }

    cout << "Total valid selections: " << count << endl;  // Final answer print karte hain
}


/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=1uMoX4soG38
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/make-array-elements-equal-to-zero
*/

/*********************************************************** C++ **************************************************/
//Approach-1 - (Simple simulation)
// ! Corrected Approach 
//T.C : O(n^ * m) 
//S.C : O(n)
class Solution {
public:
    bool isValid(vector<int>& nums, int count, int i, int direction) {
        vector<int> temp = nums;
        int idx = i;

        while (count > 0 && idx >= 0 && idx < nums.size()) {
            if (temp[idx] > 0) {
                temp[idx]--;
                direction *= -1;
                if (temp[idx] == 0) {
                    count--;
                }
            }
            idx += direction;
        }

        return count == 0; //all must become 0
    }

    int countValidSelections(vector<int>& nums) {
        int result = 0;
        int count = 0; //count of nums[i] != 0
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                count++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, count, i, -1)) {
                    result++;
                }
                if (isValid(nums, count, i, 1)) {
                    result++;
                }
            }
        }

        return result;
    }
};




/**
 * ! New  Approach 
 * Simulation type ka problem h 
 * jaisa question mein diya h waisa kr skte h 
 * Ab hum cumulative sum approach try karenge 
 * 
 * eg ::
 * 1,0,2
 * ab maan lo pehle hum right move krte h 
 * ab 2 milega toh 2-1 karke left chalenge 
 * left chal chal ke 1 pe aaya 1-1 ==0 hua 
 * firr right hua 
 * firr 2 jo 1 h uspe aaya wo 0 ho gya 
 * ab sab 0 ho gye 
 * sab 0 ho gye so count+=1
 * 
 * ab maan lo yhi pehle 1 yani left p[e gye hote toh 
 * 1-1==0
 * krke right jaate 
 * firr left jaate troh firr wapas right nhi aa pate 
 * kyunki koi au rnon zero bacha hi nhi right aane ke liye 
 * 
 * ab maan lo 1 ki jageh left mein bhi 2 hota 
 * toh left jaane pe bhi ans aa jata 
 * 
 * yaani jis index pe bhi 0 h agar uske left side ka sum == right side ka sum
 * toh guarantee 2 ans possible h 
 * sabjhe chunnu lal
 * 
 * if(leftsum==rightsum)
 * result+=2
 * else if (leftsum!=rightsum)
 * {
 * if(direction == greatersumdirection)    // only if diff ==1 
 * result+=1
 * bcz maan lo 1,0,3 hota toh nhi hon pata 
 * par 2,0,3 hota toh ho jate 
 * toh hum dekhte h ki diff 1 hona chahiye 
 * }
 * 
 *  
 * 
 */


 //Approach-2 - (Using cumulative sum)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int result =0;
        int curr = 0;
        int S = accumulate(begin(nums), end(nums), 0);//for loop bhi likh sakte ho


        for(int i = 0; i < n; i++) {
            curr += nums[i]; //left sum

            int left  = curr;
            int right = S - left;

            if(nums[i] != 0) {
                continue;
            }

            if(left == right)
                result += 2;
            
            if(abs(left - right) == 1)
                result += 1;
        }

        return result;
    }
};

int main()
{
    brute();
    return 0;
}
