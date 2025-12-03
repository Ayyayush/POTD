#include <bits/stdc++.h>
using namespace std;

void naive()
{
    // using stl 
}

void brute()     //     o(nlogn)
{

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int maxi,secmaxi=-1;
            
    sort(arr.begin(),arr.end());
    maxi=arr[arr.size()-1];
    
    for(int i=arr.size()-1;i>=0;i--)
    {
       if(arr[i]!=maxi) 
       {
            secmaxi=arr[i];
            break;
           
          
       }
    }
    cout<<secmaxi<<endl;
    
}


void better()
{
    // Time Complexity: O(N)  ........ (Two-pass method)
    // Space Complexity: O(1)  ........ (No extra space used)
    
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int largest = INT_MIN, secondLargest = INT_MIN;

    // Pehle largest element find karenge
    for (int i = 0; i < n; i++)
        largest = max(largest, arr[i]);

    // Ab doosri baar traverse karenge to find second largest
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != largest)
            secondLargest = max(secondLargest, arr[i]);
    }

    cout << "Second largest element: " << secondLargest << endl;
}


void optimal()         // O(N)      s.c==O(1)
{
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

int maxi=-1,secmaxi=-1;
        
for(int i=0;i<arr.size();i++)
{
  if(arr[i]>maxi)
  {
    secmaxi=maxi;
    maxi=arr[i];
  }
  if(arr[i]<maxi && arr[i]>secmaxi)
  {
    secmaxi=arr[i];
  }
}
cout<<secmaxi<<endl;

}


int main()
{
better();
return 0;
}