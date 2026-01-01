#include <bits/stdc++.h>
using namespace std;




void naive ()
{
    int result=0,count=0,s;
    cin>>s;
    vector<int> nums(s);
    for (int i = 0; i < s; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    int last=(nums[nums.size()-1]);
    string str = to_string(last);
    int size=str.size();
    cout<<size<<endl;
    
   
    for (int j = 0; j < pow(2 , size); j++)
    {
        count = 0;
       
        for (int i = 0; i < nums.size(); i++)
        {
            
            if (((bitset<16>(to_string(nums[j])))^ i) == 0)
            {
              
                count++;
            }
        }
        if (count == 0)
        {
            result = j;
            break;
        }
    }
   
     if(size==2)
    cout << bitset<2>(result) << endl; // Convert number to binary using bitset and print
    else if(size==3)
    cout << bitset<3>(result) << endl; // Convert number to binary using bitset and print
   else  if(size==4)
    cout << bitset<4>(result) << endl; // Convert number to binary using bitset and print
     else if(size==5)
    cout << bitset<5>(result) << endl; // Convert number to binary using bitset and print
}


void brute()
{
    // T.C : O(n^2) - Iterating on each string and converting each character to integer
    // S.C : O(n) - Using unordered set

    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> st;
    for (string &num : nums)
    {
        st.insert(stoi(num, 0, 2)); // Convert binary string to integer and insert in set
    }

    string result = "";
    for (int number = 0; number <= 65536; number++) // Checking for first missing number up to 65536
    {
        if (st.find(number) == st.end()) // If number is not found in set, return it
        {
            result = bitset<16>(number).to_string(); // Convert number to 16-bit binary string
            break;
        }
    }
    cout << result.substr(16 - n) << endl; // Extract required length of binary string
}



void better()
{
    // T.C : O(n^2) - Iterating on each string and converting each character to integer
    // S.C : O(n) - Using unordered set

    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> st;
    for (string &num : nums)
    {
        st.insert(stoi(num, 0, 2)); // Convert binary string to integer and insert in set
    }

    string result = "";
    for (int number = 0; number <= n; number++) // Only checking up to n instead of 65536
    {
        if (st.find(number) == st.end()) // If number is not found in set, return it
        {
            result = bitset<16>(number).to_string(); // Convert number to 16-bit binary string
            break;
        }
    }
    cout << result.substr(16 - n) << endl; // Extract required length of binary string
}



void optimal()
{
    // T.C : O(n) - One pass checking and constructing missing binary string
    // S.C : O(1) - No extra space used

    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    string result;
    for (int i = 0; i < n; i++)
    {
        char ch = nums[i][i]; // Extract diagonal character
        result += (ch == '0') ? "1" : "0"; // Flip '0' to '1' and '1' to '0'
    }

    cout << result << endl;
}

int main()
{
    // brute();  // Uncomment to run brute force approach
    // better(); // Uncomment to run better approach
    optimal(); // Runs optimal approach
    return 0;
}
