class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        int carry = 1;      // hum +1 kar rahe hain, toh shuru mein carry = 1

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;

            digits[i] = sum % 10;     // current digit update
            carry = sum / 10;         // next digit ke liye carry set

            if (carry == 0) break;    // agar carry 0 ho gaya toh aage kuch karne ki zarurat nahi
        }

        if (carry) {
            digits.insert(digits.begin(), carry);     // agar loop ke baad bhi carry bacha hai, toh usse front mein daalna padega
        }

        return digits;
    }
};