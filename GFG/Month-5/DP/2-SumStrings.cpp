
class Solution {
public:

    // String based addition (do strings ko number treat karke add karna)
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';   // num1 ka digit add karo
            if (j >= 0) sum += num2[j--] - '0';   // num2 ka digit add karo

            carry = sum / 10;                     // carry update karo
            result += (sum % 10 + '0');           // current digit result mein dalo
        }

        reverse(result.begin(), result.end());    // reverse karke final answer banao
        return result;
    }

    // Recursive function to check pattern match
    bool checkSequence(string &s, int start, int len1, int len2) {
        string part1 = s.substr(start, len1);                      // pehla number
        string part2 = s.substr(start + len1, len2);               // dusra number
        string sumPart = addStrings(part1, part2);                 // sum nikaalna

        int len3 = sumPart.length();

        // Agar remaining string mein space nahi bacha toh false
        if (start + len1 + len2 + len3 > s.length()) {
            return false;
        }

        // Teesre part se match karna chahiye
        if (sumPart == s.substr(start + len1 + len2, len3)) {
            // Agar string yahin khatam ho gayi toh valid hai
            if (start + len1 + len2 + len3 == s.length()) {
                return true;
            }

            // warna aage ke liye recursive check karo
            return checkSequence(s, start + len1, len2, len3);
        }

        return false;  // match nahi hua toh
    }

    bool isSumString(string &s) {
        int n = s.length();

        // Pehle number ka length fix karo, doosre ka vary karo
        for (int len1 = 1; len1 < n; len1++) {
            for (int len2 = 1; len1 + len2 < n; len2++) {
                if (checkSequence(s, 0, len1, len2)) {
                    return true;
                }
            }
        }

        return false;  // koi bhi valid combination nahi mila
    }
};
