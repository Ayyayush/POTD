/**
 * Minimum Number of People to Teach
 * 
 * Problem Explanation 💡:
 * ------------------------
 * - Tumhe 'n' number of people diye gaye hain (1 to n tak numbered).
 * - Har person ek ya zyada languages bol sakta hai (languages 1 to m tak hoti hain).
 * - Tumhe friendships di gayi hain jahan har pair (u, v) ek friendship represent karta hai.
 * 
 * Objective 🎯:
 * -------------
 * - Agar do friends ek common language share nahi karte, to wo communicate nahi kar sakte.
 * - Tumhe minimum number of people ko **ek hi language** sikhani hai taaki **sab friends** communicate kar sakein.
 * - Ek language choose karni hai aur kuch logon ko wo sikhani hai, taaki har friendship pair ke beech communication possible ho jaaye.
 * 
 * 
 * 
 * 
 * 
 * Example 🧩:
 * -----------
 * n = 3
 * languages = [[2], [1,3], [1,2]]
 * friendships = [[1,2], [1,3], [2,3]]
 * 
 * Person 1 -> {2}
 * Person 2 -> {1,3}
 * Person 3 -> {1,2}
 * 
 * Friendship checks:
 * (1,2): No common ❌
 * (1,3): Common = 2 ✅
 * (2,3): Common = 1 ✅
 * 
 * Sirf (1,2) fail hoga → sad users = {1,2}
 * 
 * Sad users ka language count:
 * User 1: {2}
 * User 2: {1,3}
 * 
 * Count table:
 * lang1 → 1 user
 * lang2 → 1 user
 * lang3 → 1 user
 * 
 * Max known language = 1 (koi bhi ek language 1 sad user jaanta hai)
 * Sad users = 2  
 * Minimum to teach = 2 - 1 = 1 ✅
 * 
 * 
 * DRY RUN TRACE 🏃‍♂️💨
 * ---------------------
 * languages:
 * index: 0   1       2
 * user:  1   2       3
 * data: {2}, {1,3}, {1,2}
 * 
 * friendships = (1,2), (1,3), (2,3)
 * 
 * Loop 1 → (1,2)
 * u = 0 → has {2}
 * v = 1 → has {1,3}
 * common? ❌ → sadUsers = {0,1}
 * 
 * Loop 2 → (1,3)
 * u = 0 → {2}
 * v = 2 → {1,2}
 * common? ✅ 
 * 
 * Loop 3 → (2,3)
 * u = 1 → {1,3}
 * v = 2 → {1,2}
 * common? ✅
 * 
 * sadUsers = {0,1}
 * 
 * language freq count among sad users:
 * user 0: {2} → lang2++
 * user 1: {1,3} → lang1++, lang3++
 * 
 * freq: lang1=1, lang2=1, lang3=1
 * mostKnownLang = 1
 * 
 * result = sadUsers(2) - mostKnownLang(1) = 1 ✅
 * 
 * 
 * Approach Notes:
 * ---------------
 * Bas un logon pe focus karo jo baat nahi kar sakte.
 * Fir unme se kaunsi language maximum log already jaante hain, woh dhoondo.
 
 * 
 * So only (1,2) friendship fails.
 * Agar hum **language 1** choose karein, aur person 1 ko language 1 sikhayein,
 * to sab communicate kar paayenge.
 * 
 * Answer = 1 (minimum number of people to teach)
 * 
 * Intuition 🧠:
 * -------------
 * - Har friendship check karo — jahan common language nahi hai, un dono friends me se
 *   kisi ek ko teach karna padega.
 * - Tumhe decide karna hai kaunsi language teach karni chahiye jisse sabse kam log
 *   sikhane padein.
 * 
 * Approach Overview 🔍:
 * ----------------------
 * 1️⃣ Identify all friendships jahan communication possible nahi hai.
 * 2️⃣ Un friendships ke logon ka set lo — unme se hi logon ko teach karna padega.
 * 3️⃣ Har language ke liye count karo ki unme se kitne log already wo language jaante hain.
 * 4️⃣ Sabse zyada overlap wali language choose karo (taaki kam se kam naye log ko sikhana pade).
 * 5️⃣ Minimum number of people to teach = total affected - max overlap.
 * 
 * 
 * 
 * 
 * 
 * ! Approach 
 * Ab dekho hamara main goal h ki sab baat kr paye 
 * dekh lo pehle toh ki kaun kaun baat kr pa rha h 
 * agar koi friends aapas mein baat nhi kar pa rhe toh wo sad h 
 * Hume unhe happy krna h 
 * ab pehle toh friendships mein har ek vector nikalo 
 * aur uss vector ko 0 based indexing mein convert karo 
 * 
 * 
 */



 //T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        // unordered_set banaya to track un users ko jo baat nahi kar sakte (sad users)
        unordered_set<int> sadUsers;

        // har friendship pair ke liye loop
        for(auto &friends : friendships) {
            int u = friends[0] - 1; // 0-based index mein convert kiya kyunki arrays 0 se start hote hain
            int v = friends[1] - 1;

            // languages[u] ki sari languages ek set mein store kar rahe
            // taki O(1) time mein check ho jaye ki koi language match karti hai ya nahi
            unordered_set<int> langSet(begin(languages[u]), end(languages[u]));

            bool canTalk = false; // assume ki initially baat nahi kar sakte

            // check karte hain ki v user ki koi language u user ke languages set mein hai kya
            for(int lang : languages[v]) {
                if(langSet.count(lang)) { // agar mila matlab baat kar sakte
                    canTalk = true;
                    break; // ek match mil gaya means baaki check karne ki zarurat nahi
                }
            }

            // agar baat nahi kar sakte toh inhe sadUsers list me daal do
            if(!canTalk) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        // ab sad users ko dekho aur pata karo sabse zyada konse language users already jante hain
        // n+1 size kyunki language indexing 1 se hoti hai
        vector<int> language(n+1, 0); 
        int mostKnownLang = 0; // store karega ki kis language ko maximum sad users already jante hain

        // har sad user ke liye
        for(int user : sadUsers) {
            // user ki har language count badha rahe
            for(int lang : languages[user]) {
                language[lang]++; // is language ko ek aur user janta hai
                mostKnownLang = max(mostKnownLang, language[lang]); // maximum track karte raho
            }
        }

        // answer hai -> total sad users - unme se kitne already ek common language jante hain
        // kyunki unhe sikhane ki zarurat nahi padegi
        return sadUsers.size() - mostKnownLang;
        
    }
};
