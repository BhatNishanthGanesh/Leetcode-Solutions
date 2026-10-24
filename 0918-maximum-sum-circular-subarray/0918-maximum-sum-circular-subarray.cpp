class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot=0,currMax=0,currMin=0,maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            tot+=nums[i];
            currMax=max(nums[i],currMax+nums[i]);
            maxi=max(maxi,currMax);
            currMin=min(nums[i],currMin+nums[i]);
            mini=min(mini,currMin);
        }
        return maxi<0?maxi:max(maxi,tot-mini);
    }
};