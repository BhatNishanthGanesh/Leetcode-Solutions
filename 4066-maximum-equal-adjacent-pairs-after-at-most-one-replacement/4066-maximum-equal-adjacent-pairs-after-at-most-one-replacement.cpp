class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) cnt++;
        }
        unordered_map<string,int>mp;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                int a=nums[i];
                int b=nums[i-1];
                if(a>b) swap(a,b);
                mp[to_string(a)+' '+to_string(b)]++;
            }
        }
        int mx=0;
        for(auto it:mp) mx=max(mx,it.second);
        return cnt+mx;
    }
};