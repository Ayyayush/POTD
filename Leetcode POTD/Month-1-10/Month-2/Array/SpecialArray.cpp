#include <bits/stdc++.h>
using namespace std;

void brute()
{
    vector<int> nums = {4, 3, 1, 6};  

    if (nums.size() == 1) 
    {
        cout << "true" << endl;
        return;
    }

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if ((nums[i] % 2) == (nums[i + 1] % 2))   
        {
            cout << "false" << endl;
            return;
        }
    }

    cout << "true" << endl;
}

void better()
{
    vector<int> nums = {4, 3, 1, 6};  

    if (nums.size() == 1) 
    {
        cout << "true" << endl;
        return;
    }

    for (int i = 1; i < nums.size(); i++)  
    {
        if ((nums[i - 1] % 2) == (nums[i] % 2))   
        {
            cout << "false" << endl;
            return;
        }
    }

    cout << "true" << endl;
}

void optimal()
{
    vector<int> nums = {4, 3, 1, 6};  

    if (nums.size() == 1) 
    {
        cout << "true" << endl;
        return;
    }

    bool isSpecial = true;

    for (int i = 1; i < nums.size(); i++)  
    {
        if ((nums[i - 1] % 2) == (nums[i] % 2))   
        {
            isSpecial = false;
            break;
        }
    }

    cout << (isSpecial ? "true" : "false") << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}
