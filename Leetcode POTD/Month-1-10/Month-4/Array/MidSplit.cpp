#include <bits/stdc++.h>
using namespace std;

void superbrute() // T.C. = O(N^2), S.C. = O(1)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        int leftCount = 0, rightCount = 0;
        for (int j = 0; j <= i; j++) // Left traversal
        {
            if (nums[j] == nums[i])
                leftCount++;
        }
        for (int j = i; j < n; j++) // Right traversal
        {
            if (nums[j] == nums[i])
                rightCount++;
        }

        int n1 = i + 1;
        int n2 = n - i - 1;
        if (leftCount > n1 / 2 && rightCount > n2 / 2)
        {
            cout << i << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

void brute() // T.C. = O(N), S.C. = O(2N)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    unordered_map<int, int> m1, m2;
    for (int &num : nums)
    {
        m2[num]++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        m1[num]++;
        m2[num]--;
        int n1 = i + 1;
        int n2 = n - i - 1;
        if (m1[num] > n1 / 2 && m2[num] > n2 / 2)
        {
            cout << i << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

void good() // T.C. = O(N), S.C. = O(2N)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    unordered_map<int, int> m1, m2;
    for (int &num : nums)
    {
        m2[num]++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        m1[num]++;
        m2[num]--;
        int n1 = i + 1;
        int n2 = n - i - 1;
        if (m1[num] * 2 > n1 && m2[num] * 2 > n2) // Division costly hota hai, toh multiply use kiya
        {
            cout << i << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

void optimal() // T.C. = O(N), S.C. = O(1)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int maj = -1, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            maj = nums[i];
            count = 1;
        }
        else if (nums[i] == maj)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int majcount = 0;
    for (int &num : nums)
    {
        if (num == maj)
            majcount++;
    }

    count = 0;
    int index = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == maj)
        {
            count++;
        }
        int remainingcount = majcount - count;
        int n1 = i + 1;
        int n2 = n - i - 1;
        if (count * 2 > n1 && remainingcount * 2 > n2)
        {
            index = i;
            break;
        }
    }
    cout << index << endl;
}

int main()
{
    optimal();
    return 0;
}
