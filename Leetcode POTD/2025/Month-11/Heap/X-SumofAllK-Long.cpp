/**
 *!  Find X-sum of All -k long Subarrays Part -1 
 * 
 * Count occurences of all elements in the array 
 * keep top x most frequent elememnts 
 * if two elts have same occurences bigger elt is considered 
 * calculate sum of resulting array '
 * k= size of subarray 
 * x= top x most frequent elts 
 * 
 * eg :: 1,1,2,2,3,4,2,3
 * k =6 , x=2 
 * 
 * maan loabhi ye subarray liya 
 * 1,2,2,3,4,2
 * 2-3
 * 4-1
 * 1-1
 * 3-1
 * 
 * 2 ke baad 4 lenge kyunki 4 bigger elt h 
 * sum ho jayega 
 * 2+2+2   ,   4 
 * 
 * frequency ke liye map use kar lenge 
 * ab top k elt nikalna h having max frequency 
 * ya toh ab sort kr skte h vector men store krke 
 * ya firr priority queue use kr skte h 
 * max freq pucha h toh min heap le lenge 
 * toh faayda ye h ki min wale top pe ho jayenge toh unko remove kar denge
 *  
 * 
 * 
 * 
 * 
 * 
 */

 
 //Approach (Using max-heap + sliding window)
//T.C : O(n * k * log(k))
//S.C : O(k)
class Solution {
public:
    typedef pair<int, int> P; //freq, element
    int findTopXSum(unordered_map<int, int>& mp, int x) {
        //min-heap
        priority_queue<P, vector<P>, greater<P>> pq; //O(k) space

        for(auto &it : mp) { //O(k * log(k))
            pq.push({it.second, it.first});

            if(pq.size() > x) {
                pq.pop(); //remove smallest element from the top
            }
        }

        int sum = 0;
        while(!pq.empty()) { //K
            auto [freq, val] = pq.top(); //
            pq.pop(); //log(k)

            sum += freq*val;
        }

        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int, int> mp; //O(k)

        vector<int> result;

        int i = 0;
        int j = 0;
        //T.C : O(n * klogk)
        while(j < n) { //khandani sliding window template
            mp[nums[j]]++;

            if(j - i + 1 == k) {
                result.push_back(findTopXSum(mp, x));

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};
