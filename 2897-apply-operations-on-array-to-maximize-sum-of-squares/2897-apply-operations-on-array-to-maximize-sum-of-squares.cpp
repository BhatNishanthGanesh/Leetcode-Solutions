class Solution {
public:
    const int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>occ(32);
        for(int ele:nums){
            for(int i=31;i>=0;i--){
                if(ele&(1<<i)) occ[i]++;
            }
        }
        long long ans=0;
        while(k>0){
            int x=0;
            for(int i=31;i>=0;i--){
                if(occ[i]>0){
                    x|=(1<<i);
                    occ[i]--;
                }
            }
            ans+=(1ll*x*x)%mod;
            k--;
        }
        return ans%mod;
    }
};