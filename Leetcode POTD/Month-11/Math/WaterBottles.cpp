/**
 * 🧴 PROBLEM: WATER BOTTLES
 * ---------------------------------------------------------
 * You are given:
 *   ➤ numBottles  → Total full water bottles you initially have.
 *   ➤ numExchange → Number of empty bottles required to get 1 new full bottle.
 * 
 * TASK:
 *   ➤ Return the maximum number of water bottles you can drink.
 * 
 * ---------------------------------------------------------
 * 🔸 EXAMPLE 1:
 * numBottles = 9
 * numExchange = 3
 * 
 * Step-by-step:
 *  1️⃣ You drink 9 bottles → 9 empty bottles bache.
 *  2️⃣ Exchange 3 empties → get 1 new bottle (3 empties used)
 *     Now: 9/3 = 3 new full bottles.
 *  3️⃣ Total bottles drunk so far = 9 + 3 = 12
 *  4️⃣ Ab 3 empties → 3/3 = 1 new bottle.
 *  5️⃣ Total drunk = 12 + 1 = 13
 *  ✅ FINAL ANSWER = 13
 * 
 * ---------------------------------------------------------
 * 🔸 EXAMPLE 2:
 * numBottles = 15
 * numExchange = 4
 * 
 * Step-by-step:
 *  1️⃣ Drink 15 → 15 empties.
 *  2️⃣ Exchange 4→ get 3 full bottles (15/4 = 3)
 *     Remainder = 15 % 4 = 3 empties.
 *  3️⃣ Total drunk = 15 + 3 = 18
 *  4️⃣ Ab empties = 3 (remainder) + 3 (new empty bottles after drinking) = 6
 *  5️⃣ 6/4 = 1 more bottle → remainder = 2
 *  6️⃣ Total drunk = 18 + 1 = 19
 *  7️⃣ Ab empties = 2 (remainder) + 1 (new empty) = 3 → can’t exchange anymore
 *  ✅ FINAL ANSWER = 19
 * 
 * ---------------------------------------------------------
 * ⚙️ APPROACH 1 (Simulation / While Loop)
 * ---------------------------------------------------------
 * IDEA:
 *   - Jab tak numBottles >= numExchange hota hai,
 *     hum exchange karte rahenge aur count badhate rahenge.
 * 
 * STEPS:
 *   1️⃣ Start with `drank = numBottles`
 *   2️⃣ Jab tak `numBottles >= numExchange`
 *         ➤ exchanged = numBottles / numExchange
 *         ➤ remainder = numBottles % numExchange
 *         ➤ drank += exchanged
 *         ➤ numBottles = exchanged + remainder
 *   3️⃣ Return drank
 * 
 * ---------------------------------------------------------
 * 🧩 APPROACH 1 CODE (Optimal Simulation)
 * ---------------------------------------------------------
 */
#include <bits/stdc++.h>
using namespace std;

void optimal() {
    int numBottles, numExchange;
    cout << "Enter total bottles and exchange rate: ";
    cin >> numBottles >> numExchange;

    int drank = numBottles;                     // Initially drink all
    int empty = numBottles;                     // All bottles are now empty

    while (empty >= numExchange) {               // Jab tak exchange possible ho
        int exchanged = empty / numExchange;     // New full bottles
        int remainder = empty % numExchange;     // Remaining empties
        drank += exchanged;                      // Add new bottles to total drunk
        empty = exchanged + remainder;           // Update empties
    }

    cout << "Maximum bottles you can drink: " << drank << endl;
}

/**
 * ---------------------------------------------------------
 * ⚙️ APPROACH 2 (Mathematical Thought)
 * ---------------------------------------------------------
 * IDEA:
 *   - Direct simulation ke jaisa hi hai, bas clearly
 *     empty bottles track karte rahenge.
 * 
 * STEPS:
 *   1️⃣ consumed = numBottles
 *   2️⃣ empty = numBottles
 *   3️⃣ Jab tak empty >= numExchange:
 *         ➤ newBottles = empty / numExchange
 *         ➤ consumed += newBottles
 *         ➤ empty = (empty % numExchange) + newBottles
 *   4️⃣ Return consumed
 * 
 * ---------------------------------------------------------
 * 🧩 APPROACH 2 CODE
 * ---------------------------------------------------------
 */

void better() {
    int numBottles, numExchange;
    cout << "Enter total bottles and exchange rate: ";
    cin >> numBottles >> numExchange;

    int consumed = numBottles;                   // Start with initial bottles
    int empty = numBottles;                      // Initially, all become empty

    while (empty >= numExchange) {                // Jab tak exchange possible
        int extra = empty / numExchange;          // Naye bottles mile
        int remainder = empty % numExchange;      // Bach gaye empty
        consumed += extra;                        // Total bottles drunk
        empty = extra + remainder;                // Update empties
    }

    cout << "Total bottles you can drink: " << consumed << endl;
}

/**
 * ---------------------------------------------------------
 * 🕒 TIME COMPLEXITY: O(log n)
 * Because each time bottles decrease by a factor of numExchange.
 *
 * 💾 SPACE COMPLEXITY: O(1)
 * Constant extra space used.
 * ---------------------------------------------------------
 */

int main() {
    optimal();
    return 0;
}



/**
 * Approach 3 
 * maan lo numb=15  nume=4
 * 4 peete hi  15-4 +1  ho rha h ==12 
 * isko directly kr skte h 
 * 15- (numexchange) +1 == 15-(numexchange-1)
 */
