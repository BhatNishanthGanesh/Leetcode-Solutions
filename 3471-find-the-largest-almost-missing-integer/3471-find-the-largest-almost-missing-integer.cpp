class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            unordered_set<int>st;
            for(int j=0;j<k;j++){
                if(st.count(nums[i+j])) continue;
                st.insert(nums[i+j]);
                mp[nums[i+j]]++;
            }
        }
        int mx=-1;
        for(auto it:mp){
            if(it.second==1) mx=max(mx,it.first);
        }
        return mx;
    }
};