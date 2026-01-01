#include <bits/stdc++.h>
using namespace std;

void brute() // O(N^2);
{
    int n, maxsum = -1;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        string s1 = to_string(nums[i]);
        int add1 = accumulate(s1.begin(), s1.end(), 0, [](int sum, char c) { // 0(D)
            return sum + (c - '0');
        });

        for (int j = 0; j < nums.size(); j++)
        {
            string s2 = to_string(nums[j]);
            int add2 = accumulate(s2.begin(), s2.end(), 0, [](int sum, char c) { // 0(D)
                return sum + (c - '0');
            });

            if (add1 == add2 && i != j)
            {
                int summation = nums[i] + nums[j];
                maxsum = max(summation, maxsum);
            }
        }
    }

    cout << maxsum << endl;
}

void brute2()
{
    // T.C : O(n^2 * m), where m = number of digits
    // S.C : O(1)

    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    auto getDigitSum = [](int num) -> int 
    {
        int sum = 0;

        while(num > 0) 
        {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    };

    int result = -1;

    for(int i = 0; i < n; i++) 
    {
        int digitSumi = getDigitSum(nums[i]);

        for(int j = i + 1; j < n; j++) 
        {
            int digitSumj = getDigitSum(nums[j]);

            if(digitSumi == digitSumj) 
            {
                result = max(result, nums[i] + nums[j]);
            }
        }
    }

    cout << result << endl;
}





void better()
{
    // T.C : O(n*m), where m = number of digits
    // S.C : O(n)

    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    auto getDigitSum = [](int num) -> int 
    {
        int sum = 0;

        while(num > 0) 
        {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    };

    int result = -1;
    
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) 
    {
        int digitSum = getDigitSum(nums[i]);

        if(mp.count(digitSum)) 
        {
            result = max(result, nums[i] + mp[digitSum]);
        }

        mp[digitSum] = max(mp[digitSum], nums[i]);
    }

    cout << result << endl;
}





void optimal()
{
    // T.C : O(n*m), where m = number of digits
    // S.C : O(1)

    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    auto getDigitSum = [](int num) -> int 
    {
        int sum = 0;

        while(num > 0) 
        {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    };

    int result = -1;

    int mp[82] = {0}; // Maximum sum of digits in a number ≤ 81 (for 999999999)

    for(int i = 0; i < n; i++) 
    {
        int digitSum = getDigitSum(nums[i]);

        if(mp[digitSum] > 0) 
        {
            result = max(result, nums[i] + mp[digitSum]);
        }

        mp[digitSum] = max(mp[digitSum], nums[i]);
    }

    cout << result << endl;
}





int main()
{
    better();
    return 0;
}