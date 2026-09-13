class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ops=0;
        stack<int>st;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<st.top()){
                mp[st.top()]--;
                st.pop();
            }
            ops+=(st.size()-mp[nums[i]]);
            st.push(nums[i]);
            mp[nums[i]]++;
        }
        return ops;
    }
};