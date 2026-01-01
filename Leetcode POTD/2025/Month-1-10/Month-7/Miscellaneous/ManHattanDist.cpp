#include <bits/stdc++.h>           
using namespace std;                

#define endl '\n'                    // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long               // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;             // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1;     // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define u unordered_map<int, int>
#define FOR(i,n) for(int i = 0; i < n; i++)


// Manhattan Distance
void brute()
{
    // pehle  modx + mod y hoga starting mrin 


    // step 2
    // 0,0 se east hi jata rahega trobhb x axis pe +1 +1 hota rahega 
    // east aur west jaane se cancel bhi hoga '
    // toh horizontal mein net movement hoga abs of east - west
  //  net of east - west kr lenge 



  // same chiz vertical mein bhi check hoga 
  // ye y axis ke liye hoga 


  //total hovga vetical + horizontal 
    
}

class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;

        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;

            int currMD = abs(east-west) + abs(north-south);

            int steps  = i+1;
            int wasted = steps - currMD;

            int extra = 0;
            if(wasted != 0) { //steps != currMD
                extra = min(2*k, wasted);
            }

            int finalCurrentMD = currMD + extra;

            maxMD = max(maxMD, finalCurrentMD);
        }

        return maxMD;
    }
};




signed main()
{
    ios::sync_with_stdio(false);     // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);                   // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0;                        // Program successful terminate ho raha hai
}
