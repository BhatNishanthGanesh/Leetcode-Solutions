class Solution {
public:
    long long solve(int i,int j,vector<int>&cuts,vector<vector<long long>>&dp){
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long mini=LLONG_MAX;
        for(int k=i+1;k<j;k++){
            long long steps=cuts[j]-cuts[i]+solve(i,k,cuts,dp)+solve(k,j,cuts,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int N=cuts.size();
        vector<vector<long long>>dp(N+1,vector<long long>(N+1,-1));
        return (int)solve(0,N-1,cuts,dp);
    }
};