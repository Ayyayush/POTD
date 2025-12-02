#include <bits/stdc++.h>
using namespace std;

void brute() // T.C = O(N^2), S.C = O(N)
{
    int n;
    cin >> n; // Array ka size input le rahe hain
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array elements input le rahe hain
    }
    int x;
    cin >> x; // Difference limit input le rahe hain

    vector<int> maxsub; // Maximum valid subarray store karne ke liye

    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> vec; // Temporary vector to store current valid subarray

        for (int j = i; j < nums.size(); j++)
        {
            if (abs(nums[i] - nums[j]) <= x) // Condition check kar rahe hain
            {
                vec.push_back(nums[j]); // Valid element ko store kar rahe hain

                // Check kar rahe hain ki koi bhi do elements ka difference x se zyada na ho
                for (int l = 0; l < vec.size(); l++)
                {
                    for (int m = 0; m < vec.size(); m++)
                    {
                        if (abs(vec[l] - vec[m]) > x)
                        {
                            vec.clear(); // Condition fail hone par vector clear kar rahe hain
                            break;
                        }
                    }
                }
            }
            else
            {
                break; // Condition fail hone par loop exit kar rahe hain
            }
            if (vec.size() > maxsub.size()) // Maximum size ka subarray store kar rahe hain
            {
                maxsub = vec;
            }
        }
    }

    for (auto x : maxsub)
        cout << x << " "; // Maximum valid subarray print kar rahe hain
}

void better() // T.C = O(N), S.C = O(N)
{
    int n, x;
    cin >> n; // Array size input le rahe hain
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Array elements input le rahe hain
    cin >> x;          // Difference limit input le rahe hain

    deque<int> minQ, maxQ; // Min aur Max elements track karne ke liye
    int start = 0, resStart = 0, resEnd = 0;

    for (int end = 0; end < n; end++)
    {
        while (!minQ.empty() && arr[minQ.back()] > arr[end])
            minQ.pop_back(); // Min queue update kar rahe hain
        while (!maxQ.empty() && arr[maxQ.back()] < arr[end])
            maxQ.pop_back(); // Max queue update kar rahe hain
        minQ.push_back(end), maxQ.push_back(end);

        // Jab tak max-min > x hai, start ko badhate raho
        while (arr[maxQ.front()] - arr[minQ.front()] > x)
        {
            if (minQ.front() == start)
                minQ.pop_front();
            if (maxQ.front() == start)
                maxQ.pop_front();
            start++;
        }

        if (end - start > resEnd - resStart)
            resStart = start, resEnd = end; // Max length ka subarray track kar rahe hain
    }

    for (int i = resStart; i <= resEnd; i++)
        cout << arr[i] << " "; // Maximum valid subarray print kar rahe hain
    cout << endl;
}

int main()
{
    brute();
    return 0;
}