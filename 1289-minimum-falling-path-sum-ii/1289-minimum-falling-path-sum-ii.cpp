class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int sum=INT_MAX;
        if(i==grid.size()-1){
            for(int k=0;k<grid[0].size();k++){
                if(j==k) continue;
                sum=min(sum,grid[i][k]);
            }
            return sum;
        }
        if(dp[i][j]!=-1e4) return dp[i][j];
        for(int k=0;k<grid[0].size();k++){
            if(j==k) continue;
            sum=min(sum,grid[i][k]+solve(i+1,k,grid,dp));
        }
        return dp[i][j]=sum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini=INT_MAX;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1e4));
        for(int i=0;i<m;i++){
            int val=solve(1,i,grid,dp);
            if(val==INT_MAX) val=0;
            mini=min(mini,grid[0][i]+val);
        }
        return mini;
    }
};