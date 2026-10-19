class Solution {
public:
    pair<int,int> solve(int i,int last,vector<int>&nums,vector<vector<pair<int,int>>>&dp){
        if(i>=nums.size()) return {0,1};
        if(dp[i][last+1].first!=-1) return dp[i][last+1];
        pair<int,int>take={-1,0};
        if(last==-1 || nums[i]>nums[last]){
            auto res=solve(i+1,i,nums,dp);
            take={1+res.first,res.second};
        }
        pair<int,int> notTake=solve(i+1,last,nums,dp);
        if(take.first>notTake.first){
            return dp[i][last+1]=take;
        }
        if(notTake.first>take.first){
            return dp[i][last+1]=notTake;
        }
        return dp[i][last+1]={take.first,take.second+notTake.second};
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1,{-1,0}));
        return solve(0,-1,nums,dp).second;
    }
};