class Solution {
public:
    int fib(int n) {

        if(n==0)
            return 0;

        if(n==1)
            return 1;

        return fib(n-1) + fib(n-2);
    }
};


class Solution {
  public:
    int nthFibonacci(int n) {
        
        if(n==0 || n==1)
            return n;
        
        return nthFibonacci(n-1) + nthFibonacci(n-2);
        // code here
    }
};
