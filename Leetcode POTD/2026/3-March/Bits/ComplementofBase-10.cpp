class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;                         // special case: complement of 0 is 1
        
        int mask = 0;
        int temp = n;

        while(temp > 0)
        {
            mask = (mask << 1) | 1;                  // creating mask with all 1s equal to number of bits in n
            temp >>= 1;
        }

        return n ^ mask;                             // XOR with mask flips only significant bits
    }
};