class Solution {
public:
    int solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(i>=coins.size() || amount<0) return INT_MAX;
        if(amount==0){
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=solve(i,coins,amount-coins[i],dp);
        if(take!=INT_MAX){
            take+=1;
        }
        int skip=solve(i+1,coins,amount,dp);
        return dp[i][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(),coins.rend());
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=solve(0,coins,amount,dp);
        return ans==INT_MAX?-1:ans;
    }
};