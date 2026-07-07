class Solution {
public:
    long long sumAndMultiply(int n) {

        string s = to_string(n);

        string ans = "";
        long long sum = 0;

        // Build number without zeros and compute digit sum
        for (char ch : s) {
            if (ch != '0') {
                ans += ch;
                sum += (ch - '0');
            }
        }

        // Convert remaining digits into a number
        long long num = stoll(ans);

        // Return product
        return num * sum;
    }
};


class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0, sum = 0;
        long long place = 1;

        while (n) {
            int rem = n % 10;

            if (rem != 0) {
                num += rem * place;    // Build number in correct order
                sum += rem;            // Add digit to sum
                place *= 10;
            }

            n /= 10;
        }

        return num * sum;
    }
};