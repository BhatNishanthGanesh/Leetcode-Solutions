class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int cnt=0;
        int l=0;
        unordered_map<int,int>mp;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(l<=r && mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};