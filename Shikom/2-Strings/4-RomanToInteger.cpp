class Solution {
public:

    // PROBLEM EXPLANATION:
    // ---------------------
    // Convert a Roman numeral string into an integer.
    //
    // Roman numerals use these symbols:
    // I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
    //
    // Normally: Add values → Example: VII = 5 + 1 + 1 = 7
    //
    // Special Rule (Subtraction Rule):
    // If a SMALLER value appears BEFORE a BIGGER value:
    // Subtract smaller from bigger → Example:
    // IV = 5 - 1 = 4
    // IX = 10 - 1 = 9
    // XL = 50 - 10 = 40
    //
    // We scan the string from left → right and:
    // If current value < next value → subtract
    // Else → add normally.

    int romanToInt(string s) {

        unordered_map<char, int> mp;  
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int sum = 0;

        for (int i = 0; i < s.size(); i++) {

            // CHECKING FOR SUBTRACTION CASE:
            // If the next Roman symbol exists AND
            // the current value is smaller than the next value,
            // it means we must subtract the current value.
            //
            // Example: "IV"
            // I = 1, V = 5 → 1 < 5 → subtract 1
            //
            // Example: "IX"
            // I = 1, X = 10 → 1 < 10 → subtract 1
            //
            // Example: "XL"
            // X = 10, L = 50 → 10 < 50 → subtract 10
            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
                sum -= mp[s[i]];
            }

            else {
                // Normal addition case:
                // Add when current value >= next value
                // Example: "VIII"
                // 5 + 1 + 1 + 1
                sum += mp[s[i]];
            }
        }

        return sum;
    }
};



class Solution:
    def romanToInt(self, s: str) -> int:

        # Roman values map
        mp = {}
        mp['I'] = 1
        mp['V'] = 5
        mp['X'] = 10
        mp['L'] = 50
        mp['C'] = 100
        mp['D'] = 500
        mp['M'] = 1000

        total = 0

        for i in range(len(s)):
            # Subtraction case: current value < next value
            if i + 1 < len(s) and mp[s[i]] < mp[s[i + 1]]:
                total -= mp[s[i]]
            
            # Normal addition case
            else:
                total += mp[s[i]]

        return total
