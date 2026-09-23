class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int mini=INT_MAX;
        int k=tot-x;
        int sum=0,l=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(l<=r && sum>k){
                sum-=nums[l++];
            }
            if(sum==k) mini=min(mini,n-(r-l+1));
        }
        return mini==INT_MAX?-1:mini;
    }
};