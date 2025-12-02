#include <bits/stdc++.h>
using namespace std;


void brute() {
    // T.C. = O(n^2), S.C. = O(1)
    // Approach: Use nested loops to count frequency of each element manually

    vector<int> arr = {2, 2, 3, 4};             // sample input
    int n = arr.size();
    int result = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;                        // manually count frequency
            }
        }
        if (count == arr[i]) {
            result = max(result, arr[i]);       // update result if lucky
        }
    }

    cout << "Lucky Integer (brute): " << result << endl;
}



void good()
{
    // T.C. = O(n), S.C. = O(n)
    // Approach: Use unordered_map to count frequency, then check value == freq

    vector<int> arr = {2, 2, 3, 4}; // sample input
    unordered_map<int, int> mp;
    int result = -1;

    for (auto it : arr)
    {
        mp[it]++; // frequency count
    }

    for (auto it : mp)
    {
        if (it.first == it.second)
        {                                   // lucky condition
            result = max(result, it.first); // update max lucky number
        }
    }

    cout << "Lucky Integer (better): " << result << endl;
}


void better() {
    // Approach: Frequency Array (Size 501, as 1 <= arr[i] <= 500)
    // T.C. = O(n), S.C. = O(501)==O(1) (since freq array is of constant size)

    vector<int> arr = {2, 2, 3, 4};      // input example

    vector<int> freq(501, 0);            // 501 size freq array for elements up to 500
    int maxi = INT_MIN, mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;                 // frequency badha rahe
        maxi = max(arr[i], maxi);       // max element
        mini = min(arr[i], mini);       // min element
    }

    int ans = -1;
    for (int i = maxi; i >= mini; i--) {
        if (freq[i] == i) {             // lucky number condition
            ans = freq[i];              // yeh value lucky hai
            break;
        }
    }

    cout << ans << endl;                // output print
}


/**
 * Ab aisa approach dhundenge ki O(501) bhi na lage
 * 
 * min freq kbhi bhi 1 ho skta h agar array empty nhi h toh
 * worst case mein ye h ki pure array mein same number hi present h 
 * toh max freq kbhi bhi n == size of array ho skta h 
 * toh possible answer 1 se n ke beech hi hoga
 * ab maan lo array mein elt 7 h aur n==4 h 
 * toh maan lo 7 ko dekhe toh kbhi possible hi nhi ki 7 ki freq 7 ho jaye
 * so hamara ans hamesha 1 se n ke beech hoga 
 * arr.size() max 500 hi hoga 
 * 
 * ab hum maan lo har elet ko hi ye kaam dete h
 *  ki wo yaad rakhe ki wo kitni baar aaya h
 * store aise karenge dekho 
 * y h toh uski info y-1 index pe hogi
 * x h toh uski info x-1 pe .........so on
 * aise hoga ye ki humne pata rahega ki har elet ke liye kha jaana h count badhane 
 * end mein hume pata karna aasan hoga ki kha ka freq aur elt same h
 * 
 * *HOW TO STORE COUNT ALONG WITH NUMBERS IN PLACE 
 * Ab dekho maximum possible ans 500 se bada ho hi nhi skta 
 * matlab n se bada ho hi nhi skta 
 * sabse bada number jo mil skta h iska mtlb wo 500 hi h 
 * integer h dekho int toh 32 bit wale numbers h 
 * 
 * 
 * * 1 <= arr[i] <= 500
 * 1 <= size <= 500
 *
 *
 * Observations:
 * -----------------------------------
 * ✅ The largest possible "lucky number" = 500
 *
 * ✅ Binary Representation:
 * Let's say we are storing values up to 500.
 * 500 in binary = 111110100
 * => This can be represented in 9 bits.
 *
 * But in code, we typically use 16-bit integers for storage:
 *
 * 16-bit binary format:
 * -----------------------
 * | 0 0 0 0 0 0 0 ... | 1 1 1 1 0 1 0 0 |
 *           (padding)       (500 in binary)
 *
 * So we can safely use 16-bit integers to represent any number up to 500.
 *
 * 
 * *SO HUM BIT HI USE KARENGE VALUE STORE KAR LENGE 
 * YE BHOT ANCIENT TECHNIQUE H 
 * pehle 16 bit mein value store kar lo
 * pichle 16 bit mein freq store kar lo
 * 
 * 
 * *DRY RUN
 *  AB DEKHTE H KARENGE KAISE 
 * har number k o 32 bit binary men likh lo
 * 
 * 
 *  * Array: {1, 2, 2, 3, 3, 3, 4, 5}
 *
 * Bitmask representation using 16-bit integers:
 * - Each bit represents presence of a number.
 * - Bit position `i` = 1 if number `i` is present in the subarray.
 *
 * curr[0] = 00000000 00000000    00000000 00000001   // only 1 present
 * curr[1] = 00000000 00000000    00000000 00000001   // 1, 2 present
 * curr[2] = 00000000 00000000    00000000 00000010   // 1, 2 (again)
 * curr[3] = 00000000 00000000    00000000 00000011
 * curr[4] = 00000000 00000000    00000000 00000100
 * curr[5] = 00000000 00000000    00000000 00000101
 * 
 * 
 * toh ab pichle half mein freq store karna h
 * kis bit pe value badhani h uske left 1<<idx use karenge 
 * 
 */


 //Approach-3 (Using bits to store frequency)
//T.C : O(n)
//S.C : O(1) in place
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        for(int &num : arr) {
            int val = (num & 65535);

            if(val <= n) {
                arr[val-1] += (1<<16); //65536, pow(2, 16)
            }
        }

        for(int val = n; val >= 1; val--) {
            if((arr[val-1] >> 16) == val) {
                return val;
            }
        }

        return -1;
    }
};

