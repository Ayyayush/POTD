// last moment before all ants fall out 
/**
 * GOOGLE
 * ek wooden plank diya h 
 * ek second mein ants 1 unit cover kr rhi h 
 * jab ants collide krti h toh dono apna direction interchange kr lete h 
 * direction change krne mein koi time nhi lagta
 * hume wo time btana h jab saare ants khtm ho jaye 
 * 
 * n=4 
 * left  = 4,3
 * right = 0,1
 * 
 * THOUGHT PROCESS
 * ----------------------------------
 * Jab 2 ants collide krti h, toh woh apna direction change krti h
 * Lekin agar hum carefully sochke dekhein:
 *      Agar ek ant left ja rahi h aur ek ant right — jab woh takraati hain,
 *      dono bas direction change karti hain, magar woh dikhne mein same lagta h
 * 
 *      Matlab: agar ek ant right ja rahi thi aur dusri left — after collision,
 *      woh just identities swap karti hain. Agar hum ants ke identity ignore karein,
 *      toh net result is same as if they **pass through each other**
 * 
 * So we can SIMULATE this as if they **never collide**
 * Har ant bas apne direction mein jaati h bina interruption ke.
 * 
 * 
 * OBSERVATION
 * ----------------------------------
 * Ants jo **left** direction mein hain:
 *      - They will fall off from left end (position 0)
 *      - Time = position (kitna distance hai 0 se)
 * 
 * Ants jo **right** direction mein hain:
 *      - They will fall off from right end (position = plankLength)
 *      - Time = (plankLength - position)
 * 
 * 
 * Conclusion
 * ----------------------------------
 * Har ant ke fall hone ka time calculate karo:
 *      - Left waali ke liye time = position
 *      - Right waali ke liye time = plankLength - position
 * 
 * Sabka maximum time lo — wahi h **last moment** jab last ant fall hoti h.
 * 
 * Example:
 * n = 4
 * plankLength = 4
 * left = [4, 3]
 * right = [0, 1]
 * 
 * Fall times:
 * - left: 4 (4→0), 3 (3→0)
 * - right: 4 (0→4), 3 (1→4)
 * 
 * Final answer = max(4,3,4,3) = 4 seconds
 * 
 */ 

 class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;      // yeh variable store karega max time, yaani last moment jab koi ant girti h

        // 👇 Left direction wali ants
        // Inhe girne mein 'x' seconds lagenge, kyunki woh left se 0 tak ja rahi hain
        for (int &x : left) {
            result = max(result, x);       // maximum time update karo
        }

        // 👇 Right direction wali ants
        // Yeh ants right end (n) pe girengi, toh unhe (n - x) seconds lagenge
        // Example: agar ant position 2 pe h aur plank 10 units ka h,
        // toh usko girne mein 10 - 2 = 8 seconds lagenge
        for (int &x : right) {
            result = max(result, n - x);   // max time update karo
        }

        return result;    // sabse last girne wali ant ka time return karo
    }
};

