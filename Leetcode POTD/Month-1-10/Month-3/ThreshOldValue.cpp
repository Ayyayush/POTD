#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2 * log n)  --> Har iteration mein min_element() and erase() use ho raha hai jo O(n log n) hai, aur worst case mein yeh n times execute ho sakta hai.
    // Space Complexity: O(n)          --> nums vector ke liye extra space use ho raha hai.

    int n, count = 0, min1 = 0, min2 = 0;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    while (nums.size()>=2) 
    {
        auto m1 = min_element(nums.begin(), nums.end());        // O(n)  --> Minimum element dhoondhna
        min1 = *m1;

        if (min1 >= k) 
        {
            cout<<count<<endl;
             return;
          
        }

        auto it1 = find(nums.begin(), nums.end(), min1);        // O(n)  --> Minimum element ka position dhundhna
        int pos = distance(nums.begin(), it1);
        nums.erase(nums.begin() + pos);                         // O(n)  --> Element erase karna
        if (nums.empty()) break;  // **Check if vector is empty before accessing second min**

        auto m2 = min_element(nums.begin(), nums.end());        // O(n)  --> Doosra minimum element dhoondhna
        min2 = *m2;

        auto it2 = find(nums.begin(), nums.end(), min2);        // O(n)  --> Doosra minimum element ka position dhundhna
        pos = distance(nums.begin(), it2);
        nums.erase(nums.begin() + pos);                         // O(n)  --> Doosra element erase karna

        nums.push_back((min(min1, min2) * 2) + max(min1, min2)); // O(1)  --> Naya element insert karna
        count++;
    }

    cout << count << endl;
}


void better()
{
        // Time Complexity Analysis:
    // Finding min_element -> O(n)
    // Erasing an element -> O(n) (worst case, as vector shifts elements)
    // Inserting into vector -> O(1) (push_back at the end)
    // While loop runs approximately O(n) times in the worst case
    // Total T.C. = O(n^2) in the worst case due to repeated min_element and erase operations


int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;



                long long  count = 0, min1 = 0, min2 = 0;
                
                while (nums.size() >= 2)
                {
                    auto m1 = min_element(nums.begin(), nums.end());
                    min1 = *m1;
                    if (min1 >= k)
                    {
                        break;
                    }
                    nums.erase(m1);
        
                    auto m2 = min_element(nums.begin(), nums.end());
                    min2 = *m2;
                     
                    nums.erase(m2);
        
                    nums.push_back((min1 * 2) + min2);
                    count++;
                }
        
                cout<< count;
                
        
}


void optimal()
{
    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    

}



void optimal()              // it can be done using heap 
{

}

int main()
{
    better();
    return 0;
}
