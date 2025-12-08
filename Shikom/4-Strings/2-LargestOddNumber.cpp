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


class Solution:
    def largestOddNumber(self, num: str) -> str:

        # Traverse from rightmost digit to left
        for i in range(len(num) - 1, -1, -1):
            if int(num[i]) % 2 == 1:     # if digit is odd
                return num[:i+1]         # return substring ending here
        
        return ""                        # no odd digit found
