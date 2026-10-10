class Solution {
public:
    int func(vector<int>&nums,int mid){
        int sum=0,split=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }else{
                split++;
                sum=nums[i];
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(func(nums,m)>k){
                l=m+1;
            }else{
                ans=m;
                h=m-1;
            }
        }
        return ans;
    }
};