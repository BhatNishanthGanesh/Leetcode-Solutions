class Solution {
public:
    bool solve(int i,int k,vector<int>&stones,vector<vector<int>>&dp){
        if(i==stones.size()-1) return true;
        if(i>=stones.size()) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        bool valid=false;
        int f=lower_bound(stones.begin(),stones.end(),stones[i]+k-1)-stones.begin();
        if(f<stones.size() && k>1){
            if(stones[f]==stones[i]+k-1) valid=valid||solve(f,stones[f]-stones[i],stones,dp);
        }
        int s=lower_bound(stones.begin(),stones.end(),stones[i]+k)-stones.begin();
        if(s<stones.size()){
            if(stones[s]==stones[i]+k) valid=valid||solve(s,stones[s]-stones[i],stones,dp);
        }
        int t=lower_bound(stones.begin(),stones.end(),stones[i]+k+1)-stones.begin();
        if(t<stones.size()){
            if(stones[t]==stones[i]+k+1) valid=valid||solve(t,stones[t]-stones[i],stones,dp);
        }
        return dp[i][k]=valid;
    }
    bool canCross(vector<int>& stones) {
        if(stones[0]+1<stones[1]) return false;
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        return solve(1,1,stones,dp);
    }
};