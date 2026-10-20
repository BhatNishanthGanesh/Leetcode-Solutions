class Solution {
public:
    int solve(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(n<0 || m<0) return INT_MAX;
        if(n==0 && m==0) return grid[0][0];
        if(dp[n][m]!=-1) return dp[n][m];
        int left=solve(n-1,m,grid,dp);
        if(left!=INT_MAX) left+=grid[n][m];
        int right=solve(n,m-1,grid,dp);
        if(right!=INT_MAX) right+=grid[n][m];
        return dp[n][m]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,grid,dp);
    }
};