class Solution {
public:
    double solve(int n,int k,int i,int j,vector<vector<vector<double>>>&dp){
        if(i<0 || i>=n || j<0 || j>=n) return 0.0;
        if(k==0) return 1.0;
        if(dp[i][j][k]!=-1.0) return dp[i][j][k];
        double prob=0.0;
        vector<pair<int,int>>v={{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
        for(auto [x,y]:v){
            prob+=solve(n,k-1,i+x,j+y,dp)/8.0;
        }
        return dp[i][j][k]=prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1.0)));
        return solve(n,k,row,column,dp);
    }
};