#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define u unordered_map<int, int>
#define f(i, n) for (int i = 0; i < n; i++)

/**
 * GFG POTD-- GOOGLE   -- HARD
 * *APPROACH
 * minimum possible maximum sum maanga h toh Binary Search
 * k contigous subarrays mein divide krna h
 * eg 1,2,3,4  k==3
 * 1,2     3    4      .... ye 3 subarrays h
 * maximum sum h 4
 * agar hum  1    2,3     4  toh maxsum hota 5
 * toh humne jo soch ke first wala bnaya whi krna h question yhi maang rha h
 *
 *
 * *First Approach ...Recursion but TLE dega
 *
 * *Second Approach
 * Toh directly Binary Search se try krte h
 * Binary Search on answer karenge
 * low=max elt    high=sum of entire array  le lo
 * bcz maxelt se >= toh kaise bhi rahega maxsum nikal rha h toh upar eg dekho
 * low==3   high == 10  ho gya
 * mid ayega pehle 4+3 == 7
 * ab mid ahamra threshold value h
 * toh ab subarray bnate chalenge tbhi subarray split hoga jab uska sum exceed kare mid se
 * sum ==0 leke chalenge har subarray ke liye
 * eg :: 1st subarray mein 1+2+3 tak lenge ...4 lene pe exceed kar rha toh split maaro
 * aise bas 2 subarray ban rha h but k==3 h...
 *  yani ki threshold se choti value pe jyada subarrays ban skte h chance h
 * toh ab high = mid-1 krke dekho
 * now new mid== 4+0==5
 * subarrays banenge   1,2     3,     4
 * toh mid ==4 pe valid h toh store karo ab isse bhi niche jaake dekho
 * but aur left jaane pe low>=high ho jayega break
 * return min of valid answer
 *
 *
 */



bool check(vector<int> &arr, int mid, int k)
{
    int count = 1; // 1st subarray shuru kar rahe hain
    int sum = 0;   // Current subarray ka sum

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid)
            return false; // Koi bhi element agar mid se bada hai to impossible
        if (sum + arr[i] > mid)
        {                 // Agar add karte hi mid cross ho gaya
            count++;      // To naya subarray banana padega
            sum = arr[i]; // Naya subarray start with current element
        }
        else
        {
            sum += arr[i]; // Nahi to same subarray mein add kar do
        }
    }

    return count <= k; // Agar subarrays ki count k se zyada nahi bani to valid
}

void better()
{
    vector<int> arr = {7, 2, 5, 10, 8}; 
    int k = 2;                         

    int low = *max_element(arr.begin(), arr.end());   // Min possible max sum
    int high = accumulate(arr.begin(), arr.end(), 0); // Max possible max sum
    int answer = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (check(arr, mid, k))
        {                   // Agar mid ke andar split possible
            answer = mid;   // Yeh ek valid ans ho sakta hai
            high = mid - 1; // Left mein aur small ans dhoondo
        }
        else
        {
            low = mid + 1; // Mid chhota tha, range badhao
        }
    }

    cout << "Minimum largest sum to split array into " << k << " subarrays: " << answer << endl;
}

signed main()
{
    better();
    return 0;
}
