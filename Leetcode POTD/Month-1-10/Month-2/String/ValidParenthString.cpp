#include <bits/stdc++.h>
using namespace std;


void brute()
{
    int i,j,count=0,count1=0,count2=0;
    string str;
    getline(cin,str);
    if(str.size()==0)
    return ;

    for(i=0;i<str.size();i++)
    {
            if(str[i]=='(')
            count1++;
            if(str[i]==')')
            count2++;
           
                 
                 if(count1==count2)
                 {
                   count1=0;
                   count2=0;
                 }
          
        
        
    }
    if(abs(count1-count2)==1)
        {
            if(str.find('*')!=string::npos)
            { 
                count1<count2?count1++:count2++;
            }
        }
    if(count1==count2)
    cout<<"True";
    else
    cout<<"False";


}


void better()
{
       int count1 = 0, count2 = 0;  // count1 for min_open, count2 for max_open
    string str;
    getline(cin, str);
    
    if (str.size() == 0) 
        return;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            count1++;  // treat '(' as increasing min_open and max_open
            count2++;  // increment max_open as well
        }
        else if (str[i] == ')') {
            count1--;  // treat ')' as decreasing min_open
            count2--;  // treat ')' as decreasing max_open
        }
        else if (str[i] == '*') {
            count1--;  // treat '*' as a ')', so we decrement min_open
            count2++;  // treat '*' as a '(', so we increment max_open
        }

        // Ensure count1 doesn't go below 0 (since '*' can be empty string)
        if (count1 < 0) 
            count1 = 0;

        // If count2 becomes negative, there are more closing parentheses than opening ones
        if (count2 < 0) {
            cout << "False" << endl;
            return;
        }
    }

    // At the end, we check if count1 == 0, meaning all parentheses are balanced
    if (count1 == 0) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}




void optimal()            //O(N)     S.C==O(N)
{
       int i,j,count=0,count1=0,count2=0;
    string str;
    char k;
    getline(cin,str);
    stack<char>stk;

    for(i=0;i<str.size();i++)
    {
        if(str[i]!=')')
        stk.push(str[i]);
        else
        {
            if(stk.top()=='('  && !stk.empty())            // question mein diya h valid string h isliye empty check nhi krna 
            {
                count1++;
                count2++;
                break;
               
            }
            while(stk.top()!='(')
            {
                if(stk.top()=='*')
                k='*';
                stk.pop();
                
            }
            stk.push(k);
             
            stk.pop();
        }
    }
     if(abs(count1-count2)==1)
        {
            if(str.find('*')!=string::npos)
            {
                count1<count2?count1++:count2++;
            }
        }
   
    if(count1==count2)
    cout<<"True";
    else
    cout<<"False";


}


int main()
{
bett();
return 0;
}