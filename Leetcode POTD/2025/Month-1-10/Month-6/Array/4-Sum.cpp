#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void brute()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2}; // Sample input
    int target = 0;

    vector<vector<int>> result;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (j < n && k < n && l < n && (nums[i] + nums[j] + nums[k] + nums[l] == target))
                    {

                        vector<int> arr;
                        arr.push_back(nums[i]);
                        arr.push_back(nums[j]);
                        arr.push_back(nums[k]);
                        arr.push_back(nums[l]);

                        sort(arr.begin(), arr.end());
                        auto it = find(result.begin(), result.end(), arr);
                        if (it == result.end())
                            result.push_back(arr);
                    }
                }
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << endl;
    }
    cout << endl;
}

void better()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2}; // Sample input
    int target = 0;

    vector<vector<int>> result;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {

                int required = target - (nums[i] + nums[j] + nums[k]);

                auto f = find(nums.begin() + k + 1, nums.end(), required);
                if (f != nums.end())
                {
                    vector<int> arr;
                    arr.push_back(nums[i]);
                    arr.push_back(nums[j]);
                    arr.push_back(nums[k]);
                    arr.push_back(required);

                    sort(arr.begin(), arr.end());
                    auto it = find(result.begin(), result.end(), arr);
                    if (it == result.end())
                        result.push_back(arr);
                }
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << endl;
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    better();

    return 0; // Program successful terminate ho raha hai
}
