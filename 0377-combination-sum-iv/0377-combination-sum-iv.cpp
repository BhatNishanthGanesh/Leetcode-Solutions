class Solution {
public:
    int solve(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int ways=0;
        for(int idx=0;idx<nums.size();idx++){
            ways+=solve(idx,nums,target-nums[idx],dp);
        }
        return dp[i][target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};