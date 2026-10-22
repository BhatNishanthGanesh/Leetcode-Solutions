class Solution {
public:
    pair<int,int>solve(int idx,int len,string &s,int tight,vector<vector<pair<int,int>>>&dp){
        if(idx==s.length()){
            return {1,0};
        }
        if(dp[idx][tight].first!=-1) return dp[idx][tight];
        int limit=tight?(s[idx]-'0'):9;
        int ways=0,ones=0;
        for(int d=0;d<=limit;d++){
            int newtight=tight&&(d==s[idx]-'0');
            auto [nways,nones]=solve(idx+1,len,s,newtight,dp);
            ways+=nways;
            ones+=nones;
            if(d==1) ones+=nways;
        }
        return dp[idx][tight]={ways,ones};
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        int len=s.length();
        vector<vector<pair<int,int>>>dp(len,vector<pair<int,int>>(2,{-1,-1}));
        return solve(0,len,s,1,dp).second;
    }
};