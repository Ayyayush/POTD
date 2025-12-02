class Solution
{
public:
    void merge(vector<int> &nums, vector<int> &idx, vector<int> &ans, int left, int mid, int right)
    {
        /*
        ✅ Ye merge step modified merge sort ka hai.
        ✅ Isme hum sirf sorting nahi karte, balki har element ke liye count bhi rakhte hain:
           ki is element ke right mein kitne chhote elements aaye.

        📌 Kaise kaam karta hai:
           Maan lo nums = [5, 2, 6, 1] aur idx = [0, 1, 2, 3]
           Aur ab left subarray = [5, 2] (index 0..1)
               right subarray = [6, 1] (index 2..3)
           Ye sorted nahi hai pehle, merge sort ke steps mein banega.
           Jab hum merge karenge, hum dekhenge ki kaun chhota hai aur
           left wale element ke liye kitne right wale chhote hain — woh hum ans[] mein store karte hain.
        */

        vector<int> temp(right - left + 1); // Ye temp index array hai, jo final merge ke baad updated indices store karega
        int i = left;                       // Left subarray pointer: left..mid
        int j = mid + 1;                    // Right subarray pointer: mid+1..right
        int k = 0;                          // Temp array pointer

        int rightCount = 0; // Ye batata hai ki kitne right wale elements chhote aaye ab tak

        while (i <= mid && j <= right)
        {
            /*
            Example:
            Agar nums[idx[i]] = 5 aur nums[idx[j]] = 1
            To 1 < 5 hai, iska matlab idx[i] ke right mein ek chhota element hai.
            RightCount++ karo aur right wale ko merge karo.
            */
            if (nums[idx[j]] < nums[idx[i]])
            {
                rightCount++;         // Ek aur chhota element mila
                temp[k++] = idx[j++]; // Right wala merge ho gaya temp mein
            }
            else
            {
                /*
                Agar left wala right wale se chhota ya equal hai,
                to left wale index ke answer mein rightCount add karo,
                kyunki utne chhote elements right se aa chuke hain.
                */
                ans[idx[i]] += rightCount; // Answer update karo
                temp[k++] = idx[i++];      // Left wala merge karo temp mein
            }
        }

        while (i <= mid)
        {
            /*
            Agar left wale elements bach gaye hain aur right finish ho gaya hai,
            to ab bache hue left wale ko bhi utna hi rightCount milega,
            kyunki baaki ke right mein koi chhota nahi bacha.
            */
            ans[idx[i]] += rightCount; // Bacha hua left bhi rightCount ko add karega
            temp[k++] = idx[i++];
        }

        while (j <= right)
        {
            /*
            Agar right wale bach gaye hain aur left khatam ho gaya,
            to right wale directly merge ho jaayenge.
            Ye answer ko affect nahi karte.
            */
            temp[k++] = idx[j++];
        }

        // Ab jo temp mein final indices bane hain, unko wapas idx mein daal do
        for (int p = left; p <= right; p++)
        {
            idx[p] = temp[p - left]; // Left se offset leke temp ka element assign karo
        }

        /*
        ✅ Is poore process ke baad:
           - idx array updated ho jaata hai (sorted order ke indices se)
           - ans[] mein har index ke liye right side ke chhote elements ka count ban jaata hai
        */
    }

    void mergeSort(vector<int> &nums, vector<int> &idx, vector<int> &ans, int left, int right)
    {
        if (left >= right)
            return; // Base case: ek hi element

        int mid = left + (right - left) / 2;

        mergeSort(nums, idx, ans, left, mid);      // Left sort
        mergeSort(nums, idx, ans, mid + 1, right); // Right sort

        merge(nums, idx, ans, left, mid, right); // Merge step
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n, 0); // Final answer store karne ke liye
        vector<int> idx(n, 0); // Index array to keep track of original indices

        for (int i = 0; i < n; i++)
            idx[i] = i; // Initialize indices

        mergeSort(nums, idx, ans, 0, n - 1); // Merge sort call

        return ans; // Answer return karo
    }
};