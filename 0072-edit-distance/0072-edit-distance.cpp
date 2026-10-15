class Solution {
public:
    int solve(int n,int m,string &word1,string &word2,vector<vector<int>>&dp){
        if(n<0) return m+1;
        if(m<0) return n+1;
        if(dp[n][m]!=-1) return dp[n][m];
        if(word1[n]==word2[m]){
            return solve(n-1,m-1,word1,word2,dp);
        }
        return dp[n][m]=min({1+solve(n,m-1,word1,word2,dp),1+solve(n-1,m-1,word1,word2,dp),1+solve(n-1,m,word1,word2,dp)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};