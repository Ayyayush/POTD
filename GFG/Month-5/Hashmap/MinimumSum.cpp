/*
 * Examples :
 *
 * Input: arr[] = [6, 8, 4, 5, 2, 3]
 * Output: "604"
 * Explanation: The minimum sum is formed by numbers 358 and 246.
 *
 * Input: arr[] = [5, 3, 0, 7, 4]
 * Output: "82"
 * Explanation: The minimum sum is formed by numbers 35 and 047.
 *
 * Input: arr[] = [9, 4]
 * Output: "13"
 * Explanation: The minimum sum is formed by numbers 9 and 4.
 *
 * Constraints:
 * 2 ≤ arr.size() ≤ 10^6
 * 0 ≤ arr[i] ≤ 9
 */

/************************************************************ C++ ************************************************/



void naive() 
{
    // T.C. = O(N log N)       // sort kar rahe hain + ek loop
    // S.C. = O(1)             // extra space nahi use ho raha

    int n;                     // Number of digits
    cin >> n;

    vector<int> arr(n);        // Digits input ke liye
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long sumeven = 0, sumodd = 0;   // Do numbers banane ke liye

    sort(arr.begin(), arr.end());        // Digits ko chhote se bada sort karo

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sumeven = sumeven * 10 + arr[i];  // Even index pe pehla number banega
        } else {
            sumodd = sumodd * 10 + arr[i];   // Odd index pe doosra number banega
        }
    }

    long long sum = sumeven + sumodd;        // Dono ka sum nikalo

    cout << sum << endl;                      // String banana optional hai — GFG mein string hota hai
}


// Approach 1: Sort the array and distribute digits alternatively to form two numbers such that smaller digits come at higher places. Then, add the two numbers using string addition to avoid integer overflow.
// Time Complexity: O(n log n), due to sorting of the array.
// Space Complexity: O(n), for storing the two strings and the result.
class Solution {
public:

    // Helper function to add two numbers represented as strings
    string addString(string& s1, string& s2) {
        int    i      = s1.length() - 1; // pointer for s1
        int    j      = s2.length() - 1; // pointer for s2
        int    c      = 0;               // carry
        string result = "";              // to store result

        // Loop till both strings and carry are processed
        while (i >= 0 || j >= 0 || c > 0) {
            int sum = c;  // initialize with carry

            if (i >= 0) {
                sum += (s1[i] - '0');  // add digit from s1 if exists
            }

            if (j >= 0) {
                sum += (s2[j] - '0');  // add digit from s2 if exists
            }

            result.push_back(sum % 10 + '0'); // add current digit
            c = sum / 10;                     // update carry
            i--; j--;                         // move pointers
        }

        // Remove leading zeros from the end
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }

        // Reverse the result to get final number
        reverse(result.begin(), result.end());

        return result;
    }

    string minSum(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // sort digits in ascending order

        string s1 = "";               // to build first number
        string s2 = "";               // to build second number

        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                s1.push_back(arr[i] + '0');  // alternate digits go to s1
            } else {
                s2.push_back(arr[i] + '0');  // rest go to s2
            }
        }

        return addString(s1, s2);  // return their sum
    }
};

/*
 *
 * Dry Run
 * Input: arr[] = [6, 8, 4, 5, 2, 3]
 * Step 1: Sort the array → [2, 3, 4, 5, 6, 8]
 * Step 2: Distribute digits:
 *   s1 = "2", s2 = ""
 *   i=1 → s2 = "3"
 *   i=2 → s1 = "24"
 *   i=3 → s2 = "35"
 *   i=4 → s1 = "246"
 *   i=5 → s2 = "358"
 *
 * Final strings:
 *   s1 = "246", s2 = "358"
 *
 * Step 3: Add "246" + "358" using addString()
 *   6+8 = 14 → result = "4", carry = 1
 *   4+5+1 = 10 → result = "04", carry = 1
 *   2+3+1 = 6 → result = "604"
 * Final Answer: "604"
 */








// Approach 2: Count the frequency of digits using a frequency array. Then distribute the digits alternatively to two strings ensuring no leading zeros. Add the two numbers using string addition.
// Time Complexity: O(n + k), where n is the size of arr and k = 10 (fixed range of digits), sorting is not needed.
// Space Complexity: O(n), for storing the result strings.
class Solution {
public:

    // Helper function to add two numbers represented as strings
    string addString(string& s1, string& s2) {
        int    i      = s1.length() - 1;
        int    j      = s2.length() - 1;
        int    c      = 0;
        string result = "";

        while (i >= 0 || j >= 0 || c > 0) {
            int sum = c;

            if (i >= 0) {
                sum += (s1[i] - '0');
            }
            if (j >= 0) {
                sum += (s2[j] - '0');
            }

            result.push_back(sum % 10 + '0');
            c = sum / 10;
            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string minSum(vector<int>& arr) {
        vector<int> count(10, 0); // count array for digits 0–9

        for (int num : arr) {
            count[num]++;
        }

        string s1   = "";
        string s2   = "";
        bool   flag = true; // true -> insert in s1, false -> s2

        for (int digit = 0; digit < 10; digit++) {
            while (count[digit]--) {
                if (flag) {
                    if (!(s1.empty() && digit == 0)) {
                        s1.push_back(digit + '0'); // avoid leading 0
                    }
                    flag = false;
                } else {
                    if (!(s2.empty() && digit == 0)) {
                        s2.push_back(digit + '0');
                    }
                    flag = true;
                }
            }
        }

        return addString(s1, s2);
    }
};

/*
 *
 * Dry Run
 * Input: arr = [2, 0, 1, 2, 0, 1]
 * Step 1: Count = [2, 2, 2, 0, 0, 0, 0, 0, 0, 0]
 *
 * Step 2: Start distributing digits using flag:
 * digit = 0 → count = 2
 *   → s1 empty, skip leading 0
 *   → s2 empty, skip leading 0
 *
 * digit = 1 → count = 2
 *   → s1 = "1", flag = false
 *   → s2 = "1", flag = true
 *
 * digit = 2 → count = 2
 *   → s1 = "12", flag = false
 *   → s2 = "12", flag = true
 *
 * Final s1 = "12", s2 = "12"
 * Add: 12 + 12 = "24"
 *
 * Output: "24"
 */






 