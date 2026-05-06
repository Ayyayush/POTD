class Solution {
public:
    int minOperations(int n) {
        int e = n / 2;
        return n & 1 ? (e + 1) * e : e * e;
    }
};