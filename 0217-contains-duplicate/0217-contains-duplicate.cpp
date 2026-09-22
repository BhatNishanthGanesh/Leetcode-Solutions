class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int ele:nums){
            if(st.count(ele)) return true;
            st.insert(ele);
        }
        return false;
    }
};