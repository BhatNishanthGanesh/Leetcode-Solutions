class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st,st2;
        for(int ele:nums1) st.insert(ele);
        for(int ele:nums2){
            if(st.count(ele)) st2.insert(ele);
        }
        vector<int>ans(st2.begin(),st2.end());
        return ans;
    }
};