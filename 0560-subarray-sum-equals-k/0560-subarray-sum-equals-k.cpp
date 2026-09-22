class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int pref=0;
        int cnt=0;
        for(int ele:nums){
            pref+=ele;
            if(mp.count(pref-k)) cnt+=mp[pref-k];
            mp[pref]++;
        }
        return cnt;
    }
};