#include <bits/stdc++.h>
using namespace std;

void brute()
{     
    int s, i, j, count = 0;                                                      // Declare variables.

    cin >> s;                                                                    // Number of words input lete hain.
    cin.ignore();                                                                // Ignore newline left by cin.

    vector<string> words(s);                                                     // Words ka vector.
    for (i = 0; i < s; i++) {
        getline(cin, words[i]);                                                  // Each word ko input lete hain.
    }

    int q;                                                                        // Number of queries.
    cin >> q;                                                                     // Input number of queries.

    vector<vector<int>> queries(q, vector<int>(2));                              // Queries ka 2D vector.
    for (i = 0; i < q; i++) {
        for (j = 0; j < 2; j++) {
            cin >> queries[i][j];                                                // Queries input karte hain.
        }
    }

    // Process each query
    for (i = 0; i < queries.size(); i++) {                                       // Har query ke liye.
        count = 0;                                                               // Count reset karte hain.
        for (j = queries[i][0] - 1; j < queries[i][1]; j++) {                    // Range mein loop chalaate hain (Inclusive indexing).
            if ((words[j][0] == 'a' || words[j][0] == 'e' || words[j][0] == 'i' || words[j][0] == 'o' || words[j][0] == 'u') &&
                (words[j].back() == 'a' || words[j].back() == 'e' || words[j].back() == 'i' || words[j].back() == 'o' || words[j].back() == 'u')) {
                count++;                                                         // Agar word ka start aur end vowel hai to count badhaate hain.
            }
        }
        cout << count << " ";                                                    // Current query ka result print karte hain.
    }
    cout << endl;                                                                // End of output.
}


void better()
{

    
}

void optimal()
{
     bool isVowel(char &ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int Q = queries.size();
        int N = words.size();
        //"a,e,i,o,u"
        vector<int> result(Q);

        vector<int> cumSum(N);
        int sum = 0;
        for(int i = 0; i < N; i++) { //O(N)
            if(isVowel(words[i][0]) && isVowel(words[i].back())) {
                sum++;
            }

            cumSum[i] = sum;
        }

        for(int i = 0; i < Q; i++) { //O(Q)
            int l = queries[i][0];
            int r = queries[i][1];

            result[i] = cumSum[r] - ((l > 0) ? cumSum[l-1] : 0);
        }

        return result;

    }
}
int main()
{
    brute();                                                                     // Function call.
    return 0;                                                                    // Program ends here.
}
