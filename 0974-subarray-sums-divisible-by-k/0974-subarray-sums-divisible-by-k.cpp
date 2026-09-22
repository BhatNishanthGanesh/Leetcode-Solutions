class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int pref=0,cnt=0;
        mp[0]=1;
        for(int ele:nums){
            pref+=ele;
            int req=(pref%k+k)%k;
            if(mp.count(req)) cnt+=mp[req];
            mp[req]++;
        }
        return cnt;
    }
};