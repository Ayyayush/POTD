class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;   // edge case

        string s = "";

        // ! Convert to BINARY (fix: use %2 not %10)
        while (n) {
            int rem = n % 2;
            s += to_string(rem);
            n /= 2;
        }

        reverse(s.begin(), s.end());   // ! fix order

        // ! flip bits
        for (int i = 0; i < s.size(); i++) {
            s[i] = (s[i] == '0') ? '1' : '0';
        }

        // ! convert binary string to decimal
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum = sum * 2 + (s[i] - '0');
        }

        return sum;
    }
};




/******************************************************* C++ *******************************************************/
//Approach-1
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        
        int result = 0;
        int counter = 0;
        while(n) {
            int r = n%2;
            result += (pow(2,counter)*!r);
            counter++;
            n = n>>1;
        }
        return result;
    }
};

//Approach-2
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int mask = 1;

        while (mask < n) {
            mask = (mask << 1) | 1;  // builds 111...1
        }
        
        return n ^ mask;
    }
};


//Approach-3
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int bits = floor(log2(n)) + 1;  // number of bits
        int mask = (1 << bits) - 1;     // 2^bits - 1 = 111...1

        return n ^ mask;
    }
};


