class Solution {
public:
    vector<int>perfectSq(int n){
        vector<int>v;
        for(int i=1;i*i<=n;i++){
            v.push_back(i*i);
        }
        return v;
    }

    int solve(int i,int k,vector<int>&v,vector<vector<int>>&dp){
        if(i>=v.size() || k<0) return INT_MAX;
        if(k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int take=INT_MAX;
        if(k-v[i]>=0) take=solve(i,k-v[i],v,dp);
        if(take!=INT_MAX) take++;
        int skip=solve(i+1,k,v,dp);
        return dp[i][k]=min(take,skip);
    }

    int numSquares(int n) {
        vector<int>v=perfectSq(n);
        vector<vector<int>>dp(v.size()+1,vector<int>(n+1,-1));
        return solve(0,n,v,dp);
    }
};