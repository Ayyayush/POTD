#include <bits/stdc++.h>
using namespace std;

// Dummy MountainArray class for reference, actual implementation online judge par hoti hai
class MountainArray
{
public:
    int get(int index); // Element return karta hai at given index
    int length();       // Length return karta hai
};

void better()
{
    int target;
    cin >> target; // Target input lo

    MountainArray mountainArr; // MountainArray object (judge provide karta hai)

    int n = mountainArr.length(); // Mountain array ki length lo

    // Step 1: Peak index find karna
    int low = 1, high = n - 2;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
        {
            low = mid + 1; // Right me jao
        }
        else
        {
            high = mid; // Left me ya mid pe peak ho sakta hai
        }
    }
    int peak = low; // Peak index mil gaya

    // Step 2: Left part (increasing) me binary search
    int l = 0, r = peak;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int val = mountainArr.get(mid);
        if (val == target)
        {
            cout << mid << endl; // Match mil gaya
            return;
        }
        else if (val < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    // Step 3: Right part (decreasing) me binary search
    l = peak + 1;
    r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int val = mountainArr.get(mid);
        if (val == target)
        {
            cout << mid << endl; // Match mil gaya
            return;
        }
        else if (val > target)
        {
            l = mid + 1; // Decreasing array me right jao
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << -1 << endl; // Target nahi mila
}

int main()
{
    better();
    return 0;
}