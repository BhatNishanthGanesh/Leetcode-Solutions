class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+solve(i+2,nums,dp);
        int skip=solve(i+1,nums,dp);
        return dp[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int temp=nums[0];
        nums.erase(nums.begin());
        vector<int>dp(nums.size(),-1);
        int f=solve(0,nums,dp);
        nums.insert(nums.begin(),temp);
        nums.pop_back();
        vector<int>dp2(nums.size(),-1);
        int s=solve(0,nums,dp2);
        return max(f,s);
    }
};