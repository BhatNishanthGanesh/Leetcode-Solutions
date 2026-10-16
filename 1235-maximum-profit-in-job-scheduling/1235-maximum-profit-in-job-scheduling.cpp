class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<tuple<int,int,int>>v;
        for(int i=0;i<n;i++) v.push_back({startTime[i],endTime[i],profit[i]});
        sort(v.begin(),v.end());
        vector<int>dp(n+1);
        for(int i=n-1;i>=0;i--){
            int nxt=lower_bound(v.begin()+i+1,v.end(),make_tuple(get<1>(v[i]),INT_MIN,INT_MIN))-v.begin();
            dp[i]=max(dp[i+1],get<2>(v[i])+dp[nxt]);
        }
        return dp[0];
    }
};