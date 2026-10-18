class Solution {
public:
    const int mod=1e9+7;
    vector<long long>fact,inv;
    long long modpow(long long base,long long exp){
        long long res=1;
        while(exp>0){
            if(exp&1) res=res*base%mod;
            base=base*base%mod;
            exp>>=1;
        }
        return res%mod;
    }
    long long comb(int a,int b){
        if(b<0 || b>a) return 0;
        return fact[a]*inv[b]%mod*inv[a-b]%mod;
    }
    long long ways(vector<int>&nums){
        int n=nums.size();
        if(n<=2) return 1;
        vector<int>left,right;
        for(int x:nums){
            if(x<nums[0]) left.push_back(x);
            else if(x>nums[0]) right.push_back(x);
        }
        return comb(n-1,left.size())*ways(left)%mod*ways(right)%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        fact.resize(n+1,1);
        inv.resize(n+1,1);
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
        inv[n]=modpow(fact[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        return (ways(nums)-1+mod)%mod;
    }
};