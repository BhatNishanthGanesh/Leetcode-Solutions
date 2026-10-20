class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=1;i<=amount;i++) dp[n][i]=INT_MAX;
        for(int i=n-1;i>=0;i--){
            for(int a=0;a<=amount;a++){
                int take=INT_MAX;
                if(a-coins[i]>=0) take=dp[i][a-coins[i]];
                if(take!=INT_MAX) take++;
                int skip=dp[i+1][a];
                dp[i][a]=min(take,skip);
            }
        }
        return dp[0][amount]==INT_MAX?-1:dp[0][amount];
    }
};