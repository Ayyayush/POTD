#include <bits/stdc++.h>
using namespace std;

void brute() // using STL
{
    int i, s;
    cin >> s;
    
    vector<int> nums(s);
    for (i = 0; i < s; i++)
    {
        cin >> nums[i];
    }
    
    vector<int>::iterator it1, it2;

    if(is_sorted(nums.begin(), nums.end() ))
    {
        cout<<"true"<<endl;
        return;
    }
    else{
    // Finding the minimum element
    it1 = min_element(nums.begin(), nums.end());
    int minelt = *it1;

    // Finding position of the minimum element
    it2 = find(nums.begin(), nums.end(), minelt);
    int pos = distance(nums.begin(), it2);

    // Checking sorted conditions
    if (!(is_sorted(nums.begin() + pos, nums.end())))
    {
        cout << "False" << endl;
        return;
    }
    else if (is_sorted(nums.begin(), nums.begin() + pos) && nums[0]>nums[nums.size()-1])
    {
        cout << "True" << endl;
        return;
    }

    cout << "False" << endl; // Default case
}
}

void better()
{
    
}

int main()
{
    brute();
    return 0;
}
