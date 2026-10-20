class Solution {
public:
    int solve(int n,int m,vector<vector<int>>&v,vector<vector<int>>&dp){
        if(n<0 || m<0) return 0;
        if(n==0 && m==0) return 1;
        if(v[n][m]==1) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m]=solve(n-1,m,v,dp)+solve(n,m-1,v,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        if(v[0][0]==1 || v[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,v,dp);
    }
};