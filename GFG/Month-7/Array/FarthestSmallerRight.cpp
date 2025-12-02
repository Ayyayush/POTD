class Solution
{
public:
    vector<int> farMin(vector<int> &arr)
    {
        // code here
        vector<int> result(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = arr.size() - 1; j > i; j--)
            {
                if (arr[j] < arr[i])
                {
                    result[i] = j;
                    break;
                }
            }
        }

        return result;
    }
};


class Solution {
public:
    // Approach: Monotonic stack + Binary search
    // T.C. = O(n log n), S.C. = O(n)
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);

        // Step1: Build suffix minimum array
        vector<int> suffMin(n);
        suffMin[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffMin[i] = min(arr[i], suffMin[i+1]);
        }

        // Step2: For each i, binary search on suffixMin
        for(int i=0; i<n; i++) {
            int l=i+1, r=n-1, ans=-1;
            while(l<=r) {
                int mid = l + (r-l)/2;
                if(suffMin[mid] < arr[i]) {
                    ans = mid;       // store candidate
                    l = mid+1;       // try farther
                } else {
                    r = mid-1;
                }
            }
            result[i] = ans;
        }
        return result;
    }
};
