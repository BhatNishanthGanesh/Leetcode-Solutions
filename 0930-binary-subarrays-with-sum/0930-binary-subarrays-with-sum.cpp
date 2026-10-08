class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int pref=0,cnt=0;
        for(int ele:nums){
            pref+=ele;
            if(mp.count(pref-goal)) cnt+=mp[pref-goal];
            mp[pref]++;
        }
        return cnt;
    }
};