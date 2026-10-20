class Solution {
public:
    int solve(int i,vector<string>&strs,int m,int n,vector<vector<vector<int>>>&dp){
        if(i>=strs.size() || m<0 || n<0) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int ones=count(strs[i].begin(),strs[i].end(),'1');
        int zeroes=(int)strs[i].length()-ones;
        int take=0;
        if(m-zeroes>=0 && n-ones>=0) take=1+solve(i+1,strs,m-zeroes,n-ones,dp);
        int skip=solve(i+1,strs,m,n,dp);
        return dp[i][m][n]=max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,strs,m,n,dp);
    }
};