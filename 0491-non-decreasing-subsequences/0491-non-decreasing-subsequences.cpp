class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&v){
        if(temp.size()>=2){
            v.push_back(temp);
        }
        unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){
            if(st.count(nums[i])) continue;
            if(!temp.empty() && nums[i]<temp.back()) continue;
            st.insert(nums[i]);
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,v);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        solve(0,nums,temp,v);
        return v;
    }
};