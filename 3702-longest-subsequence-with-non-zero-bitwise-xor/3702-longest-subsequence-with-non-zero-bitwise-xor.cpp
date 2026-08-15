class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int cntz=count(nums.begin(),nums.end(),0);
        if(cntz==n) return 0;
        int xr=0;
        for(int ele:nums) xr^=ele;
        if(xr>0) return n;
        return n-1;
    }
};