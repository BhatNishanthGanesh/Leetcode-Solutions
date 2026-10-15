class Solution {
public:
    bool solve(int n,vector<int>&nums,int k,vector<vector<int>>&dp){
        if(n==0){
            if(k==0) return true;
            return false;
        }
        if(k==0) return true;
        if(dp[n][k]!=-1) return dp[n][k];
        bool take=false;
        if(nums[n-1]<=k){
            take=solve(n-1,nums,k-nums[n-1],dp);
        }
        bool skip=solve(n-1,nums,k,dp);
        return dp[n][k]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%2!=0) return false;
        int k=tot/2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,nums,k,dp);
    }
};