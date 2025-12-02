#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

// ------------------------------------------------------------
// Time Complexity: O(n^2)                // har '*' ke liye loop chalta hai + erase bhi O(n) hota hai
// Space Complexity: O(1)                 // koi extra data structure use nahi ho raha
void brute()
{
    string s;
    cin >> s;

    size_t index = s.find('*');   // Pehle '*' ka index dhoondho
    while (index != string::npos) // Jab tak koi '*' bacha hai
    {
        s.erase(index, 1); // '*' ko hata do

        char minchar = '{'; // '{' ascii mein 'z'+1 hota hai, smallest character dhoondhne ke liye initial value
        int minindex;

        for (int i = index - 1; i >= 0; i--) // '*' ke pehle ka sabse chhota character dhoondho
        {
            if (s[i] < minchar)
            {
                minchar = s[i]; // smallest character update karo
                minindex = i;   // uska index bhi save karo
            }
        }

        s.erase(minindex, 1); // us smallest character ko bhi hata do

        index = s.find('*'); // dubara check karo koi aur '*' bacha hai ya nahi
    }

    cout << s << endl; // final string print karo
}

// ------------------------------------------------------------
// Time Complexity: O(n^2) (worst case)        // '*' ke andar loop + erase har baar O(n) lagta hai
// Space Complexity: O(1)                      // koi extra structure use nahi ho raha
void better()
{
    string s;
    cin >> s;

    size_t index = s.find('*'); // Pehle '*' ka index dhoondho

    if (index != string::npos)
    {
        char minchar = '{';             // smallest character track karne ke liye
        int minindex = -1;              // fix: garbage value hata ke -1 se initialize karo

        for (int i = index ; i >= 0; i--) // '*' ke pehle backward jao
        {
            if (s[i] == '*')           // agar nested '*' mila
            {
                s.erase(i, 1);         // us '*' ko hata do
                i--;

                minchar = '{';         // har nayi baar ke liye reset karo
                minindex = -1;

                while (i >= 0 && s[i] != '*') // tab tak chhoti char dhoondo jab tak dusra '*' na mile
                {
                    if (s[i] < minchar)     // chhoti character mila?
                    {
                        minchar = s[i];
                        minindex = i;
                    }
                    i--;
                }

                if (minindex != -1)         // ensure ki valid character mila ho
                    s.erase(minindex, 1);   // sabse chhoti character hata do
            }
        }
    }

    cout << s << endl;
}

// ------------------------------------------------------------
// Time Complexity: O(n log n)                     // Heap operations O(log n), n times worst case
// Space Complexity: O(n)                          // Heap mein characters ke index ke saath store karne hain
void optimal()
{
    string s;
    cin >> s;

    // Custom min heap banayenge jisme pair hoga <char, index>
    // taaki smallest character easily mile aur index track ho jaye
    // Heap ke top se smallest character ko pop karenge jab '*' mile

    // Step 1: Push sab characters with unvisited '*' ke pehle waale indexes into min heap
    // Step 2: Jab '*' mile to heap ka top pop karo (smallest char remove karne ke liye)
    // Step 3: Mark '*' positions as removed logically, actual string se erase nahi karenge (index maintain rakhne ke liye)
    // Step 4: Last mein string ke non-'*' aur unremoved characters print karenge

    // Heap data structure ka use kar rahe hain:
    // Priority queue with comparison based on character to get smallest char quickly

    // Dry run example: s = "aba*"
    // heap me push karenge (a,0), (b,1), (a,2)
    // '*' milte hi top (smallest) character ko remove karenge, wo 'a' (index 0) hoga
    // finally string se '*' and removed chars hata kar result print karenge


    /*
    Detailed Dry Run Example:

    Input: s = "aaba*"

    Initial string indices:  0:'a', 1:'a', 2:'b', 3:'a', 4:'*'
    
    Step 1: Push characters in heap except '*'
        Heap contains: (a,0), (a,1), (b,2), (a,3)
        Since it's min-heap by character, smallest 'a' on top

    Step 2: Traverse string
        i=0: 'a' -> ignore
        i=1: 'a' -> ignore
        i=2: 'b' -> ignore
        i=3: 'a' -> ignore
        i=4: '*' found
            - Pop from heap top: (a,0)
            - Mark removed[0] = true (remove 'a' at index 0)
            - Mark removed[4] = true (remove '*')
    
    Step 3: Print all characters where removed[i] == false
        removed = [true, false, false, false, true]
        So print characters at indices 1:'a', 2:'b', 3:'a'
        Output: "aba"

    Final answer after removing '*' and smallest char before '*': "aba"
    */

    typedef pair<char, int> P;

    struct comp {
        bool operator()(P &p1, P &p2) {
            if (p1.first == p2.first)
                return p1.second < p2.second;     // lexically same char toh jo aage aaya ho usko pehle nikalo
            return p1.first > p2.first;           // min heap based on character
        }
    };

    int n = s.length();                       
    priority_queue<P, vector<P>, comp> pq;    
    vector<bool> removed(n, false);           // kaunse character remove hue unka track rakhna

    for (int i = 0; i < n; i++) {
        if (s[i] != '*') {
            pq.push({s[i], i});
        } else {
            if (!pq.empty()) {
                int idx = pq.top().second;
                pq.pop();
                removed[idx] = true;          // smallest character mark as removed
            }
            removed[i] = true;                // '*' bhi remove
        }
    }

    for (int i = 0; i < n; i++) {
        if (!removed[i]) cout << s[i];        // sirf valid characters print karo
    }

    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    optimal();  // ya brute(), better() call kar sakte ho test ke liye

    return 0;
}
