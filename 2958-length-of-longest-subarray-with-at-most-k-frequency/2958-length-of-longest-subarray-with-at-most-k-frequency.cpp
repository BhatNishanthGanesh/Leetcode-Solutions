class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left=0,ans=0;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            while(left<=right && mp[nums[right]]>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};