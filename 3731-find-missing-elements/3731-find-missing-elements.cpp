class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int sm=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>ans;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=sm;i<=mx;i++){
            if(st.count(i)) continue;
            ans.push_back(i);
        }
        return ans;
    }
};