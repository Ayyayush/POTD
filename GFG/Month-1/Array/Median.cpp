#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    vector<int>vec;
    vector<double>result;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i=0;i<nums.size();i++)     // O(N)
    {
        vec.push_back(nums[i]);
        sort(vec.begin(),vec.end());     //0(NLOGN)
        if(vec.size()%2==0)
        {
         double median=(vec[vec.size()/2]+vec[(vec.size()/2)-1])/2.0;
         cout<<"1-"<<median<<endl;
         result.push_back(median);
        
        }
        else
        {
        
            double median=(vec[floor(vec.size()/2)]);
            cout<<"2-"<<median<<endl;
            result.push_back(median); 
        }
    }

    for(auto x:result)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
void better() {
    vector<int> arr;  
    int n; 
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        arr.push_back(x);
    }
    
    priority_queue<int> leftmaxheap; // Max heap for left half
    priority_queue<int, vector<int>, greater<int>> rightminheap; // Min heap for right half
    vector<double> ans;
    
    for (int i = 0; i < arr.size(); i++) {
        leftmaxheap.push(arr[i]);
        
        int ele = leftmaxheap.top();
        rightminheap.push(ele);
        leftmaxheap.pop();
        
        if (rightminheap.size() > leftmaxheap.size()) {
            int ele = rightminheap.top();
            leftmaxheap.push(ele);
            rightminheap.pop();
        }
        
        double median;
        if (leftmaxheap.size() != rightminheap.size())
            median = leftmaxheap.top();
        else
            median = (double)(leftmaxheap.top() + rightminheap.top()) / 2;
        
        ans.push_back(median);
    }
    
    for (double med : ans) {
        cout << med << " ";
    }
    cout << endl;
}



int main()
{
better();
return 0;
}