class Solution {
public:
    int solve(int i,vector<int>&nums,int k,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(k==0) return 1;
            return 0;
        }
        if(k<0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int take=solve(i+1,nums,k-nums[i],dp);
        int skip=solve(i+1,nums,k,dp);
        return dp[i][k]=take+skip;
    }
    int findTargetSumWays(vector<int>& nums, int k) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot<abs(k)) return 0;
        if((tot+k)%2!=0) return 0;
        int s=(tot+k)/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(s+1,-1));
        return solve(0,nums,s,dp);
    }
};