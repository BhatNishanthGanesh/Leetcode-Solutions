class Solution {
public:
    int solve(int i,vector<int>&prices,bool buy,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+solve(i+1,prices,false,dp),solve(i+1,prices,true,dp));
        }
        return dp[i][buy]=max(prices[i]+solve(i+2,prices,true,dp),solve(i+1,prices,false,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,prices,true,dp);
    }
};