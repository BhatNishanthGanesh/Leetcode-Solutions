class Solution {
public:
    const int mod=1e9+7;
    int solve(int i,int j,int last,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i>=n || i<0 || j>=m || j<0) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j][last+1]!=-1) return dp[i][j][last+1];
        int right=0;
        int down=0;
        if(grid[i][j]==1){
            if(last==0) down=solve(i+1,j,1,n,m,grid,dp);
            else right=solve(i,j+1,0,n,m,grid,dp);
        }else{
            right=solve(i,j+1,0,n,m,grid,dp);
            down=solve(i+1,j,1,n,m,grid,dp);
        }
        return dp[i][j][last+1]=(right+down)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return solve(0,0,-1,n,m,grid,dp);
    }
};