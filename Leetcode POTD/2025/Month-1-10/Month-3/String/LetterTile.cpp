#include <bits/stdc++.h>
using namespace std;
void brute() // O(N^2)
{
  int count = 0;
  string tiles, subs;
  getline(cin, tiles);
  unordered_set<string> st;
  for (int i = 0; i < tiles.size(); i++)
  {
    subs = "";
    for (int j = i; j < tiles.size(); j++)
    {

      subs += tiles[j];

        cout << subs << endl;
        
        count++;
      
    }
  }
  cout << count << endl;
}

void better()
{
  int count = 0;
  string tiles, subs1, subs2;
  getline(cin, tiles);
  unordered_set<string> st;
  int s, e = tiles.size();

  for (int i = 0; i < tiles.size(); i++)
  {
    subs1 = "";
    subs2 = "";
    s = i;
    while (s < tiles.size() && e >= 0)
    {
      subs1 += tiles[s];
      subs2 += tiles[e];

        cout << subs1 << endl;
        count++;
      
     
      cout << subs2 << endl;
      count++;
     
    }

    s++;
    e--;
  }
  cout << count << endl;
}




int main()
{
  brute();
  return 0;
}