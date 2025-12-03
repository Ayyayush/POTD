#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int ct1,ct2,s1,s2,i,j,k,flag=0;
    cin >> s1 >> s2;
    cin.ignore();
    
    vector<string> words1(s1);
    for (i = 0; i < s1; i++)
    {
        getline(cin, words1[i]);
    }

    vector<string> words2(s2);
    for (i = 0; i < s2; i++)
    {
        getline(cin, words2[i]);
    }

    for (i = 0; i < words1.size(); i++)
    {
        ct1=0;
        ct2=0;
         ct1=count(words1.begin(),words1.end(),words1[i]);
        for (j = 0; j < words2.size(); j++)
        {
          ct2=count(words2.begin(),words2.end(),words1[i]);
         
         if(ct1==ct2)
         {
            flag++;
            break;
         }


        }

}
cout<<flag<<endl;
}

void better()
{
     int ct1,ct2,s1,s2,i,j,k,flag=0;
    cin >> s1 >> s2;
    cin.ignore();
    
    vector<string> words1(s1);
    for (i = 0; i < s1; i++)
    {
        getline(cin, words1[i]);
    }

    vector<string> words2(s2);
    for (i = 0; i < s2; i++)
    {
        getline(cin, words2[i]);
    }

    for (i = 0; i < words1.size(); i++)
    {
        ct1=0;
        ct2=0;
         ct1=count(words1.begin(),words1.end(),words1[i]);
          ct2=count(words2.begin(),words2.end(),words1[i]);
         
         if(ct1==ct2)
         {
            flag++;
            
         }


        

}
cout<<flag<<endl;
}



void optimal()


{
     int ct1,ct2,s1,s2,i,j,k,flag=0;
    cin >> s1 >> s2;
    cin.ignore();
    
    vector<string> words1(s1);
    for (i = 0; i < s1; i++)
    {
        getline(cin, words1[i]);
    }

    vector<string> words2(s2);
    for (i = 0; i < s2; i++)
    {
        getline(cin, words2[i]);
    }

  for (i = 0; i < words1.size(); i++)
    {
        ct1=0;
        ct2=0;
         ct1=count(words1.begin(),words1.end(),words1[i]);
          ct2=count(words2.begin(),words2.end(),words1[i]);
         
         if(ct1==ct2)
         {
            flag++;
            
         }


        

}
cout<<flag<<endl;
}




int main()
{
optimal();
return 0;
}
