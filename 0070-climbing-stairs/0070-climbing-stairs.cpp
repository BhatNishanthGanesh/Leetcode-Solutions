class Solution {
public:
    int climbStairs(int n) {
        int fib1=1;
        int fib2=1;
        for(int i=2;i<=n;i++){
            int fib3=fib1+fib2;
            fib1=fib2;
            fib2=fib3;
        }
        return fib2;
    }
};