# ------------------------------
// Python Code (Frequency Method)
// Time Complexity: O(n)
// Space Complexity: O(1)   // only 26 lowercase chars are tracked
// Approach:
//   - Count frequency of each character in s
//   - Subtract frequency using characters in t
//   - If all counts become zero → strings are anagrams
# ------------------------------

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = {}                                  // map to store char counts

        for c in s:                              // count frequencies of s
            mp[c] = mp.get(c, 0) + 1

        for c in t:                              // subtract frequencies for t
            mp[c] = mp.get(c, 0) - 1

        for val in mp.values():                  // check if all zero
            if val != 0:
                return False

        return True



# ------------------------------
// Python Code (Sorting Method)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Approach:
//   - Convert string → list (strings cannot be sorted directly)
//   - Sort both lists
//   - Compare element-by-element
# ------------------------------

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        s = list(s)                               // convert string to list
        t = list(t)

        s.sort()                                  // sort list s
        t.sort()                                  // sort list t

        return s == t                             // compare sorted lists
