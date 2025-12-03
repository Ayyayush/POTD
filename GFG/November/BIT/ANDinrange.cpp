class Solution {
  public:
    int andInRange(int l, int r) {
        // If both numbers are same, AND of range is the number itself
        int shift = 0;
        
        // Keep removing differing rightmost bits
        while(l < r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }
        
        // Shift back to restore common prefix
        return l << shift;
    }
};
