class Solution {
public:
    bool solve(int idx,vector<int>&nums,int k,int target,int sum,int mask,vector<int>&dp){
        int currMask=mask;
        if(target==0){
            if(k==1) return true;
            return solve(0,nums,k-1,sum,sum,mask,dp);
        }
        if(target<0 || idx>=nums.size()) return false;
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<nums.size();i++){
            if(currMask&(1<<i)) continue;
            currMask|=(1<<i);
            if(solve(i+1,nums,k,target-nums[i],sum,currMask,dp)) return dp[mask]=true;
            currMask&=~(1<<i);
        }
        return dp[mask]=false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%k!=0) return false;
        int target=tot/k;
        vector<int>dp(1<<n,-1);
        return solve(0,nums,k,target,target,0,dp);
    }
};