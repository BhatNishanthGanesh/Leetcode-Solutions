class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        int k=(tot+target)/2;
        if(tot<abs(target)) return 0;
        if((tot+target)%2!=0) return 0;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int take=0;
                if(nums[i-1]<=j){
                    take=dp[i-1][j-nums[i-1]];
                }
                int skip=dp[i-1][j];
                dp[i][j]=take+skip;
            }
        }
        return dp[n][k];
    }
};