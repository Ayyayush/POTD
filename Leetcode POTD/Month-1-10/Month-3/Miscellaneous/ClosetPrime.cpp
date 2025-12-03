#include <bits/stdc++.h>
using namespace std;

void brute() // 0(N^2)
{
    vector<int> vec;           //  Prime numbers store karne ke liye vector
    vector<int> result(2, -1); //  Default result [-1, -1] agar pair na mile toh

    for (int i = left; i <= right; i++)
    {
        int f = 0;
        for (int j = 2; j < i; j++) //  Har number ke liye check kar rahe hain ki prime hai ya nahi
        {
            if (i % j == 0) //  Agar divisible ho gaya toh prime nahi hai
            {
                f++;
                break;
            }
        }
        if (f == 0)
        {
            vec.push_back(i); //  Prime number vector me daal diya
        }
    }

    //  Agar prime numbers 1 ya usse kam mile toh default result print karo
    if (vec.size() <= 1)
    {
        for (auto x : result)
            cout << x << " ";
        return; //  Execution yahi khatam kar diya
    }

    long long minimum = INT_MAX; //  Minimum difference store karne ke liye variable

    //  Closest prime pair dhoondhna
    for (int i = 0; i < vec.size(); i++)
    {
        if ((i + 1 < vec.size()) && abs(vec[i] - vec[i + 1]) < minimum)
        {
            minimum = abs(vec[i] - vec[i + 1]); //  Minimum distance update kar rahe hain
            l = vec[i];
            r = vec[i + 1];
        }
    }

    result[0] = l;
    result[1] = r;

    //  Output print karna
    for (auto x : result)
        cout << x << " ";
}

void better()
{

    bool isPrime(int n)
    {
        if (n < 2)
            return false; //  2 se chhote numbers prime nahi hote
        for (int i = 2; i * i <= n; i++)
        { //  Sirf √N tak check kar rahe hain
            if (n % i == 0)
                return false; //  Agar kisi se divide ho gaya toh prime nahi hai
        }
        return true;
    }

    void better()
    {
        int left, right, l, r;
        cin >> left >> right; //  Left aur right range input le rahe hain

        vector<int> vec, result(2, -1); //  Prime numbers aur result store karne ke liye vector

        //  Prime numbers dhoondhna optimized method se (√N check)
        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
                vec.push_back(i); //  Agar prime hai toh vector me daal diya
        }

        //  Agar prime numbers ek ya kam mile toh default result print karna
        if (vec.size() <= 1)
        {
            for (auto x : result)
                cout << x << " ";
            return;
        }

        long long minimum = INT_MAX; //  Minimum difference track karne ke liye

        //  Closest prime pair dhoondhna
        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (abs(vec[i] - vec[i + 1]) < minimum)
            {
                minimum = abs(vec[i] - vec[i + 1]); //  Minimum distance update kar rahe hain
                l = vec[i];                         //  Pair ka first element
                r = vec[i + 1];                     //  Pair ka second element
            }
        }

        result[0] = l;
        result[1] = r;

        //  Output print karna
        for (auto x : result)
            cout << x << " ";
    }
}

int main()
{
    brute(); //  Brute-force function call kiya
    return 0;
}
