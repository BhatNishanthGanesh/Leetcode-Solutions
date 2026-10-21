class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(j<0 || j>=matrix[0].size()) return INT_MAX;
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j]!=-1e7) return dp[i][j];
        int left=solve(i+1,j-1,matrix,dp);
        int down=solve(i+1,j,matrix,dp);
        int right=solve(i+1,j+1,matrix,dp);
        int mn=min({left,down,right});
        if(mn!=INT_MAX) return dp[i][j]=matrix[i][j]+mn;
        return mn;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1e7));
        int mn=INT_MAX;
        for(int i=0;i<m;i++){
            mn=min(mn,solve(0,i,matrix,dp));
        }
        return mn;
    }
};