class Solution {
public:
    int solve(int n,int m,string &text1,string &text2,vector<vector<int>>&dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(text1[n]==text2[m]){
            return 1+solve(n-1,m-1,text1,text2,dp);
        }
        return dp[n][m]=max(solve(n-1,m,text1,text2,dp),solve(n,m-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};