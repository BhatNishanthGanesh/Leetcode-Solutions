class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>pref(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pref[i]=sum;
        }
        return pref;
    }
};