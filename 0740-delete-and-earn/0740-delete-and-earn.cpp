class Solution {
public:
    int solve(int i,int mx,vector<int>&pref,vector<int>&dp){
        if(i>mx){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int take=pref[i]+solve(i+2,mx,pref,dp);
        int skip=solve(i+1,mx,pref,dp);
        return dp[i]=max(take,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>pref(mx+1);
        for(int ele:nums){
            pref[ele]+=ele;
        }
        vector<int>dp(mx+1,-1);
        return solve(0,mx,pref,dp);
    }
};