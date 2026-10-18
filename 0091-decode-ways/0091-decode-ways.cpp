class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0 || s[0]=='0') return 0;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int left=(s[i-1]!='0')?dp[i-1]:0;
            int num=stoi(s.substr(i-2,2));
            int right=(num>=10 && num<=26)?dp[i-2]:0;
            dp[i]=left+right;
        }
        return dp[n];
    }
};