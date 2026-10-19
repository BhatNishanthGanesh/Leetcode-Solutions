class Solution {
public:
    bool solve(int i,vector<int>&nums,int k,vector<vector<int>>&dp){
        if(i>=nums.size() || k<0) return false;
        if(k==0) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        return dp[i][k]=solve(i+1,nums,k-nums[i],dp) || solve(i+1,nums,k,dp);
    }
    bool canPartition(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%2!=0) return false;
        int k=tot/2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(0,nums,k,dp);
    }
};