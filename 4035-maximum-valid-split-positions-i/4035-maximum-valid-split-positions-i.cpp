class Solution {
public:
    int helper(vector<int>&nums){
        int n=nums.size();
        vector<int>pref(n),suff(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=__gcd(pref[i-1],nums[i]);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) suff[i]=__gcd(suff[i+1],nums[i]);
        int splits=0;
        for(int i=0;i<n-1;i++){
            int curr=pref[i];
            int rem=suff[i+1];
            if(curr==rem) splits++;
        }
        return splits;
    }
    int maxValidSplits(vector<int>& nums) {
        int max_splits=helper(nums);
        for(int i=0;i<nums.size();i++){
            int rm_idx=i;
            vector<int>new_nums;
            for(int j=0;j<rm_idx;j++) new_nums.push_back(nums[j]);
            for(int j=rm_idx+1;j<nums.size();j++) new_nums.push_back(nums[j]);
            max_splits=max(max_splits,helper(new_nums));
        }
        return max_splits;
    }
};