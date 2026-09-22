class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int ele:nums){  
            mp[ele]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp) v.push_back({it.first,it.second});
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};