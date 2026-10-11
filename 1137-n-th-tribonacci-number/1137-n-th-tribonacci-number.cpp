class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        int fib1=0,fib2=1,fib3=1;
        for(int i=3;i<=n;i++){
            int fib4=fib1+fib2+fib3;
            fib1=fib2;
            fib2=fib3;
            fib3=fib4;
        }
        return fib3;
    }
};