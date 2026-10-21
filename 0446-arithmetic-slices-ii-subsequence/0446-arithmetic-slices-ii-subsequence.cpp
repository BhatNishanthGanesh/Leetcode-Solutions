class Solution {
public:
    int solve(int i,long long diff,vector<int>&nums,vector<unordered_map<long long,int>>&dp){
        if(i<0) return 0;
        if(dp[i].count(diff)) return dp[i][diff];
        int ways=0;
        for(int j=0;j<i;j++){
            if(1ll*nums[i]-nums[j]==diff){
                ways+=1+solve(j,diff,nums,dp);
            }
        }
        return dp[i][diff]=ways;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        vector<unordered_map<long long,int>>dp(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=1ll*nums[i]-nums[j];
                cnt+=solve(j,diff,nums,dp);
            }
        }
        return cnt;
    }
};