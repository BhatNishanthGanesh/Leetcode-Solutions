class Solution {
public:
    bool solve(int i,string s,vector<string>&wordDict,vector<int>&dp){
        if(i==s.length()) return true;
        if(dp[i]!=-1) return dp[i];
        for(int idx=i;idx<s.length();idx++){
            string pref=s.substr(i,idx-i+1);
            bool f=false;
            for(int j=0;j<wordDict.size();j++){
                if(pref==wordDict[j]){
                    f=true;
                    break;
                }
            }
            if(f && solve(idx+1,s,wordDict,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        return solve(0,s,wordDict,dp);
    }
};