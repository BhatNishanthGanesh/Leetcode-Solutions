class Solution {
public:
    int solve(int i,vector<int>&prices,int k,bool buy,vector<vector<vector<int>>>&dp){
        if(i>=prices.size() || k<=0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int b=0,s=0;
        if(buy){
            b=max(-prices[i]+solve(i+1,prices,k,false,dp),solve(i+1,prices,k,true,dp));
        }else{
            s=max(prices[i]+solve(i+1,prices,k-1,true,dp),solve(i+1,prices,k,false,dp));
        }
        return dp[i][buy][k]=max(b,s);
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,prices,k,true,dp);
    }
};