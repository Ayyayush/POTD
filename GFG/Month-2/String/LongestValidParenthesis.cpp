#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int count=0,maxcount=-1;
    string s;
    getline(cin,s);
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(c=='(')
        st.push(c);
        else
        {
            if(!st.empty())
            {
                if(st.top()=='(' && c==')')
                {
                count+=2;
                maxcount=max(count,maxcount);
                st.pop();
                }
                else
                {
                    count=0;
                }
            }
            else
            {
                count=0;
            }
        }
      
    }
    cout<<maxcount<<endl;
}

void better() {
    string s;
    cin >> s; // Input lo string ka

    stack<int> st; // Stack initialize kiya
    st.push(-1); // Dummy index push kiya taaki calculations sahi ho
    int maxi = 0; // Maximum valid substring length store karne ke liye

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') 
            st.push(i); // Agar '(' mila to index stack me daal do
        else {
            st.pop(); // ')' aane par stack se ek element hatao
            if (!st.empty()) 
                maxi = max(maxi, i - st.top()); // Maximum length update karo
            else 
                st.push(i); // Stack empty ho gaya to current index push karo
        }
    }

    cout << maxi << endl; // Output maximum length of valid substring
}

 



int main()
{
    better();
    return 0;
}