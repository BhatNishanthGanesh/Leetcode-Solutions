class Solution {
public:
    int solve(int i,vector<int>&v,vector<int>&costs,vector<int>&dp){
        if(i>=v.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take1=costs[0]+solve(i+1,v,costs,dp);
        int j=i;
        while(j<v.size() && v[j]<v[i]+7) j++;
        int take2=costs[1]+solve(j,v,costs,dp);
        j=i;
        while(j<v.size() && v[j]<v[i]+30) j++;
        int take3=costs[2]+solve(j,v,costs,dp);
        return dp[i]=min({take1,take2,take3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(0,days,costs,dp);
    }
};