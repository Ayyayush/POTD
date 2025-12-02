/**
 * 2 arrays diye h
 * 
 * ek positive integer add krna hgiven index mein num2 mein 
 * 
 */
class FindSumPairs {
public:
    vector<int> nums1, nums2;					// Store input vectors as class members

    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
    }

    void add(int index, int val) {
        nums2[index] += val;					// Add value at given index of nums2
    }

    int count(int tot) {
        int count = 0;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] + nums2[j] == tot) {
                    count++;
                }
            }
        }

        return count;							// RETURN MISSING IN YOUR CODE
    }
};


//Approach (Using map and approach similar to Two Sum Problem)
//T.C : O(m+n) for FindSumPairs(), O(1) for add() and O(n) for count()
//S.C : O(m+n) for vec1 and vec2
class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int &x : vec2) {
            mp[x]++;
        }
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int &x : vec1) {
            c += mp[tot-x];
        }

        return c;
    }
};



