class Solution {
public:
    pair<int,int>solve(int idx,string &s,int tight,vector<vector<pair<int,int>>>&dp){
        if(idx==s.length()){
            return {1,0};
        }
        if(dp[idx][tight].first!=-1) return dp[idx][tight];
        int limit=(tight)?s[idx]-'0':9;
        int ways=0,ones=0;
        for(int i=0;i<=limit;i++){
            int newTight=tight && (i==s[idx]-'0');
            auto [nways,nones]=solve(idx+1,s,newTight,dp);
            ways+=nways;
            ones+=nones;
            if(i==1) ones+=nways;
        }
        return dp[idx][tight]={ways,ones};
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        vector<vector<pair<int,int>>>dp(s.length(),vector<pair<int,int>>(2,{-1,-1}));
        return solve(0,s,1,dp).second;
    }
};