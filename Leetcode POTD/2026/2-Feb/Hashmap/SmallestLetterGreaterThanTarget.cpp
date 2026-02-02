class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int i, j, s, count;

        char k;
        char mingreatest = '{'; // Initialize to highest lower-case letter
        for (i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
            {
                mingreatest = letters[i]; // Find the smallest letter greater than target
                break;
            }
        }

        // If no valid letter found, wrap around and return letters[0]
        if (mingreatest == '{')
        {
            mingreatest = letters[0];
        }
        return mingreatest;


    }
};


/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {

    // Time Complexity: O(log n)                 // binary search
    // Space Complexity: O(1)                    // constant extra space
    // Approach: Binary Search

    let low = 0;
    let high = letters.length - 1;
    let ans = letters[0];                       // default wrap-around answer

    while (low <= high)
    {
        let mid = Math.floor((low + high) / 2);

        if (letters[mid] > target)              // possible answer found
        {
            ans = letters[mid];                 // store candidate
            high = mid - 1;                     // search left for smaller valid
        }
        else
        {
            low = mid + 1;                      // move right
        }
    }

    return ans;
};
