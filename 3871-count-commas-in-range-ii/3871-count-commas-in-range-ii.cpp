class Solution {
public:
    long long power(long long base,long long exp){
        long long ans=1ll;
        while(exp>0){
            if(exp&1) ans*=base;
            base*=base;
            exp>>=1;
        }
        return ans;
    }
    long long countCommas(long long n) {
        string s=to_string(n);
        int k=(int)(s.length()-1)/3;
        long long c=0;
        for(int i=1;i<=k;i++) c+=max(0ll,n-power(10,3*i)+1);
        return c;
    }
};