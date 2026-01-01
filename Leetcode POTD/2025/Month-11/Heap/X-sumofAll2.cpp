
 //Approach (Using max-heap + sliding window)
//T.C : O(n * k * log(k))
//S.C : O(k)
class Solution {
public:
    typedef pair<long long , long long > P; //freq, element
    long long  findTopXSum(unordered_map<long long , long long >& mp, long long  x) {
        //min-heap
        priority_queue<P, vector<P>, greater<P>> pq; //O(k) space

        for(auto &it : mp) { //O(k * log(k))
            pq.push({it.second, it.first});

            if(pq.size() > x) {
                pq.pop(); //remove smallest element from the top
            }
        }

        long long  sum = 0;
        while(!pq.empty()) { //K
            auto [freq, val] = pq.top(); //
            pq.pop(); //log(k)

            sum += freq*val;
        }

        return sum;
    }


    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        long long  n = nums.size();

        unordered_map<long long , long long > mp; //O(k)

        vector<long long > result;

        long long  i = 0;
        long long  j = 0;
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



/**
 * Upar wala approach TLE de dega 
 * kyunki iss baar constraint high h 
 * it is a type of data structure heavy problem 
 * 
 * 
 * ! Thought process
 * sliding window use krke ek tarah se optimise kiya hi tha 
 * but ab aurr optimize krna h 
 * toh hum improvement sliding window wale part mein aur optimize nhi kr skte
 * toh hume khi aurr optimize krna padega yani ki function mein 
 * 
 * Improvment in top x elemengt function karenge 
 * hum glti ye kr rhe the ki priority queue mein ki jab jab 
 * sliding window shift krke naya subarray dega 
 * utni baar priority queue build kr rhe h 
 * toh baar baar daalne mein mehnat lag rhi h 
 * priority queue mein ye bhi prooblem h 
 * ki agar ha baar alag al;ag na bana ke 
 * ek hi baar banye pq toh iterate krna padega 
 * jo ki ek problem h 
 * so hume ek naya ds chahiye jo ordered way mein rakhe elt aur search bhi kr paye 
 * toh wo ds h ordered set 
 * 
 * 
 * ! Will Data Structure Help me 
 * 
 * eg :: nums=1,1,2,2,3,4,2,3
 * k =6    x= 2
 * <freq,elt>
 * set = {(2,1,),(2,2),(1,3),(1,4)}
 * now ordered={(1,3),(1,4),(2,1),(2,2)}
 * 
 * ab dekhte h ki kaam kar bhi rha h ya nhi 
 * ab set mein toh dhund skte h 
 * ab maan lo sliding window mein naya elt 2 add hua h 
 * toh set se purani freq nikal lo 
 * set.find(2,2) krke    // logarithmic operatrion h 
 * ab update krna padega
 * now ordered={(1,3),(1,4),(2,1),(3,2)}  
 * ab directly find kr skte h 
 * ab 1 ka freq bhi ghata tha 
 * ye faayda ho gya ki aaram se freq ko update kar pa rhe h 
 * 
 * ab baat ye h ki jab finally sum nikalna hoga toh  O(x) lag jayega
 * toh 10^5 * 10^5  ho jayega 
 * hume optimally sum nikalna padega 
 * 
 * ab ek chiz dhyaan do ki O(x) bhi nhi chalegha 
 * toh isse kam mein nikalne ke liye kya karna padega 
 * sum ko constantr time mein nikalna padega 
 * hum sum naam ka ek variable rakh lenge 
 * aur usme sum maintain karte rahenge 
 * 
 * ab aata h 
 * ! Most important part 
 * it is used in many ther problems 
 * 
 * * Find the median of a stream problem mein use hua h 
 * 
 * ab dekho simple sa concept h 
 * ki maan ke chalo ek simple sa set le lete h 
 * set={a,b,c,d,e}
 * ab maan lo top 2 let ka sum sum constant time mein chhaiye
 * toh hu mt2 set use karenge 
 * constant time mei n krne ke liye 
 * 
 * min = {d,e}
 * max = {}
 * ek set ko main maan ke chalenge 
 * main = {d,e}
 * sum = {a,b,c}
 * sum = d+e 
 * 
 * ab dekho window slide krne ki wjaeh se hota ye h ki
 * koi elt aa bhi sakta h 
 * aur koi elt ja bji sakta h 
 * 
 * hum har waqt main wale set ka size x leke chal rhe h 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */