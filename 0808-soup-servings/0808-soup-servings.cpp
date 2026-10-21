class Solution {
public:
    double dfs(int A,int B,vector<vector<double>>&dp){
        if(A<=0 && B>0) return 1.0;
        if(A<=0 && B<=0) return 0.5;
        if(A>0 && B<=0) return 0.0;
        if(dp[A][B]!=-1.0) return dp[A][B];
        return dp[A][B]=0.25*(dfs(A-4,B,dp)+dfs(A-3,B-1,dp)+dfs(A-2,B-2,dp)+dfs(A-1,B-3,dp));
    }
    double soupServings(int n) {
        if(n>5000) return 1.0;
        int N=ceil(n/25.0);
        vector<vector<double>>dp(N+1,vector<double>(N+1,-1.0));
        return dfs(N,N,dp);
    }
};