GFG/November/Graph/MaxNoOfkDivItems.cppclass Solution {
public:
    vector<int> subsetXOR(int n) {

        // Step 1: compute XOR of all numbers from 1 to n
        int xr = 0;
        for(int i = 1; i <= n; i++) xr ^= i;

        int need = xr ^ n;   // value that must be removed xor-wise

        vector<int> ans;

        // Case 1: XOR(all) == n → take all numbers
        if(need == 0){
            for(int i = 1; i <= n; i++) ans.push_back(i);
            return ans;
        }

        // Case 2: removing one element = possible
        if(need >= 1 && need <= n){
            for(int i = 1; i <= n; i++){
                if(i != need) ans.push_back(i);
            }
            return ans;
        }

        // Case 3: need > n → remove a pair (a,b) such that a^b = need
        int a = -1, b = -1;
        for(int x = 1; x <= n; x++){
            int y = x ^ need;   // candidate second number
            if(y >= 1 && y <= n && y != x){
                a = x;
                b = y;
                break;
            }
        }

        // remove the found pair
        for(int i = 1; i <= n; i++){
            if(i != a && i != b) ans.push_back(i);
        }

        return ans;
    }
};
