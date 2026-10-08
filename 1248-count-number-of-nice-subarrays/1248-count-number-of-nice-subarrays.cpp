class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int cnt=0;
        unordered_map<int,int>mp;
        int l=0,odd=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(nums[i]&1) odd++;
            while(l<=i && odd>k){
                mp[nums[l]]--;
                if(nums[l]&1) odd--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            cnt+=(i-l+1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};