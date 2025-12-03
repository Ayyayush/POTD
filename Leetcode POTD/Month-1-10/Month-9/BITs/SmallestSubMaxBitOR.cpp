/**
 * Weekly Contets 87
 * Smallest Subarrays with Maximum Bitwise OR
 * 
 * 
 * har index se start hone wale subarray ka size btana h
 * jiska size min se min ho aur value max se max
 * eg ::   1,0,2,1,3
 * ans ==  3,3,2,2,1
 * 
 * 
 * Thought Process
 * maximum or ya ans kab milega jab jyada se jyada bit set ho ya saare bit set ho
 * already set ho chuka h toh aage jaane ki jarurat nhi 
 * eg :: when i =1 toh hume index =3 tak jana pada
 * to make all index bits set 
 * toh i=1 ke liye shortest subarray jop maximum or de uska length h 3
 * 
 * 
 * eg :: 1,0,2,1,10
 * ab maan lo i=0 h
 * max bitwise or find krna shuru krte h min se min subarray mein 
 * 1,0,2,1,10   inn sab ko lene se max bna rha 
 * toh i=0 ke liye minsub ka ans hoga 5
 * ab dekhte h kis index ke element ki wajeh se kaun sa bit set ho rha h
 * jaise hi kisi index pe sab set ho jaye ruk jao 
 * ha rbit ke liye dekho kis index tak jana pad rha
 * last mein jaha tak bhi jana pada uska max le lo 
 * whi uss i ke liye ans hoga 
 * toh nested loop se check krte jayenge wo brute approach hoga 
 * 
 * Better
 * Hum right se check krte jayenge ab 
 * hum use karenge how to check ith bit is set or not 
 * number && (1<<k)!=0   toh ktrh bit set rha hoga 
 * 
 * 
 * 
 */

 //Approach (Using frequency count and Xor Property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();                                              // nums ka size nikal liya

        vector<int> result(n);                                            // yeh final result array hai — har index pe subarray length aayegi

        vector<int> setBitIndex(32, -1);                                  // yeh 32-bit array rakha hai, har bit ke last seen index ko track karega
        // setBitIndex[j] = i   it means that jth bit can be set via element at index i in nums 

        for(int i = n-1; i >= 0; i--) {                                   // reverse traversal from right to left

            int endIndex = i;                                             // initially subarray ka end index i hi hoga
            for(int j = 0; j < 32; j++) {                                 // har bit ko check karenge (0 to 31)

                if(!(nums[i] & (1 << j))) {                               // agar jth bit nums[i] mein set nahi hai
                    if(setBitIndex[j] != -1) {                            // aur agar woh bit pehle kabhi set dekhi gayi thi
                        endIndex = max(endIndex, setBitIndex[j]);         // toh subarray ka end wahan tak lena padega
                    }
                } else {
                    setBitIndex[j] = i;                                   // agar jth bit nums[i] mein set hai toh is index pe update kar do
                }
            }

            result[i] = endIndex - i + 1;                                 // subarray ki length = endIndex - i + 1
        }

        return result;                                                   // final result array return karo
    }
};

