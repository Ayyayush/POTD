
class Solution {
public:
    int divide(int dividend, int divisor) {

        // Edge Case: INT_MIN / -1 causes overflow
        if (dividend == INT_MIN && divisor == -1) 
        {
            return INT_MAX;  
        }
         if (dividend == INT_MIN && divisor == 1) 
        {
            return INT_MIN;  
        }


        // Determine sign of result
        bool isNegative = (dividend < 0) ^ (divisor < 0);  

        // Convert to long long BEFORE taking absolute value
        long long num = abs((long long)dividend);  
        long long den = abs((long long)divisor);

        int quotient = 0;

        // Try shifting divisor up to max 31 bits
        for (int i = 31; i >= 0; i--) 
        {
            if ((num >> i) >= den)   // Check if (divisor << i) fits in dividend
            {
                num -= (den << i);  // Subtract that portion
                quotient += (1 << i); // Add corresponding power to quotient
            }
        }

        return isNegative ? -quotient : quotient;  // Apply negative sign if needed
    }
};