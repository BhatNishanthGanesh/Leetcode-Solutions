class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0,mx=0;
        unordered_map<int,int>mp;
        int l=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            mp[nums[r]]++;
            while(l<=r && mp[nums[r]]>1){
                mp[nums[l]]--;
                sum-=nums[l];
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            mx=max(mx,sum);
        }
        return mx;
    }
};