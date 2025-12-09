class Solution {
public:

    // --------------------------------------------------------------
    // Time Complexity  : O(n^2 * m)
    //    - n = number of strings
    //    - m = maximum length of a single string
    //    - We compare every pair (i, j) and compare characters.
    //
    // Space Complexity : O(m)
    //    - Temporary prefix string 'subs' can go up to m length.
    //
    // Approach:
    //    - For every pair of strings, compute their longest
    //      common prefix (pairwise LCP).
    //    - Track the smallest LCP across all pairs.
    // --------------------------------------------------------------
    string longestCommonPrefix(vector<string>& strs) {

        string minstring = strs[0];          // globally smallest prefix
        int minsize = INT_MAX;               // keep track of minimum length

        // Loop through all pairs of strings
        for (int i = 0; i < strs.size() - 1; i++)
        {
            for (int j = i + 1; j < strs.size(); j++)
            {
                string subs = "";            // prefix for this pair
                int x = 0;

                // Extract common prefix between strs[i] and strs[j]
                while (x < strs[i].size() &&
                       x < strs[j].size() &&
                       strs[i][x] == strs[j][x])
                {
                    subs += strs[i][x];      // add matching char
                    x++;                     // move forward
                }

                // Update global min prefix if this one is smaller
                if (subs.size() < minsize)
                {
                    minsize = subs.size();
                    minstring = subs;
                }
            }
        }

        return minstring;
    }
};



class Solution {
public:

    // --------------------------------------------------------------
    // Time Complexity  : O(n * m)
    //    - Compare each string with the next one only.
    //    - For each pair, at most m operations.
    //
    // Space Complexity : O(m)
    //    - Temporary string 'temp' can take up to m chars.
    //
    // Approach:
    //    - Start with prefix = first string.
    //    - Compare strs[i] with strs[i+1] and compute their LCP.
    //    - Always update prefix to the smaller common prefix.
    //
    // --------------------------------------------------------------
    string longestCommonPrefix(vector<string>& strs) {

        string s = strs[0];                      // global prefix starting with first string

        // Compare each string with its next neighbor
        for (int i = 0; i < strs.size() - 1; i++)
        {
            string temp = "";                   // prefix for this adjacent pair
            string s1 = strs[i];
            string s2 = strs[i + 1];

            int k = 0;

            // Extract LCP for s1 and s2
            while (k < min(s1.size(), s2.size()) &&
                   s1[k] == s2[k])
            {
                temp += s1[k];                  // add matching char
                k++;                            // move forward
            }

            // Update global prefix with the smaller prefix
            if (temp.size() < s.size())
            {
                s = temp;
            }
        }

        return s;
    }
};
