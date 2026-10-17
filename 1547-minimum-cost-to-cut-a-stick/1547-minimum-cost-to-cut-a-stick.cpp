class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int N=cuts.size();
        vector<vector<long long>>dp(N+1,vector<long long>(N+1,0));
        for(int i=n-2;i>=0;i--){
            for(int j=i+2;j<N;j++){
                long long mini=LLONG_MAX;
                for(int k=i+1;k<j;k++){
                    long long steps=cuts[j]-cuts[i]+dp[i][k]+dp[k][j];
                    mini=min(mini,steps);
                }
                dp[i][j]=mini;
            }
        }
        return dp[0][N-1];
    }
};