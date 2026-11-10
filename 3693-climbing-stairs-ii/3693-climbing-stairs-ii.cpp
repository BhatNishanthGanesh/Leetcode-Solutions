class Solution {
public:
    int func(int i,int last){
        return ((i-last)*(i-last));
    }
    int solve(int i,int n,vector<int>&costs,vector<int>&dp){
        if(i>n) return INT_MAX;
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take1=solve(i+1,n,costs,dp);
        int take2=solve(i+2,n,costs,dp);
        int take3=solve(i+3,n,costs,dp);
        if(take1!=INT_MAX) take1+=costs[i]+func(i+1,i);
        if(take2!=INT_MAX) take2+=costs[i+1]+func(i+2,i);
        if(take3!=INT_MAX) take3+=costs[i+2]+func(i+3,i);
        return dp[i]=min(take1,min(take2,take3));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return solve(0,n,costs,dp);
    }
};