#include <bits/stdc++.h>
using namespace std;



void brute() 
{
    string s;
    getline(cin, s);

    int k;
    cin >> k;

    cin.ignore();

    if (s.size() >= k) 
    {
        cout << "True" << endl;
        return;
    }

    if (s.size() < k) 
    {
        cout << "False" << endl;
        return;
    }

    unordered_map<char, int> freq;

    for (char ch : s) 
    {
        freq[ch]++;
    }

    int oddfreq = 0, evenfreq = 0;

    for (auto it : freq) 
    {
        if (it.second % 2 == 0) 
        {
            evenfreq++;
        } 
        else 
        {
            oddfreq++;
        }
    }

    if (oddfreq <= k) 
    {
        cout << "True" << endl;
    } 
    else 
    {
        cout << "False" << endl;
    }
}



void better() 
{
    string s;
    getline(cin, s);  // Input string lete hain

    int k;
    cin >> k;  // Input integer k lete hain

    cin.ignore();  // Ignoring extra newline character

    if (s.size() >= k) 
    {
        cout << "True" << endl;  // Agar string ka size >= k, toh "True" print karenge
        return;
    }

    if (s.size() < k) 
    {
        cout << "False" << endl;  // Agar string ka size < k, toh "False" print karenge
        return;
    }

    // Frequency check karenge
    unordered_map<char, int> freq;

    for (char ch : s) 
    {
        freq[ch]++;  // Har character ki frequency count karenge
    }

    int oddfreq = 0, evenfreq = 0;

    for (auto it : freq) 
    {
        if (it.second % 2 == 0) 
        {
            evenfreq++;  // Even frequency ke liye count badhayenge
        } 
        else 
        {
            oddfreq++;  // Odd frequency ke liye count badhayenge
        }
    }

    if (oddfreq <= k) 
    {
        cout << "True" << endl;  // Agar odd frequency k se kam ya barabar ho, toh "True"
    } 
    else 
    {
        cout << "False" << endl;  // Warna "False"
    }
}



int main() 
{
    better();
    return 0;
}
