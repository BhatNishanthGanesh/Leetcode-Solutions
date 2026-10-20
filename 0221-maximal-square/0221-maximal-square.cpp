class Solution {
public:
    int solve(int n,int m,vector<vector<char>>&matrix,vector<vector<int>>&dp){
        if(n<0 || m<0) return 0;
        if(matrix[n][m]=='0') return 0;
        if(n==0 || m==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=solve(n-1,m,matrix,dp);
        int left=solve(n,m-1,matrix,dp);
        int diag=solve(n-1,m-1,matrix,dp);
        return dp[n][m]=1+min({left,up,diag});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int mx=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    mx=max(mx,solve(i,j,matrix,dp));
                }
            }
        }
        return mx*mx;
    }
};