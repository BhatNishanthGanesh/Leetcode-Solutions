class Solution {
public:
    int solve(int i,string &s,vector<int>&dp){
        if(i>=s.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ways=0;
        if(s[i]!='0') ways+=solve(i+1,s,dp);
        if(i+2<=s.length()){
            int num=stoi(s.substr(i,2));
            if(num>=10 && num<=26) ways+=solve(i+2,s,dp);
        }
        return dp[i]=ways;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return solve(0,s,dp);
    }
};