class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int ans=0;
        for(int ele:nums){
            mp[ele+1]=mp[ele]+1;
            mp[ele]=mp[ele-1]+1;
            ans=max({ans,mp[ele],mp[ele+1]});
        }
        return ans;
    }
};