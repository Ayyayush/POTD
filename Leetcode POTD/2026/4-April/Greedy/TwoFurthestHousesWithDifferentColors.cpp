/*
Leetcode 2078
*/

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    result = max(result, j - i);
                }
            }
        }
        return result;
    }
};


//Approach-2 (Improved Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j > i; j--) {
                if (colors[i] != colors[j]) {
                    result = max(result, j - i);
                    break;
                }
            }
        }
        return result;
    }
};


//Approach-3 (HashMap Based)
//T.C : O(n * k)  ≈ O(n^2) in worst case
//S.C : O(k) ≈ O(n)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size(),maxDist=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(auto it:mp)
            {
                if(it.first!=colors[i])
                maxDist=max(maxDist,abs(it.second-i));
            }
            if(mp.count(colors[i])==0)
                mp[colors[i]]=i;
        }
        return maxDist;
    }
};


//Approach-4 (2 Pass Solution)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int result = 0;

        int i = 0;
        while(colors[i] == colors[n-1]) i++;

        result = max(result, abs(i - (n-1)));

        i = n-1;
        while(colors[0] == colors[i]) i--;

        result = max(result, i);

        return result;
    }
};


//Approach-5 (1 Pass Solution)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int result = 0;

        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[0]) {
                result = max(result, i);
            }

            if(colors[i] != colors[n-1]) {
                result = max(result, abs(i - (n-1)));
            }
        }

        return result;
    }
};