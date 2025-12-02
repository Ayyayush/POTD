#include <bits/stdc++.h>
using namespace std;

void better()
{
  string s;
  cin >> s; // Input string

  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != ']')
      st.push(s[i]); // Push characters until we find ']'
    else
    {
      string word;
      while (!st.empty() && st.top() != '[')
      {
        word.push_back(st.top());
        st.pop();
      }
      reverse(word.begin(), word.end()); // Reverse the extracted word
      st.pop();                          // Remove '['

      string k;
      while (!st.empty() && isdigit(st.top()))
      {
        k.push_back(st.top());
        st.pop();
      }
      reverse(k.begin(), k.end()); // Reverse to get the correct number
      int num = stoi(k);           // Convert to integer

      string repeated;
      for (int j = 0; j < num; j++)
      {
        repeated.append(word); // Repeat the word num times
      }

      for (char c : repeated)
        st.push(c); // Push the expanded string back into stack
    }
  }

  string ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end()); // Reverse to get the final decoded string

  cout << ans << endl; // Output the decoded string
}

int main()
{
  better();
  return 0;
}
