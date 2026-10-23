class Solution {
public:
    int solve(int i,int j,vector<int>&piles,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int p1=piles[i]-solve(i+1,j,piles,dp);
        int p2=piles[j]-solve(i,j-1,piles,dp);
        return dp[i][j]=max(p1,p2);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        return solve(0,piles.size()-1,piles,dp);
    }
};