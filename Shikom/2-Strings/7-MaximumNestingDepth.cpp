#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// BRUTE FORCE
// ----------------------------------------------------------
// Approach: For every index, check how many '(' are open
//           until it gets closed. Very inefficient.
// T.C: O(n^2)
// S.C: O(1)
//////////////////////////////////////////////////////////////
void brute()
{
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            int depth = 1;
            int cur = 1;

            // Count how deep we go until closing ')'
            for(int j = i+1; j < n; j++)
            {
                if(s[j] == '(') cur++;
                else if(s[j] == ')') cur--;

                depth = max(depth, cur);

                if(cur == 0) break;   // when matching pair found
            }

            ans = max(ans, depth);
        }
    }

    cout << ans << endl;
}

//////////////////////////////////////////////////////////////
// BETTER APPROACH
// ----------------------------------------------------------
// Use a stack to track depths.
// Push '(' → increase size, pop ')' → decrease.
// T.C: O(n)
// S.C: O(n) for stack
//////////////////////////////////////////////////////////////
void better()
{
    string s;
    cin >> s;

    stack<char> st;
    int maxDepth = 0;

    for(char c : s)
    {
        if(c == '(')
        {
            st.push(c);
            maxDepth = max(maxDepth, (int)st.size());  // stack size = depth
        }
        else if(c == ')')
        {
            st.pop();
        }
    }

    cout << maxDepth << endl;
}



def better():
    s = input()

    stack = []
    max_depth = 0

    for c in s:
        if c == '(':
            stack.append(c)
            max_depth = max(max_depth, len(stack))   # stack size = depth
        
        elif c == ')':
            stack.pop()

    print(max_depth)


    
//////////////////////////////////////////////////////////////
// OPTIMAL APPROACH (NO STACK) — Expand Depth Count
// ----------------------------------------------------------
// Simply count current depth with 'depth' variable.
// '(' → depth++
// ')' → depth--
// maxDepth = maximum depth reached.
// T.C: O(n)
// S.C: O(1)
//////////////////////////////////////////////////////////////
void optimal()
{
    string s;
    cin >> s;

    int depth = 0;
    int maxDepth = 0;

    for(char c : s)
    {
        if(c == '(')
            depth++;

        else if(c == ')')
            depth--;

        maxDepth = max(maxDepth, depth);   // update after each change
    }

    cout << maxDepth << endl;
}

//////////////////////////////////////////////////////////////

int main()
{
    // Choose any:
    // brute();
    // better();
    optimal();

    return 0;
}
