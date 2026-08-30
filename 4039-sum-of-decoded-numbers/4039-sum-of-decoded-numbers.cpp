class Solution {
public:
    const int mod=1e9+7;
    vector<long long>helper(long long width,long long d){
        long long temp=d;
        long long digits=0;
        while(temp>0){
            temp/=10;
            digits++;
        }
        long long p=1;
        for(int i=0;i<digits-width;i++){
            p*=10;
        }
        return {d/p,d%p};
    }
    long long pw(long long base,long long exp){
        long long p=1;
        base%=mod;
        while(exp>0){
            if(exp&1) p=(p*base)%mod;
            base=base*base%mod;
            exp>>=1;
        }
        return p%mod;
    }
    int sumDecoded(vector<long long>& nums) {
        int sum=0;
        for(long long ele:nums){
            long long width=ele%10;
            long long d=ele/10;
            vector<long long>v=helper(width,d);
            long long x=v[0];
            long long y=v[1];
            long long p=pw(x,y);
            sum=(sum+p)%mod;
        }
        return sum;
    }
};