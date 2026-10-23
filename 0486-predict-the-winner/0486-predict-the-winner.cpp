class Solution {
public:
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int p1=nums[i]-solve(i+1,j,nums,dp);
        int p2=nums[j]-solve(i,j-1,nums,dp);
        return dp[i][j]=max(p1,p2);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(0,nums.size()-1,nums,dp)>=0;
    }
};