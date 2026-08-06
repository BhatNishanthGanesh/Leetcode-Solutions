class Solution {
public:
    int prod(int num){
        int p=1;
        while(num>0){
            p*=(num%10);
            num/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=200;i++){
            int p=prod(i);
            if(p%t==0) return i;
        }
        return -1;
    }
};