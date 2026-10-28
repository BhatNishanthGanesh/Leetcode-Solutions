class Solution {
public:
    int solve(int xr,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(n<0 || m<0) return INT_MAX;
        xr^=grid[n][m];
        if(n==0 && m==0) return xr;
        if(dp[n][m][xr]!=-1) return dp[n][m][xr];
        int left=solve(xr,n,m-1,grid,dp);
        int up=solve(xr,n-1,m,grid,dp);
        return dp[n][m][xr]=min(left,up);
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int xr=0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(1024,-1)));
        return solve(xr,n-1,m-1,grid,dp);
    }
};