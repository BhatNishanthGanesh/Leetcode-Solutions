class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int &ele:nums){
            if(ele==0) ele=-1;
        }
        int mx=0,pref=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            pref+=nums[i];
            if(mp.count(pref)) mx=max(mx,i-mp[pref]);
            if(!mp.count(pref)) mp[pref]=i;
        }
        return mx;
    }
};