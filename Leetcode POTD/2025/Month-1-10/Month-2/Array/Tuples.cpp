#include <bits/stdc++.h>
using namespace std;





// Approach-1 (Brute Force)  ---> T.C : O(n^4) , S.C : O(1)
void brute()
{
    vector<int> nums = {2, 3, 4, 6};                // Input array

    int totalNumberOfTuples = 0;                    
    int n = nums.size();                            

    for (int i = 0; i < n; i++) {                   // 'a' choose kar rahe hain
        for (int j = i + 1; j < n; j++) {           // 'b' choose kar rahe hain (a se different)
            for (int k = 0; k < n; k++) {           // 'c' choose kar rahe hain
                for (int l = k + 1; l < n; l++) {   // 'd' choose kar rahe hain (c se different)
                    
                    if (i != k && i != l && j != k && j != l) {   // Ensure indices different hain
                        int product1 = nums[i] * nums[j];         
                        int product2 = nums[k] * nums[l];         

                        if (product1 == product2) {               // Dono ka product same hai to count increase karenge
                            totalNumberOfTuples++;
                        }
                    }
                }
            }
        }
    }

    cout << (totalNumberOfTuples / 2) * 8 << endl;   // Double counting ko handle karne ke liye divide by 2 kiya
}





// Approach-2 (Sorting to improve efficiency)  ---> T.C : O(n^4 + nlogn) , S.C : O(1)
void better()
{
    vector<int> nums = {2, 3, 4, 6};       // Input array

    int totalNumberOfTuples = 0;
    int n = nums.size();
    sort(begin(nums), end(nums));          // Sorting kar rahe hain taaki order maintain ho

    for (int i = 0; i < n; i++) {          
        for (int j = n-1; j > i; j--) {    
            for(int k = i+1; k < j; k++) {
                for(int l = j-1; l > k; l--) {

                    int p1 = nums[i] * nums[j];   // Pehla product
                    int p2 = nums[k] * nums[l];   // Dusra product

                    if(p1 == p2) {               // Agar dono product same hain to count badhayein
                        totalNumberOfTuples++;
                    }
                }
            }
        }
    }

    cout << totalNumberOfTuples * 8 << endl;   // Final answer
}





// Approach-3 (Better Brute Force)  ---> T.C : O(n^3) , S.C : O(n)
void optimal()
{
    vector<int> nums = {2, 3, 4, 6};      // Input array

    int totalNumberOfTuples = 0;
    int n = nums.size();
    sort(begin(nums), end(nums));        // Sorting to make searching efficient

    for (int i = 0; i < n; i++) {        
        for (int j = n - 1; j > i; j--) {
            int product = nums[i] * nums[j];   // Pehla product calculate kiya
            unordered_set<int> st;            

            for (int k = i+1; k < j; k++) {    // 'c' choose kar rahe hain
                
                if(product % nums[k] == 0) {   // Agar divisible hai to possible 'd' nikal sakte hain
                    int lValue = product/nums[k];

                    if(st.count(lValue)) {   // Agar 'd' pehle se set mein hai to valid tuple mila
                        totalNumberOfTuples++;
                    }

                    st.insert(nums[k]);   // 'c' ko set mein daal rahe hain future ke liye
                }
            }
        }
    }

    cout << totalNumberOfTuples * 8 << endl;   // Final answer
}





// Approach-4 (Using HashMap for counting pairs)  ---> T.C : O(n^2) , S.C : O(n)
void moreOptimal()
{
    vector<int> nums = {2, 3, 4, 6};       // Input array

    int n = nums.size();
    int tuples = 0;
    unordered_map<int, int> mp;            // HashMap to store product frequency

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int p = nums[i] * nums[j];      // Har pair ka product store kar rahe hain
            mp[p]++;
        }
    }

    for(auto &it : mp) {                   // HashMap traverse karke tuples count karenge
        int freq = it.second;
        tuples += (freq * (freq-1))/2;      // nC2 formula apply kiya
    }

    cout << tuples * 8 << endl;             // Final answer
}





int main()
{
    brute();       
    better();      
    optimal();     
    moreOptimal(); 

    return 0;
}
