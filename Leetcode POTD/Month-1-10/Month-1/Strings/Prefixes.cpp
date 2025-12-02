

#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int i,j,k,count=0;

    int n;
    cin>>n;
    cin.ignore();

      vector<string>words(n);
      for(i=0;i<n;i++)
      {
        getline(cin,words[i]);
      }

     string s,str;
    getline(cin, s);                
   

  
     for(i=0;i<words.size();i++)
    {
        str=words[i];
        for(k=0;k<str.size();k++)
        {
               if (!words[i].empty() && words[i][0] == s[0] && words[i].size()<s.size())    // Check if the word is not empty
        count++;
        }
      
    }
      //T.C. = O(n * k)

    cout<<count<<endl;



}

   
void better()
{
    int i, count = 0;

    // Input number of words
    int n;
    cin >> n;
    cin.ignore(); // Ignore newline after integer input

    // Input words
    vector<string> words(n);
    for (i = 0; i < n; i++) {
        getline(cin, words[i]);
    }

    // Input the string `s`
    string s;
    getline(cin, s);

    // Check for prefixes using substr
    for (i = 0; i < words.size(); i++) {
        string str = words[i];


        // Check if str is a prefix of s using substr
        if (!str.empty() && str == s.substr(0, str.size())) {
            count++;
        }
    }

    // Output the count
    cout << count << endl;
      //T.C. = O(n * k)
}


void opptimal()
{
    int i, count = 0;

    // Input number of words
    int n;
    cin >> n;
    cin.ignore(); // Ignore newline after integer input

    // Input words
    vector<string> words(n);
    for (i = 0; i < n; i++) {
        getline(cin, words[i]);
    }

    // Input the string `s`
    string s;
    getline(cin, s);

    // Check for prefixes using find
    for (i = 0; i < words.size(); i++) {
        string str = words[i];
        // Check if str is a prefix of s using find
        if (!str.empty() && s.find(str) == 0) {  // `find` will return 0 if `str` is at the start of `s`
            count++;
        }
    }

    // Output the count
    cout << count << endl;

    //T.C. = O(n * k)

}





int main()
{
    brute();
    return 0;
}
