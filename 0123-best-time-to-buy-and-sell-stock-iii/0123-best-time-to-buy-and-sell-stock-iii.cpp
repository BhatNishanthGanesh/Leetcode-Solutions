class Solution {
public:
    int solve(int i,bool buy,vector<int>&prices,int k,vector<vector<vector<int>>>&dp){
        if(i>=prices.size()) return 0;
        if(k<0) return 0;
        if(dp[i][buy][k]!=-1e6) return dp[i][buy][k];
        int take=0,sell=0;
        if(buy){
            take=max(-prices[i]+solve(i+1,false,prices,k,dp),solve(i+1,true,prices,k,dp));
        }else{
            sell=max(prices[i]+solve(i+1,true,prices,k-1,dp),solve(i+1,false,prices,k,dp));
        }
        return dp[i][buy][k]=max(take,sell);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1e6)));
        return solve(0,true,prices,1,dp);
    }
};