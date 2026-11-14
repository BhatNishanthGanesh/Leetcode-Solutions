class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini=INT_MAX;
        for(int i=l;i<=r;i++){
            int sum=0;
            for(int j=0;j<i;j++){
                sum+=nums[j];
            }
            if(sum>0) mini=min(mini,sum);
            int l=0;
            for(int j=i;j<nums.size();j++){
                sum-=nums[l++];
                sum+=nums[j];
                if(sum>0) mini=min(mini,sum);
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};