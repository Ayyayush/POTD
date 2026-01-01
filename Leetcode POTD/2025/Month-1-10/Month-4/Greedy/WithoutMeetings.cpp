#include <bits/stdc++.h>
using namespace std;

void brute() // O(N*M) time, O(N*M) space  
{
    int days, n;
    cin >> days >> n;
    vector<vector<int>> meetings(n, vector<int>(2));

    // Input lena O(N)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> meetings[i][j];  
        }
    }

    set<int> st; // Har meeting ka har day store kar rahe hain  

    // O(N*M) time (N meetings, har ek ka M days range)  
    for (int i = 0; i < meetings.size(); i++)
    {
        for (int k = meetings[i][0]; k <= meetings[i][1]; k++)
        {
            st.insert(k);  // O(logN) har insertion ka  
        }
    }

    cout << days - st.size() << endl; // Unique occupied days nikal rahe hain  
}

/*
    ✅ **Time Complexity:**  
       - **Loop for meetings:** `O(N)`
       - **Loop for days range:** `O(M)`
       - **Insert in set:** `O(logN)`
       - **Total:** `O(N*M logN) ≈ O(N*M)`

    ✅ **Space Complexity:**  
       - `O(N*M)` worst case (agar saare days alag-alag stored ho)  
*/


void better()  // O(N logN) time, O(1) space  
{
    int days, n;
    cin >> days >> n;
    vector<vector<int>> meetings(n, vector<int>(2));

    // Input lena O(N)
    for (int i = 0; i < n; i++)
    {
        cin >> meetings[i][0] >> meetings[i][1];  
    }

    sort(begin(meetings), end(meetings)); // O(N logN) sorting  

    int result = 0, end = 0;

    for (auto &meet : meetings)
    {
        if (meet[0] > end)
        {
            result += meet[0] - end - 1; // Free days count kar rahe hain  
        }
        end = max(end, meet[1]); // Maximum end update kar rahe hain  
    }

    if (days > end)
    {
        result += days - end; // Remaining free days add kar rahe hain  
    }

    cout << result << endl;
}

/*
    ✅ **Time Complexity:**  
       - **Sorting Meetings:** `O(N logN)`
       - **Loop through meetings:** `O(N)`
       - **Total:** `O(N logN)`

    ✅ **Space Complexity:**  
       - **No extra space used:** `O(1)`
*/


void optimizeMeetings() // O(N + days) time, O(days) space  
{
    int days, n;
    cin >> days >> n;
    vector<vector<int>> meetings(n, vector<int>(2));

    // Input lena O(N)
    for (int i = 0; i < n; i++)
    {
        cin >> meetings[i][0] >> meetings[i][1];
    }

    vector<int> occupied(days + 2, 0); // Difference Array (O(days) space)  

    // Mark start and end points O(N)
    for (int i = 0; i < n; i++)
    {
        occupied[meetings[i][0]]++;    // Start mark  
        occupied[meetings[i][1] + 1]--; // End mark  
    }

    // Prefix sum to count occupied days O(days)
    int count = 0, occupiedDays = 0;
    for (int i = 1; i <= days; i++)
    {
        count += occupied[i];
        if (count > 0) occupiedDays++;
    }

    cout << days - occupiedDays << endl; // Free days nikal rahe hain  
}

/*
    ✅ **Time Complexity:**  
       - **Marking start/end in difference array:** `O(N)`
       - **Prefix sum to get occupied days:** `O(days)`
       - **Total:** `O(N + days)`

    ✅ **Space Complexity:**  
       - **Only difference array used:** `O(days)`
*/


int main()
{
    optimizeMeetings();
    return 0;
}
