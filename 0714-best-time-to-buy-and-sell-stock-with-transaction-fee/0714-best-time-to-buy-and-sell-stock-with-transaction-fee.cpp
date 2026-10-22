class Solution {
public:
    int solve(int i,vector<int>&prices,int fee,vector<vector<int>>&dp,bool f){
        if(i>=prices.size()) return 0;
        if(dp[i][f]!=-1) return dp[i][f];
        int buy=0,sell=0;
        if(f) buy=max(-prices[i]+solve(i+1,prices,fee,dp,false),solve(i+1,prices,fee,dp,true));
        else{
            sell=max(prices[i]-fee+solve(i+1,prices,fee,dp,true),solve(i+1,prices,fee,dp,false));
        }
        return dp[i][f]=max(buy,sell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,prices,fee,dp,true);
    }
};