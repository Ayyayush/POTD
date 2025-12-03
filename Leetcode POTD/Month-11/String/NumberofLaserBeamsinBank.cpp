#include <bits/stdc++.h>
using namespace std;

/***
 * ! Problem: Number of Laser Beams in a Bank
 * ! Company: Amazon
 *
 * 🏦 Story Explanation (Hinglish):
 * Ek bank hai jisme har floor pe security devices lage hue hain.
 * Har floor ko ek binary string ke form me diya gaya hai jahan:
 *   - '1' ka matlab hai ek security device
 *   - '0' ka matlab hai koi device nahi
 *
 * Laser beams tabhi banti hain jab:
 *   - Do consecutive floors me devices ho (matlab dono rows me '1' hon)
 *   - Beech me agar koi empty row (all zeros) aaye toh beam break ho jaati hai
 *
 * Har device ek beam banata hai dusre floor ke har device ke saath.
 * Isiliye agar ek floor me `a` devices aur next me `b` devices hain,
 * toh total beams = a × b
 *
 * Hume total beams ka sum nikalna hai.
 *
 * 📘 Formula:
 * Total Beams = Σ (devices[i] * devices[i+1]) for consecutive non-empty rows
 *
 *
 * 🧩 Example 1:
 * bank = ["011001","000000","010100","001000"]
 *
 * Step 1️⃣: Har row me kitne devices hain:
 *   Row 0 → "011001" → 3 devices
 *   Row 1 → "000000" → 0 devices
 *   Row 2 → "010100" → 2 devices
 *   Row 3 → "001000" → 1 device
 *
 * Step 2️⃣: Consecutive non-empty rows identify karo:
 *   (Row0, Row2) → 3 * 2 = 6 beams
 *   (Row2, Row3) → 2 * 1 = 2 beams
 *
 * ✅ Total Beams = 6 + 2 = 8
 *
 *
 * 🧩 Example 2:
 * bank = ["000","111","000"]
 * Devices = [0, 3, 0]
 * Sirf ek non-empty row hai (middle one)
 * ✅ Output = 0
 *
 *
 * 🧠 Approach:
 * - Har row me 1s count karenge.
 * - Consecutive non-zero rows ka product add karte jayenge.
 * - Jab bhi ek empty row milti hai, beam connection break ho jata hai.
 *
 * 🔹 Time Complexity:  O(m * n)     → (m rows × n columns)
 * 🔹 Space Complexity: O(1)         → sirf few variables use hue hain
 */

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;                // pichle non-empty floor ke devices count
        int totalBeams = 0;          // total beams store karne ke liye

        for (auto &row : bank) {     // har floor ke liye iterate karenge
            int curr = count(row.begin(), row.end(), '1');   // current floor me kitne '1' hain

            if (curr > 0) {          // agar current floor pe koi device hai
                totalBeams += prev * curr;    // beams = prev floor ke devices * curr floor ke devices
                prev = curr;                  // current ko next iteration ke liye prev bana do
            }
        }
        return totalBeams;           // total beams return karo
    }
};


/**
 * ✅ Dry Run (Detailed):
 *
 * Input:
 * bank = ["011001","000000","010100","001000"]
 *
 * Step-by-step:
 * prev = 0, totalBeams = 0
 *
 * Row 0: "011001"
 * → curr = 3
 * → totalBeams += 0 * 3 = 0
 * → prev = 3
 *
 * Row 1: "000000"
 * → curr = 0 → skip (no devices)
 *
 * Row 2: "010100"
 * → curr = 2
 * → totalBeams += 3 * 2 = 6
 * → prev = 2
 *
 * Row 3: "001000"
 * → curr = 1
 * → totalBeams += 2 * 1 = 2
 * → prev = 1
 *
 * ✅ Final Answer = 6 + 2 = 8
 */
