class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1,false);
        dp[n]=true;
        for(int idx=n-1;idx>=0;idx--){
            for(int i=idx;i<n;i++){
                string word=s.substr(idx,i-idx+1);
                bool f=false;
                for(int j=0;j<wordDict.size();j++){
                    if(wordDict[j]==word){
                        f=true;
                        break;
                    }
                }
                if(f && dp[i+1]){
                    dp[idx]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};