class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%2!=0) return false;
        int k=tot/2;
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                bool take=false;
                if(nums[i-1]<=j){
                    take=dp[i-1][j-nums[i-1]];
                }
                bool skip=dp[i-1][j];
                dp[i][j]=take||skip;
            }
        }
        return dp[n][k];
    }
};