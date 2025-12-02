#include <bits/stdc++.h>
using namespace std;

void better()    
{
    // Approach: Extra space (vector<char> res) use karke compression kar rahe
    // T.C. = O(n), S.C. = O(n)

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    vector<char> res;                                   // compressed string yahan banega
    int count = 1;

    for (int i = 1; i < chars.size(); i++) {
        if (chars[i] == chars[i - 1]) {
            count++;
        } else {
            res.push_back(chars[i - 1]);                // previous char daal do
            if (count > 1) {
                string cnt = to_string(count);          // count ko string mein convert karo
                for (char c : cnt) res.push_back(c);    // har digit ko daalo
            }
            count = 1;                                  // naye group ka count start
        }
    }

    // Last character handle
    res.push_back(chars.back());
    if (count > 1) {
        string cnt = to_string(count);
        for (char c : cnt) res.push_back(c);
    }

    chars = res;                                        // chars mein compressed result copy
    cout << "Compressed chars: ";
    for (char c : chars) cout << c << " ";
    cout << "\nLength: " << chars.size() << endl;
}

void optimal()
{
    // Approach: In-place compression using two-pointer technique
    // T.C. = O(n), S.C. = O(1)

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int i = 0, index = 0;                              // i → read ptr, index → write ptr

    while (i < chars.size()) {
        char current = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == current) {
            i++;
            count++;
        }

        chars[index++] = current;                      // pehla char likho
        if (count > 1) {
            string cnt = to_string(count);
            for (char c : cnt) {
                chars[index++] = c;                    // count ke digits daalo
            }
        }
    }

    cout << "Compressed chars: ";
    for (int j = 0; j < index; j++) cout << chars[j] << " ";
    cout << "\nLength: " << index << endl;
}

int main()
{
    better();
    cout << "---------------------\n";
    optimal();
    return 0;
}
