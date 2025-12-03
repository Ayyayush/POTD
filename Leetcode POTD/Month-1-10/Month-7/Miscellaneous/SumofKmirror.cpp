#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define u unordered_map<int, int>
#define FOR(i, n) for (int i = 0; i < n; i++)

// sum of k mirror numbers
void brute()
{
    /**
     * aise numbers jo base 10 mein bhi palin ho 
     * aur given base jisme nikalna h usme bhi palindrome ho
     * eg:: k=2 n=5 toh 2 base mein bhi palin wale min 5 numbers nikalo 
     * i.e:: 1,3,5,7,9
     * 
     *  specific number ko uss base mein convert krne ke liye uss number se divide krte jao 
     * pehle check karo ki number palindorme h ya nhi 
     * agar h tab base mein convert kakre dekho 
     * aagr base mein convert krke bhi palin aaya toh next pe jao aur pehle uss number ko sum mein add karo
     * brute force mein dikkat ye h ki bade numbers mein problem hogi 
     * aur aise 2 numbers ke beech bhot gap ho skta h 
     * eg::17th number 6958596   isko nikaalne ke liye beech mnein kitna check kiya hoga 
     */

    int k, n;                    // Base aur count input lo
    cin >> k >> n;

    vector<int> result;          /* Palindromic numbers collect karne ke liye */
    int i = 0;                   /* Number start karo */

    while (result.size() < n) {  /* Jab tak n numbers nahi ho jaate */
        i++;
        int currnum = i;

        /* Base k mein convert karo bina alphabet ke */
        vector<string> digits;

        while (currnum > 0) {
            int rem = currnum % k;                      /* Remainder nikalo */
            digits.push_back(to_string(rem));           /* String mein numeric add karo */
            currnum /= k;                               /* Number ko base se divide karo */
        }

        /* Digits reverse karke base k number banao */
        string res = "";
        for (int j = digits.size() - 1; j >= 0; j--) {
            res += digits[j];
        }

        /* Check karo kya ye base k representation palindromic hai AND decimal mein bhi */
        string dec = to_string(i);
        string rev_dec = dec; reverse(rev_dec.begin(), rev_dec.end());
        string rev_res = res; reverse(rev_res.begin(), rev_res.end());

        if (res == rev_res && dec == rev_dec) {
            result.push_back(i);
        }
    }

    /* Final sum of first n k-mirror numbers */
    long long sum = 0;
    for (auto x : result) sum += x;

    cout << sum << endl;         /* Answer print karo */
}


void better()
{
    /**
     * isme hum khud se palindrome number banayenge 
     * jaise 12 h toh 21 jodd de piche se toh palindrome 
     *so we need to know how to generating palindromes  
     *
     */


     // Generating Palindroes
     /**
      * 1 digit wale toh saare palindromes h 
      * lengthwise palindorme dhundne se faayda h
      * 
      * even length 
      * eg 4 length ke palindormes ke liye ...
      * 2 dgit ke palin nikaal ke usko reverse krke append kar do 
      * so jis lenght ka chaiye uska half krke unn numbers ko append krke dekhe 
      * even length ka plaindorme generate krna easy h 
      * bcz len/2 numbers ke saare digit nikaal ke append kar ke dekho 
      * 
      * odd length 
      * isme left ka reverse hoga right mein beech mein mid hoga 
      * agar l odd h toh (len+1/2) ke saare numbers lo 
      * len ==7   (len+1/2)  se mila 4 
      * ab 4 digit waalo se 7 digit ka palindorme bnana h 
      * eg 1234   isko reverse karo 4321
      * reverse number mein pehle ko ignore karo baaki ko apkend karo do 
      * 1234321   toh mil gya palindrome 
      * 
      *  Note:: (Len+1)/2  ye odd or even dono ke liye correct hi dega  
      */


      /**
       * ab agar palindrome ban gya toh uska base case mein convert krke dekho
       * agar uss base mein bhi palin h toh add kar do 
       * ab maan lo half len 2 h toh 2 digit ke saare numbers check krne h
       * range 10-99
       * half len-3   range 100-999 
       * 
       * half len h toh uss range ka minimum number hoga
       * Formula for min ==  10^(half-len-1)
       * prove 10^(2-1) ==  10   minimum of len-2 range ==10
       * Formula for max ==  10^(half-len)-1
       *  prove 10^(2)-1 ==  99  maximum of len-2 range ==99
       * long long mein lenge dono ko 
       * half -len ka min-m,ax nkaalna aa gya toh ussi range mein check karenge 
       * 
       * ab min max ko stirng mein convert kar lo 
       * for(num==min_num ;num<=maxnum;num++)
       * {
       * ab odd ya even len ke according num ko reverse krke append karenge 
       * first half== to_stirng (num);
       * second_half== first_half 
       * reverse karo second half ko 
       * if(len==odd)
       * {
       * first_half+ second_half.susbtr(1)     // pehla digit chor rhe h reversed ka 
       * }
       * else
       * {
       * first_half+second_half
       * }
       * 
       * }
       */
      

  
    long long kMirror(int k, int n) 
    {
        long long sum = 0;
        int len = 1;                          // Length of decimal palindrome

        while (n > 0) 
        {
            int half_len = (len + 1) / 2;     // 'half_len' sahi naam rakho
            long long min_num = pow(10, half_len - 1);  
            long long max_num = pow(10, half_len) - 1;

            for (long long num = min_num; num <= max_num; num++) 
            {
                string first_half = to_string(num);      // 'to_String' galat tha, 'to_string' sahi hai
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());

                string pal = "";
                if (len % 2 == 0) 
                {
                    pal = first_half + second_half;
                } 
                else 
                {
                    pal = first_half + second_half.substr(1);
                }

                long long pal_num = stoll(pal);          // Decimal palindrome number
                string baseK = convertToBaseK(pal_num, k);

                if (isPalindrome(baseK)) 
                {
                    sum += pal_num;                      // 'num' nahi, 'pal_num' ko add karo
                    n--;
                    if (n == 0)                          // 'if(n==)' galat tha
                        break;
                }
            }
            len++;
        }
        return sum;

}

    bool isPalindrome(string &s1) 
    {
        int i = 0;
        int j = s1.length() - 1;             // baseK nahi, s1 hi lena hai

        while (i <= j) 
        {
            if (s1[i] != s1[j])               // '@=' galat tha, '!=' sahi hai
                return false;
            i++;
            j--;
        }
        return true;
    }

      string convertToBaseK(long long num, int k) 
    {
        if (num == 0) 
            return "0";

        string res = "";                      // 'strin' galat tha, 'string' sahi hai

        while (num > 0) 
        {
            res += to_string(num % k);        // numK galat tha, num % k sahi hai
            num /= k;
        }

        reverse(res.begin(), res.end());      // Base-k string ulta banega, so reverse karo
        return res;
    }


signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye

    brute();                     // Brute call karo

    return 0;                    // Program successful terminate ho raha hai
}
