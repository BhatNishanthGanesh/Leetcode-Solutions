class Solution {
public:
    const int mod=1e9+7;
    int solve(int idx,string &s,vector<int>&dp){
        if(idx>=s.length()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        unordered_set<char>st;
        int ways=1;
        for(int i=idx;i<s.length();i++){
            if(st.count(s[i])) continue;
            st.insert(s[i]);
            ways=(ways+solve(i+1,s,dp))%mod;
        }
        return dp[idx]=ways%mod;
    }
    int distinctSubseqII(string s) {
        vector<int>dp(s.length(),-1);
        return (solve(0,s,dp)-1+mod)%mod;
    }
};