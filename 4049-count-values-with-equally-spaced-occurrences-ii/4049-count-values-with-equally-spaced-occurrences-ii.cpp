class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second.size()>=3){
                int diff=it.second[1]-it.second[0];
                bool f=true;
                for(int i=2;i<it.second.size();i++){
                    if(it.second[i]-it.second[i-1]!=diff){
                        f=false;
                        break;
                    }
                }
                if(f) cnt++;
            }
        }
        return cnt;
    }
};