/**
 * * Bitwise Or of Subarrays
 * hume saare subarrays ka bitwise or nikalna h
 * bujrte force mein nested loop se nikaal lenge 
 * 
 * 
 * * BETTER APPROACH 
 * eg:: 1,5,2,3
 * 1 
 * 1,5
 * 1,5,2
 * 1,5,2,3
 * dekho jo naya element aa rha h 
 * wo khud mein ek naya elt h 
 * hum har index pe end hone wale saare subarrays ko store kar lenge 
 * 
 * 

 */


void brute()
{
    // Input lena
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    unordered_set<int> st;                         // unique OR values store karne ke liye

    for(int i = 0; i < nums.size(); i++) {
        int result = 0;                            // har i ke liye result 0 se start hoga
        for(int j = i; j < nums.size(); j++) {
            result |= nums[j];                     // ith to jth tak OR operation karte jao
            st.insert(result);                     // result ko set mein daal do (unique store hoga)
        }
    }

    cout << st.size() << endl;                     // unique OR values ki count print karo
}

int main()
{
    brute();
    return 0;
}
