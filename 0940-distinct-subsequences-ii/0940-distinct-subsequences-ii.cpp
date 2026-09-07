class Solution {
public:
    const int mod=1e9+7;
    long long solve(int idx,string &s,vector<long long>&dp){
        if(idx==s.length()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        long long ans=1;
        unordered_set<int>st;
        for(int i=idx;i<s.length();i++){
            if(st.count(s[i])) continue;
            st.insert(s[i]);
            ans=(ans+solve(i+1,s,dp))%mod;
        }
        return dp[idx]=ans;
    }
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<long long>dp(n,-1);
        long long tot=solve(0,s,dp);
        return (int)(tot-1+mod)%mod;
    }
};