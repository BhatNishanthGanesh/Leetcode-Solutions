class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int>ans,len;
        ans.push_back(nums[0]);
        len.push_back(1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=ans.back()){
                ans.push_back(nums[i]);
                len.push_back(ans.size());
            }else{
                int idx=upper_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
                len.push_back(idx+1);
            }
        }
        return len;
    }
};