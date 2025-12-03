/**
 * * Rearranging fruits 
 * 
 * two baskets diye h 
 * baskets[i]=cost of fruit
 * Hum dono baksets ke let ko swap krte h 
 * hum dono basket ko equal bnana h at end after sorting
 * minimum cost mein
 * minimum cost == min of swapped elt 
 * 
 * eg ::              4,2,2,2       1,4,2,2
 * abhi maan lo       2,2,2,4       1,2,2,4
 * if i swap 1  and 2 
 * toh final hoga     1,2,24        1,2,2,4
 * at end dono equla h after soritng 
 * minium cost jo laga == min of 1,2 ==1 
 * so cost 1 mein hi ho gya   
 * 
 * hum dono baksets ke liye alag alag freq map bnayenge 
 * same elt ka dono map mein se total freq leke divide by 2 karenge 
 * jo ans aayega har basket mein wo elt utni baar hi hona chahiye 
 * 
 * eg      2 is 3  times in basket 1 
 *         2 is 1 times in bakset 2
 *   toatal =4    ans == 4/2 ==2 
 * dono basket mein 2  do baar hi hona chahiye 
 * yani ki isko swap krna hoga 
 * 
 * ab maan lo ek 2 toh dono mein 
 * bakset 1 mein do the 2 extra h 
 * isko split krna hoga 
 * 
 * 4 dono basket mein same times h   so extra 4 ==0 
 * 
 * now ::
 *  1 is present 0 times in bakset 2
 *  1 is present 2 times in bakset 2
 * extra 1 == 2
 * toh isko bhi split krna hoga 
 * 
 * 
 * ek final map lenge 
 * map mein +1 -1 form mein lenge elt ki freq 
 * agr elt b1 mein h +1 
 * agar b2 mein bhi h toh -1 
 * at end iski freq 0 ho jayegi toh yaani uss elt ko kuch nhi krna 
 * 
 * extra count aaya agr wo even h 
 * toh spliiting possible h 
 * agar odd h toh split kr hi nhi skte 
 * 
 * 
 * maan lo ab extras ye mile h 
 * 1,1     2,2 
 * ab inko swap krna h
 * 1  <->   2
 * toh ab ho gya
 * 1,2     1,2
 * 
 * toh hume kitni baar swap krna  uska hint milta h 
 * swap == freq/2 times 
 * 
 * ab maan lo jo elts extra h 
 * unko ek jageh alag se store kro
 * par kitni baar swap krna h uske accoridng 
 * so   [1,2]   kyunki swap == freq/2
 * 
 * 
 * * Ab hum ye chiz bade array pe try krte h 
 * 
 * bn1 ==   4,2,2,2,7,7,7,8,8,8
 * bn2 ==   9,4,9,2,7,8,5,5,1,1
 * final map 
 * 4 -> 0
 * 2 -> 2
 * 7 -> 2
 * 8 -> 2
 * 9 -> -2
 * 5 -> -2
 * 1 -> -2
 * 
 * 
 * ab swap array bnayenge 
 * [2,7,8,9,5,1]
 * order jaruri nhi ki yhi ho 
 * maan lo agar hum basket ke accoridng swap wale alag rakh de 
 * aur unko sort kr de 
 * b1 extra == 2,7,8
 * b2 extra == 1,5,9
 * toh agaer ek ke sabse chote ko dusre ke sabse bade ke sath swap karein toh 
 * min cost aayega 
 * 
 * eg ::
 * 1 <-> 8
 * 5 <-> 7
 * 2 <-> 9
 * total cost == 1+5+2  == 8
 * 
 * toh hume ye hint mila ki sort kar do 
 * 
 * hum chahe toh ek hi array mein store krke 
 * sort kr do 
 * firr 2 pointers approach krke le lo 
 * ya direct starting se n/2 elts le lo 
 * 
 * 
 * 
 * * WHAT'S WRONG 
 * Why 8 is not best answer
 * isse bhi better answer kaise nikal skta h 
 * jo hum 7 ko 5 se directly swap kr rhe h wo galat h 
 * toh pehlle ye karo
 * kisi bhi elt ko sabse minimum se swap karo jo opposite box mein 
 * 7 ko pehle 1 se swap karo
 * 9 ke liyen oppsite box mein minimum 2 h toh usse karo
 * firr 5 ko bhi 1 se swap kar do kyunki 1 abhi dusre box mein ja chuka h 
 * so we will do indirect swapping
 * 
 * 
 * 
 * swap(7,1) + swap(5,2) + swap(9,2)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */


 #include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // 🔸 Function to find minimum cost of making two baskets equal
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;             // 🔹 Map to count net frequency difference
        int minel = INT_MAX;                    // 🔹 Track minimum element for 2*minel strategy

        // 🔸 Add elements from basket1 and update frequency map
        for (int &x : basket1) {
            mp[x]++;                            // 🔹 x ek baar basket1 mein mila
            minel = min(minel, x);              // 🔹 Minimum element track karo
        }

        // 🔸 Subtract elements from basket2 and update map
        for (int &x : basket2) {
            mp[x]--;                            // 🔹 x ek baar basket2 mein mila
            minel = min(minel, x);              // 🔹 Minimum element update karo
        }

        vector<int> finalist;                   // 🔹 List of elements that actually need to be swapped

        for (auto &it : mp) {
            int cost = it.first;
            int count = it.second;

            if (count == 0) continue;           // ✅ No imbalance → skip

            if (count % 2 != 0) return -1;      // ❌ Odd count → can't balance baskets → return -1

            // 🔹 Add (count / 2) number of elements to swap list
            // Half because we'll pair this value with another during actual swapping
            for (int c = 1; c <= abs(count) / 2; c++) {
                finalist.push_back(cost);
            }
        }

        // 🔸 Sort so that we pick lowest cost items first
        sort(finalist.begin(), finalist.end());

        long long result = 0;
        int n = finalist.size();

        // 🔸 Only first half of elements used (they'll be paired with remaining half)
        for (int i = 0; i < n / 2; i++) {
            // 🔹 Swap cost: either direct element or roundabout using 2 * minel
            result += min(finalist[i], minel * 2);
        }

        return result;
    }
};



/**Improvement mein ye kr skte h ki half array hi sorted chahiye
 * toh pura array kyun sort krna 
 * sidhe nth element laga do 
 */

class Solution {
public:
    // 🔸 Function to find minimum cost of making two baskets equal
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;             // 🔹 Map to count net frequency difference
        int minel = INT_MAX;                    // 🔹 Track minimum element for 2*minel strategy

        // 🔸 Add elements from basket1 and update frequency map
        for (int &x : basket1) {
            mp[x]++;                            // 🔹 x ek baar basket1 mein mila
            minel = min(minel, x);              // 🔹 Minimum element track karo
        }

        // 🔸 Subtract elements from basket2 and update map
        for (int &x : basket2) {
            mp[x]--;                            // 🔹 x ek baar basket2 mein mila
            minel = min(minel, x);              // 🔹 Minimum element update karo
        }

        vector<int> finalist;                   // 🔹 List of elements that actually need to be swapped

        for (auto &it : mp) {
            int cost = it.first;
            int count = it.second;

            if (count == 0) continue;           // ✅ No imbalance → skip

            if (count % 2 != 0) return -1;      // ❌ Odd count → can't balance baskets → return -1

            // 🔹 Add (count / 2) number of elements to swap list
            // Half because we'll pair this value with another during actual swapping
            for (int c = 1; c <= abs(count) / 2; c++) {
                finalist.push_back(cost);
            }
        }

        // 🔸 nth_element to partially sort only half that we need
        // 🔹 Place median element at position finalist.size()/2
        int mid = finalist.size() / 2;
        nth_element(finalist.begin(), finalist.begin() + mid, finalist.end());

        long long result = 0;

        // 🔸 Only first half of elements used (they'll be paired with remaining half)
        for (int i = 0; i < mid; i++) {
            // 🔹 Swap cost: either direct element or roundabout using 2 * minel
            result += min(finalist[i], minel * 2);
        }

        return result;
    }
};
