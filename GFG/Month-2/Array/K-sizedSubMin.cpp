#include <bits/stdc++.h>
using namespace std;


void brute() // O(N^2)
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < arr.size() - k + 1; i++)
    {
        int maximum = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            maximum = max(maximum, arr[j]);
        }
        result.push_back(maximum);
    }

    for (auto x : result)
    {
        cout << x << " ";
    }
}

void better()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> result;

    // Array input lena
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maximum = INT_MIN;
    int count = 0;

    // Loop to find maximum in each sliding window
    for (int i = 0; i <= arr.size() - k; i++)
    { // Loop condition fix kiya (<= lagaya)
        count++;
        maximum = max(maximum, arr[i]); // Current window ka max update kar rahe hain

        if (count == k)
        {                              // Jab ek complete window cover ho jaye
            result.push_back(maximum); // Maximum store karo
            maximum = INT_MIN;         // Reset maximum for next window
            count = 0;                 // Reset count
        }
    }

    // Output the result
    for (auto x : result)
    {
        cout << x << " ";
    }
}

void optimal()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> result;
    deque<int> dq; // Max element ke indexes store karne ke liye

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        // Pichle window ke elements hatao
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Chhote elements hatao jo naye aane wale element se chhote hain
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        // Current element ka index push karo
        dq.push_back(i);

        // Jab window complete ho chuki ho tab max add karo result me
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
}


int main()
{
    better();
    return 0;
}