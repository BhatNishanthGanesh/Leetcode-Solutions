class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                int left=(i>0)?dp[i-1][j]:INT_MAX;
                int right=(j>0)?dp[i][j-1]:INT_MAX;
                dp[i][j]=min(left,right);
                if(dp[i][j]!=INT_MAX) dp[i][j]+=grid[i][j];

            }
        }
        return dp[n-1][m-1];
    }
};