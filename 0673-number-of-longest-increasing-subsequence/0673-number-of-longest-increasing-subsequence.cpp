class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1,{0,1}));
        for(int i=n-1;i>=0;i--){
            for(int last=i-1;last>=-1;last--){
                pair<int,int> take={0,0};
                if(last==-1 || nums[i]>nums[last]){
                    auto res=dp[i+1][i+1];
                    take={1+res.first,res.second};
                }
                pair<int,int> notTake=dp[i+1][last+1];
                if(take.first>notTake.first){
                    dp[i][last+1]=take;
                    continue;
                }
                if(notTake.first>take.first){
                    dp[i][last+1]=notTake;
                    continue;
                }
                dp[i][last+1]={max(take.first,notTake.first),take.second+notTake.second};
            }
        }
        return dp[0][0].second;
    }
};