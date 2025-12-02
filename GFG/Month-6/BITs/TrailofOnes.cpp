/**
 * *TRAIL OF ONES - AMAZON
 * Multiple approaches are there to solve it 
 * pehla hint toh yhi h ki constraint bhot low h
 * 
 * 
 * Recursion
 * 
 * 
 * Optimal Manner
 * jitni n ki length h 
 * 2^n binary strings bna skte h n length ki 
 * eg n=2  00 , 01, 11, 10
 * ans ==2
 * aise strings btane h jisme atleast 1 pair of consecutive strings ho
 * 
 * eg:;= n=3
 * 000,001,010,011,100,101,110,111
 * ans= 3
 * 
 * similary n=4 ke liye ans =8
 *          n=5 ke liye ans =19
 * 
 * kuch pattern bante dikh rha h ?
 * hn sablko double krke usme kuch add kr de toh agla ban rha h
 * 1,2,8,19,43,94
 * 
 * n = 2 → 1   = 0 * 2 + 1
 * n = 3 → 3   = 1 × 2 + 1
 * n = 4 → 8   = 3 × 2 + 2
 * n = 5 → 19  = 8 × 2 + 3
 * n = 6 → 43 = 19 × 2 + 5
 * n = 7 → 94 = 43 × 2 + 8
 * 
 * toh hume dikhta h ki fibonacci sequence add ho rha h 
 * 
 *
 * 
 * 
 */

 class Solution {
  public:
    int countConsec(int n) {
        // code here
        if(n==2)
        return 1;
        
        int first=0,second=1,third,result=1;
        for(int i=3;i<=n;i++)
        {
            third=first+second;
            result=result*2 + third;
            
            first=second;
            second=third;
            
        }
        return result;
    }
};