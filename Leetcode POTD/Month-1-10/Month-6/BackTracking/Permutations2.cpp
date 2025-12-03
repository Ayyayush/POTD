#include <bits/stdc++.h>
using namespace std;

void permutationsString(string str, string ans, set<string> &st) // set<string> hona chahiye
{
    if (str.size() == 0)
    {
        st.insert(ans);       // Permutation insert kar rahe hain
        return;               // Return karna zaroori hai
    }

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string left = str.substr(0, i);         // 0 se i-1 tak
        string right = str.substr(i + 1);       // i+1 se end tak
        string nextstr = left + right;          // i-th char ko hata diya
        permutations(nextstr, ans + ch, st);    // Recursive call
    }
}

void permutations(vector<int> arr, vector<int> &ans, set<vector<int>> &st)
{
    if (arr.size() == 0)
    {
        st.insert(ans);      // Jab ek permutation ready ho jaye, to set mein daal do
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        int ch = arr[i];

        // i-th element ko hata ke new vector banate hain
        vector<int> remaining;
        for (int j = 0; j < arr.size(); j++)
        {
            if (j != i) remaining.push_back(arr[j]);
        }

        ans.push_back(ch);                         // current number add karo
        permutations(remaining, ans, st);          // recursion
        ans.pop_back();                            // backtrack karo
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};                   // Input array
    set<vector<int>> st;                           // Unique permutations store karne ke liye
    vector<int> ans;                               // Current permutation

    permutations(arr, ans, st);

    // Print all unique permutations
    for (auto &vec : st)
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
