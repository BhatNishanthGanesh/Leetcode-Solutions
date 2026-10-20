class Solution {
public:
    int solve(int i,vector<int>&stones,int target,vector<vector<int>>&dp){
        if(i>=stones.size() || target<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int take=0;
        if(target-stones[i]>=0) take=stones[i]+solve(i+1,stones,target-stones[i],dp);
        int skip=solve(i+1,stones,target,dp);
        return dp[i][target]=max(take,skip);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int tot=accumulate(stones.begin(),stones.end(),0);
        int target=tot/2;
        int n=stones.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int best=solve(0,stones,target,dp);
        return tot-2*best;
    }
};