#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n, m;
    cin >> n >> m; // Array size aur queries ka count input le rahe hain

    vector<int> nums(n); // Array ko store karne ke liye vector
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array elements input le rahe hain
    }

    vector<vector<int>> queries(m, vector<int>(3)); // Queries ko store karne ke liye 2D vector
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j]; // Har query ke liye start index, end index aur decrement value input le rahe hain
        }
    }

    bool all_zero = true; // Flag to check agar poora array zero ho gaya
    for (int k = 0; k < nums.size(); k++)
    {
        if (nums[k] != 0) // Agar koi bhi non-zero element mil gaya to flag false ho jayega
        {
            all_zero = false;
            break;
        }
    }

    if (all_zero) // Agar poora array zero ho gaya to index print karke return karenge
    {
        cout << "0" << endl;
        return;
    }

    for (int i = 0; i < m; i++) // Har query ko process karne ke liye loop
    {
        for (int j = queries[i][0]; j <= queries[i][1]; j++) // Given range me elements ko decrement kar rahe hain
        {
            if (nums[j] > 0) // Sirf tabhi decrement karenge agar element greater than 0 hai
            {
                nums[j] = max(0, nums[j] - queries[i][2]); // Ensure ki element negative na ho
            }
        }

        bool all_zero = true; // Flag to check agar poora array zero ho gaya
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] != 0) // Agar koi bhi non-zero element mil gaya to flag false ho jayega
            {
                all_zero = false;
                break;
            }
        }

        if (all_zero) // Agar poora array zero ho gaya to index print karke return karenge
        {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << "-1" << endl; // Agar kabhi bhi poora array zero nahi hua to -1 print karenge
}





// DIFFERENCE ARRAY TECHNIQUE
// diff[l]+=x
// diff[r+1]-=x;     if(r+1<n)
// cumulative sum of diff array 
// T.C : O(Q * (Q + n))
// S.C : O(n)
void better()
{
    int n, Q;
    cin >> n >> Q; // Array size aur queries ka count input le rahe hain
    
    vector<int> nums(n);
    for (int &num : nums)
        cin >> num; // Array ke elements input le rahe hain

    vector<vector<int>> queries(Q, vector<int>(3)); // Queries ko store karne ke liye 2D vector
    for (int i = 0; i < Q; i++)
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2]; // Har query ke liye l, r aur x input le rahe hain

    auto checkWithDifferenceArrayTeq = [&](int k)
    {
        vector<int> diff(n, 0); // Difference array initialize kar rahe hain

        // O(Q)
        for (int i = 0; i <= k; i++)
        {
            int l = queries[i][0], r = queries[i][1], x = queries[i][2];
            diff[l] += x; // l index se x add kar rahe hain
            if (r + 1 < n)
                diff[r + 1] -= x; // r+1 index se x subtract kar rahe hain
        }

        int cumSum = 0;
        // O(n)
        for (int i = 0; i < n; i++)
        {
            cumSum += diff[i];
            diff[i] = cumSum;
            if (nums[i] - diff[i] > 0)
                return false; // Agar nums[i] 0 nahi bana, to false return karenge
        }
        return true; // Agar poora array zero ban gaya, to true return karenge
    };

    if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; }))
    {
        cout << 0 << endl; // Pehle se hi sab zero hai to answer 0 hoga
        return;
    }

    for (int i = 0; i < Q; i++)
    { // O(Q * (Q + n))
        if (checkWithDifferenceArrayTeq(i))
        {
            cout << i + 1 << endl; // Jis index par array zero ho gaya wahi answer hai
            return;
        }
    }

    cout << -1 << endl; // Agar kabhi bhi zero nahi bana to -1 print karenge
}

// T.C : O(log(Q) * (Q + n))
// S.C : O(n)
void optimal()
{
    int n, Q;
    cin >> n >> Q; // Array size aur queries ka count input le rahe hain

    vector<int> nums(n);
    for (int &num : nums)
        cin >> num; // Array elements input le rahe hain

    vector<vector<int>> queries(Q, vector<int>(3)); // Queries ko store karne ke liye 2D vector
    for (int i = 0; i < Q; i++)
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2]; // Har query ke liye l, r aur x input le rahe hain

    auto checkWithDifferenceArrayTeq = [&](int k)
    {
        vector<int> diff(n, 0); // Difference array initialize kar rahe hain

        // O(Q)
        for (int i = 0; i <= k; i++)
        {
            int l = queries[i][0], r = queries[i][1], x = queries[i][2];
            diff[l] += x; // l index se x add kar rahe hain
            if (r + 1 < n)
                diff[r + 1] -= x; // r+1 index se x subtract kar rahe hain
        }

        int cumSum = 0;
        // O(n)
        for (int i = 0; i < n; i++)
        {
            cumSum += diff[i];
            diff[i] = cumSum;
            if (nums[i] - diff[i] > 0)
                return false; // Agar nums[i] 0 nahi bana, to false return karenge
        }
        return true; // Agar poora array zero ban gaya, to true return karenge
    };

    if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; }))
    {
        cout << 0 << endl; // Pehle se hi sab zero hai to answer 0 hoga
        return;
    }

    int l = 0, r = Q - 1, k = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (checkWithDifferenceArrayTeq(mid))
        {
            k = mid + 1; // Possible answer store kar rahe hain
            r = mid - 1; // Left side search kar rahe hain
        }
        else
        {
            l = mid + 1; // Right side search kar rahe hain
        }
    }

    cout << k << endl; // Final answer print kar rahe hain
}

int main()
{
    optimal(); // Better function call kar rahe hain
    return 0;
}