/**
 * *Max Min Height
 * Maximize the minimum
 * Similar to couting ship container
 * Ek baar mein k days w continous flowers ko water kar skte h
 * water krne pe height increase ho jata h by 1
 * Smallest ko badhao toh maximize hoga minimum wala
 *
 *
 * *INTUITION
 * Hum pehle sochnege ki minimum wale pe jao min find karke wha se w consectuive ko water  karo
 * par maan lo 10000 flowers bhi h toh bhot time lagega
 * So we can use difference array
 * Ye kisi range mein value update krna ho toh constant time me de dega
 * It is like a magic trick
 * a= 0,0,0,0,0    x=3
 * naive way h ki saare index pe jaake badhao by x
 *
 *
 * *DIFF Array way
 * ek array bnao n+1 size ka
 * maan lo 1 se leke 3 tak by x badhana h
 * diff[l]+=x     l==1
 * diff[r+1]-=x     r==5
 * == 0,3,0,0,0,-3
 * now process the prefix sum
 * prefix sum == 0,3,3,3,0,0
 * array == 0,3,3,3,0
 *
 *
 * Using this in question
 * hum lok k consectuive days tak har dinn W flowers ko water kr skte h
 * hume smallest height ko maximize krna h jabtak days khtm na ho jaye
 * brute mein hum baar baar minimum check karte h time lagega
 * so we can do binary search on answer
 *
 * water [i]  += need
 * water[i+w] -= need
 *
 */

// Approach: Use binary search to maximize the minimum possible height. For each candidate height, check if it can be achieved by at most k waterings using a difference array for efficient range update simulation.
// Time Complexity: O(n * log k), where n is the size of arr and log k is from binary search steps.
// Space Complexity: O(n), for the water difference array.
class Solution
{
public:
    // Helper function to check if targetHeight can be achieved with <= k waterings
    bool isPossible(vector<int> &arr, int k, int w, int targetHeight)
    {
        int n = arr.size();
        vector<int> water(n + 1, 0); // Difference array for efficient range addition
        int daysUsed = 0;
        int currWater = 0;

        for (int i = 0; i < n; i++)
        {
            currWater += water[i]; // Add the effect of previous waterings
            int currHeight = arr[i] + currWater;
            if (currHeight < targetHeight)
            {
                int need = targetHeight - currHeight; // Water needed at this point
                daysUsed += need;
                if (daysUsed > k)
                { // If exceeded allowed waterings, not possible
                    return false;
                }
                currWater += need; // Add immediate effect
                water[i] += need;  // Start effect at i
                if (i + w <= n)
                {
                    water[i + w] -= need; // End effect after window
                }
            }
        }
        return true;
    }

    // Main function to maximize the minimum height
    int maxMinHeight(vector<int> &arr, int k, int w)
    {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;

        int result = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid))
            {
                result = mid; // Try to go higher
                low = mid + 1;
            }
            else
            {
                high = mid - 1; // Try lower
            }
        }
        return result;
    }
};

/*
 *
 * Dry Run
 *
 * Input: arr = [2, 2, 2, 2, 1, 1], k = 2, w = 3
 *
 * 1. Binary search: low = 1, high = 3 (since min(arr)=1, max we can reach = 1 + k = 3)
 * 2. Try mid = 2:
 *     - isPossible(arr, 2, 3, 2):
 *         i=0: currHeight = 2, no water needed.
 *         i=1: currHeight = 2, no water needed.
 *         i=2: currHeight = 2, no water needed.
 *         i=3: currHeight = 2, no water needed.
 *         i=4: currHeight = 1, need 1 water. daysUsed = 1, water[4] += 1.
 *         i=5: currWater includes water[4]=1, so currHeight = 1+1=2, no more water needed.
 *         All daysUsed = 1 <= 2. So mid=2 is possible.
 *     - Update result=2, low=3
 * 3. Try mid = 3:
 *     - isPossible(arr, 2, 3, 3):
 *         i=0: currHeight = 2, need 1 water. daysUsed = 1, water[0] += 1, water[3] -= 1.
 *         i=1: currWater=1, currHeight=3, no water needed.
 *         i=2: currWater=1, currHeight=3, no water needed.
 *         i=3: currWater+=water[3]=-1 (currWater=0), currHeight=2, need 1 water. daysUsed = 2, water[3] += 1, water[6] -= 1.
 *         i=4: currWater=1, currHeight=2, need 1 water. daysUsed = 3 (> k), return false.
 *     - mid=3 is not possible, high=2
 * 4. Loop ends. Return result=2.
 *
 */
