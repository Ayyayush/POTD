class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result(queries.size());

        int n = nums.size();

        for (int i = 0; i < queries.size(); i++) {

            int idx = queries[i];

            if (mp[nums[idx]].size() == 1)
                result[i] = -1;
            else {
                int mindist = INT_MAX;

                for (auto it : mp[nums[idx]]) {

                    if (it == idx) continue;

                    int dist = abs(it - idx);
                    mindist = min(mindist, min(dist, n - dist));  // ✅ FIX HERE
                }

                result[i] = mindist;
            }
        }

        return result;
    }
};





/************************************************************ C++ *****************************************************/
//Approach - Store in map and use binary search to find indices
//T.C : O(Q * log(n))
//S.C : O(n)
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for(int qi : queries) { //O(Q)
            int element = nums[qi];
            vector<int>& vec = mp[element];

            int sz = vec.size();

            //no more occurence of this element
            if(sz == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec); //log(n)
            int res = INT_MAX;

            //Right Neighbour - pos+1
            int right = vec[(pos+1) % sz];
            int d = abs(qi - right);//straight forqward distance
            int circularDist = n-d;
            res = min({res, d, circularDist});


            //Left Neighbour - pos-1
            int left = vec[(pos-1+sz) % sz];
            d = abs(qi - left);//straught forqward distance
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }

        return result;
    }
};


/************************************************************ C++ *****************************************************/
/*
 * 🚀 APPROACH: Map + Binary Search (Optimal)
 * ----------------------------------------------------
 * 🧠 IDEA (Simple Hinglish):
 * 
 * 👉 Same value ke saare indices ko ek vector me store kar lo (sorted order me)
 * 👉 Har query ke liye:
 *      - current index ka position dhundo (lower_bound se)
 *      - uske left aur right neighbour check karo
 *      - circular distance bhi consider karo
 *
 * ----------------------------------------------------
 * 🧪 Example:
 * nums = [1,2,1,3,1]
 * mp[1] = [0,2,4]
 *
 * Query: idx = 2
 * → left = 0
 * → right = 4
 *
 * direct dist = |2-0| = 2
 * circular dist = n - 2 = 3
 *
 * 👉 answer = min(all distances)
 *
 * ----------------------------------------------------
 * ⏱️ TIME COMPLEXITY:
 * O(Q * log N)
 *
 * 🧠 SPACE COMPLEXITY:
 * O(N)
 */

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        /*
         * 🔥 Step 1: Map banao
         * value → list of indices
         */
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        /*
         * 🔁 Step 2: Har query process karo
         */
        for(int qi : queries) {   // O(Q)

            int element = nums[qi];

            /*
             * Same element ke saare indices
             */
            vector<int>& vec = mp[element];
            int sz = vec.size();

            /*
             * ❌ Agar sirf ek hi occurrence hai
             */
            if(sz == 1) {
                result.push_back(-1);
                continue;
            }

            /*
             * 🔍 Step 3: Current index ka position find karo
             * (binary search use kar rahe hain)
             */
            int pos = lower_bound(vec.begin(), vec.end(), qi) - vec.begin();

            int ans = INT_MAX;

            /*
             * 👉 RIGHT neighbour
             * (circular ke liye % use kiya)
             */
            int rightIndex = vec[(pos + 1) % sz];

            int dist = abs(qi - rightIndex);   // normal distance
            int circularDist = n - dist;       // circular distance

            ans = min(ans, min(dist, circularDist));

            /*
             * 👉 LEFT neighbour
             */
            int leftIndex = vec[(pos - 1 + sz) % sz];

            dist = abs(qi - leftIndex);
            circularDist = n - dist;

            ans = min(ans, min(dist, circularDist));

            /*
             * ✅ Final answer push karo
             */
            result.push_back(ans);
        }

        return result;
    }
};