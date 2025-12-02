#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*
    Approach: Suffix Automaton
    Time Complexity: O(n * ALPHABET) ~ O(n) amortized (building the SAM is linear in string length)
    Space Complexity: O(n * ALPHABET) (number of states <= 2n; each state stores transitions for 26 letters)
    Explanation:
      - Build a suffix automaton (SAM) for the input string.
      - Number of distinct non-empty substrings = sum_over_states( len[state] - len[link[state]] )
        (excluding the initial state which contributes 0).
    */
    int countSubs(string& s) {
        int n = (int)s.size();                                 // length of input string

        // Maximum number of states in SAM is at most 2*n
        struct State {
            int len;                                           // longest length of substring in this state
            int link;                                          // suffix link
            int next[26];                                      // transitions for 'a'..'z'
            State() {
                len = 0;
                link = -1;
                for (int i = 0; i < 26; ++i) next[i] = -1;    // initialize to no transition
            }
        };

        vector<State> st;                                      // states of the SAM
        st.reserve(2 * n + 5);                                 // reserve to avoid reallocations
        st.push_back(State());                                 // state 0: initial state
        st[0].len = 0;                                         // initial state's length = 0
        st[0].link = -1;                                       // initial state's link = -1
        int last = 0;                                          // points to the state for the entire string processed so far

        // function to extend SAM with character 'c' (0..25)
        auto sam_extend = [&](int c) {
            int cur = (int)st.size();
            st.push_back(State());                             // create new state
            st[cur].len = st[last].len + 1;                    // longest length for cur
            int p = last;
            // propagate transition p --c--> cur for all p that don't have this transition
            while (p != -1 && st[p].next[c] == -1) {
                st[p].next[c] = cur;
                p = st[p].link;
            }
            if (p == -1) {
                st[cur].link = 0;                              // link to initial state
            } else {
                int q = st[p].next[c];
                if (st[p].len + 1 == st[q].len) {
                    st[cur].link = q;                         // direct link
                } else {
                    // need to clone state q
                    int clone = (int)st.size();
                    st.push_back(State());
                    st[clone] = st[q];                        // copy all fields
                    st[clone].len = st[p].len + 1;            // set clone length
                    // redirect transitions that pointed to q to point to clone
                    while (p != -1 && st[p].next[c] == q) {
                        st[p].next[c] = clone;
                        p = st[p].link;
                    }
                    st[q].link = st[cur].link = clone;       // adjust links
                }
            }
            last = cur;                                        // update last
        };

        // Build SAM for string s
        for (char ch : s) {
            int c = ch - 'a';
            sam_extend(c);                                     // extend automaton with character
        }

        // Count distinct substrings:
        // sum over all states (len[state] - len[link[state]])
        long long ans = 0;
        for (size_t i = 1; i < st.size(); ++i) {              // skip state 0 (initial) since link = -1
            int L = st[i].len;                                // longest length in state i
            int linkL = (st[i].link == -1) ? 0 : st[st[i].link].len; // length of link state
            ans += (long long)(L - linkL);                   // each difference counts new distinct substrings
        }

        return (int)ans;                                      // fits in int for n <= 3000
    }
};
