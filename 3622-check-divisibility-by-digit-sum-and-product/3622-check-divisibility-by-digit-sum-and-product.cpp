class Solution {
public:
    bool solve(int n){
        long long sum=0,prod=1;
        long long num=n;
        while(num>0){
            int digi=num%10;
            sum+=digi;
            prod*=digi;
            num/=10;
        }
        cout<<sum<<" "<<prod<<endl;
        return n%(sum+prod)==0;
    }
    bool checkDivisibility(int n) {
        return solve(n);       
    }
};