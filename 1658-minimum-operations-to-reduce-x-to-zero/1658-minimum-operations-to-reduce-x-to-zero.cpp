class Solution {
public:
    int maxSubarrayk(vector<int>&nums,int k){
        int n=nums.size();
        int maxi=INT_MIN,l=0,sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(l<=r && sum>k){
                sum-=nums[l++];
            }
            if(sum==k) maxi=max(maxi,r-l+1);
        }
        return maxi==INT_MIN?-1:maxi;
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        int k=tot-x;
        int maxi=maxSubarrayk(nums,k);
        if(maxi==-1) return -1;
        return n-maxi;
    }
};