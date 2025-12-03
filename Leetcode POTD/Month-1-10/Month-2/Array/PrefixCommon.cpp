#include <bits/stdc++.h>
using namespace std;
void brute()              // O(N)
{
    int a, b, c, i, j, k;
    cin>>a>>b;
    vector<int> A(a);
    vector<int> B(b);
    vector<int> C;
    for (i = 0; i < a; i++)
    {
        cin >> A[i];
    }
    for (i = 0; i < b; i++)
    {
        cin >> B[i];
    }
  

    for (i = 0; i < a; i++)
    {
      int count = 0;
         
        for (j = 0; j <= i; j++)
        {
            int k=0;

           
            while (k <= i)
            {
                if (B[j] == A[k])
                {
                    count++;
                     
                }
                k++;
               
            }
        

        }
         C.push_back(count);
       
    }

    for (i = 0; i <C.size(); i++)
    {
        cout << C[i] << " ";
    }
}

int main()
{
    brute();
    return 0;
}