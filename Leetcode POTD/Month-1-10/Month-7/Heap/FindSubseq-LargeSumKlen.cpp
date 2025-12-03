#include <bits/stdc++.h>
using namespace std;

// Global variables for tracking best subsequence and its sum
vector<int> bestSubsequence;
int maxSum = INT_MIN;

void generate(int idx, vector<int>& nums, vector<int>& temp, int k)
{
    // Base case: agar subsequence ki length k ho gayi
    if (temp.size() == k)
    {
        int currSum = accumulate(temp.begin(), temp.end(), 0);      // current subsequence ka sum nikala
        if (currSum > maxSum)
        {
            maxSum = currSum;                                       // maxSum update kiya
            bestSubsequence = temp;                                 // best subsequence store kiya
        }
        return;
    }

    if (idx == nums.size()) return;                                 // array ke end tak pahuch gaye

    // Include current element in subsequence
    temp.push_back(nums[idx]);
    generate(idx + 1, nums, temp, k);                               // recursive call with current element included

    // Backtrack (exclude current element)
    temp.pop_back();
    generate(idx + 1, nums, temp, k);                               // recursive call without including current element
}

void brute()
{
    // Approach: Recursion (Generate all subsequences of length k)
    // Time Complexity: O(2^n * k)
    // Space Complexity: O(k)

    vector<int> nums = {2, 1, 3, 3};         // Sample input
    int k = 2;

    vector<int> temp;
    bestSubsequence.clear();
    maxSum = INT_MIN;

    generate(0, nums, temp, k);             // recursive function call

    // Print result
    for (int x : bestSubsequence)
        cout << x << " ";
    cout << endl;
}


/**
 * *Better Method
 * Subsequence h toh ordering shi hona chahiye 
 * recursion wale mein indexing shi reh rha h but tle ho rha
 * toh kuch aisa karo ki tle na ho aur indexing bhi rhe
 * Number ke sath uska index bhi store karenge 
 * phir starting ke k elements ko index ke basis pe sort kr do  
 * 
 * *Steps::=
 * Store in a vector of pair  with index
 * Sort in descending order
 * Preserve index in sorting 
 * auto lamda likh ke index ke accoridng sort karayenge 
 * Pick k elements from beginning but index should be in correct order (jo ki sorted hi h)
 * 
 */




 void better()
{
    // 🔸 Input lena
    vector<int> nums = {2, 1, 3, 3};     // example input
    int k = 2;

    int n = nums.size();
    if (k == n)
    {
        for (int num : nums) cout << num << " ";
        cout << endl;
        return;
    }

    // 🔹 Step 1: Pair har number ko uske index ke saath
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = {i, nums[i]};
    }

    // 🔹 Step 2: Value ke hisaab se descending sort (top k max chahiye)
    auto comp = [](pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    };
    sort(vec.begin(), vec.end(), comp);

    // 🔹 Step 3: Top k elements uthao
    vector<pair<int, int>> topK(vec.begin(), vec.begin() + k);

    // 🔹 Step 4: Inhe index ke hisaab se sort karo (original order maintain karne ke liye)
    sort(topK.begin(), topK.end());

    // 🔹 Step 5: Sirf values print karo
    for (int i = 0; i < k; i++) {
        cout << topK[i].second << " ";
    }
    cout << endl;
}




/**
 * * Optimal
 * hume pura sort krne ke jarurat nhi h 
 * kyunki bas first nth elements chahiye 
 * Partial sorting karenge nth element use krke 
 * Nth element nth position pe nth smallest rakh dega  ya greatest rakh dega 
 * nth ke left aur right sorted nhi hoga 
 * Partial sort ka avg time complexity O(n) h 
 * 
 * eg ::3,1,5,7,2  nth ==3
 * partial sort karenge toh lambda..greater<int> lagake
 *   2,1,3,7,5 
 * 3rd postion pe bas 3 aa gya shi se 
 * Kth largest element pata chal jayega avg O(n) mein hi mil gya 
 * par ye original nums mein nhi karenge temp bnake karenge 
 * par abhi bhi index nhi pata h indexing ka dhyaan rakhna h
 * kth largest pata h hume indexing ka dhyaan rakhnge temp aur nums ko compare karke
 * ab original nums[i] ko compare krke dekhnge kya kth largest se <= h kya
 * agar h toh shi h valid h store kar lo
 * agar kth largest se chota h toh wo include ho hi nhi skta
 * 
 * 
 * 
 * 
 * *CORNER CASE 
 * 5,2,1,2,3    k==3 
 * nth element laga ke sort kr liya 
 * real descending sorting == 5,3,2,2,1 
 * nthy element sorting   == 5,3,,2,2,1 
 * left side greater honge right side larger par sorted nhi 
 * ab nums mein starting se traverse krna shuru karo 
 * toh ye elements include hote jayenge kyunki nth se bade h..
 * 5,2,2  ...but but but
 * ye wrong h galti ye h ki ye 2nd 2 range ke bahar h jiski wajeh se 3 chut rha 
 * toh hum count kr lenge ki kth largets se left yani uske range mein ..
 * hume kth largets elt ko kitni baar lena h 
 * toh bas whi element lo jo kth largest se >= ho but freq desired ho 
 * toh CONCLUSION kth largets element ka frequency maintain karo 
 * 
 * 
 */



 
void optimal()
{
    // 🔸 Input lena
    vector<int> nums = {2, 1, 3, 3};     // example input
    int k = 2;

    if (k == nums.size()) {
        for (int num : nums) cout << num << " ";
        cout << endl;
        return;
    }

    // 🔹 Step 1: Copy original vector
    vector<int> temp(nums);

    // 🔹 Step 2: nth_element ka use karke k-th largest tak le jao
    nth_element(temp.begin(), temp.begin() + k - 1, temp.end(), greater<int>());

    int threshold = temp[k - 1];  // 🔹 yahi wo value hai jo last cut-off pe hai
    int countThreshold = count(temp.begin(), temp.begin() + k, threshold);  // 🔹 threshold kitni baar aya hai top k mein

    vector<int> result;
    
    // 🔹 Step 3: Original nums mein se wo elements uthao jo > threshold ya threshold ke equal ho par limit tak
    for (int num : nums) {
        if (num > threshold) {
            result.push_back(num);
        } else if (num == threshold && countThreshold > 0) {
            result.push_back(num);
            --countThreshold;
        }
        if (result.size() == k)
            break;
    }

    // 🔹 Output result
    for (int x : result) cout << x << " ";
    cout << endl;
}

int main()
{
    optimal();
    return 0;
}
