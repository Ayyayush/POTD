class Solution {
public:
    string largestOddNumber(string num) {

        for(int i = num.size() - 1; i >= 0; i--)     // String ko reverse traverse kar rahe hain  
    {
        int numst = num[i] - '0';    // Character ko integer me convert kar rahe hain  

        

        if(numst%2!= 0)    // Agar non-zero digit mil jaye toh baaki string hata deni hai  
        {
            num.erase(num.begin() + i+1, num.end());     // i index se end tak ka part delete kar rahe hain  

            
           
            return num;     // Function se exit ho rahe hain kyunki ek hi change karna hai  
        }
        else
        {
            if(i==0)
            {
              return ""   ;      
                 }
            num.erase(num.begin() + i+1, num.end());     // i index se end tak ka part delete kar rahe hain   
        }
    }
      return num;
        
    }
};


#include <bits/stdc++.h>
using namespace std;
void brute()
{
    string num;
    int i,j,sum=0;
    int maxodd=0;
    getline(cin,num);    // Convert string into an integer array (nums)
    vector<int> nums;
    for (char ch : num) {
        // Convert character to its integer equivalent and store in nums
        nums.push_back(ch - '0');
    }

    // Process the numeric array and find the maximum odd number
    for (int i = 0; i < nums.size(); i++) {
        // Build the number by multiplying sum by 10 and adding current digit
        sum = sum * 10 + nums[i];

        // Check if the current sum is odd
        if (sum % 2 != 0) {
            maxodd = max(sum, maxodd); // Update maxodd if sum is odd
        }
    }

    cout<<maxodd<<endl;
}



void better() {
    string num;
    int sum = 0, maxodd = 0;

    // Input the string
    getline(cin, num);

    // Iterate through each character of the string
    for (char ch : num) {
        // Convert the character to its integer equivalent
        int digit = ch - '0'; // '0' -> 48, so subtract '0' to get the digit

        // Build the number step-by-step
        sum = sum * 10 + digit;

        // Check if the number is odd and update maxodd
        if (sum % 2 != 0) {
            maxodd = max(sum, maxodd);
        }
    }

    // Output the maximum odd sum
    cout << maxodd << endl;
}

int main()
{
brute();
return 0;
}


class Solution:
    def largestOddNumber(self, num: str) -> str:

        # Traverse from rightmost digit to left
        for i in range(len(num) - 1, -1, -1):
            if int(num[i]) % 2 == 1:     # if digit is odd
                return num[:i+1]         # return substring ending here
        
        return ""                        # no odd digit found
