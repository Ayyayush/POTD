#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    // Time Complexity: O(N^2) in worst case, O(N + M) in best case  
    // Space Complexity: O(1), kyunki koi extra space use nahi ho raha  

    string str;
    getline(cin, str);

    string subs;
    getline(cin, subs);

    while (!str.empty())    // Jab tak string empty nahi hoti  
    {
        size_t index = str.find(subs);    // Substring ka first occurrence ka index milega   ---> O(N * M) worst case  

        if (index != string::npos) 
        {
            str.erase(index, subs.size());   // Substring ko hata rahe hain ---> O(N) worst case  
        } 
        else 
        {
            break;  // Jab substring nahi milti, loop ko break karenge  
        }
    }

    cout << str << endl;   // Final string print karo  
}


void optimal()          // KNUTH MORRIS PRATT ALGO
{
    // Time Complexity: O(N + M), kyunki KMP algorithm ka use ho raha hai
    // Space Complexity: O(N), kyunki ek extra output string ban rahi hai

    string str;
    getline(cin, str);

    string subs;
    getline(cin, subs);

    size_t index = 0;
    ostringstream result;    // Final result store karne ke liye

    while ((index = str.find(subs, index)) != string::npos)   // KMP based fast find ---> O(N + M)
    {
        result << str.substr(0, index);    // Substring add kar rahe hain bina target word ke
        str = str.substr(index + subs.size());    // Remaining string ko assign kar rahe hain
    }

    result << str;   // Jo last portion bach gaya usko add kar do
    cout << result.str() << endl;   // Optimized output
}


int main() 
{
    brute();
    return 0;
}
