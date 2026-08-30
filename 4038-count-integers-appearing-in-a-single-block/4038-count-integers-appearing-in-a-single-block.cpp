class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt=0;
        int i=0;
        vector<bool>vis(101,true);
        while(i<nums.size()){
            bool f=true;
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[i]) j++;
            int idx=j;
            while(j<nums.size()){
                if(nums[j]==nums[i]){
                    f=false;
                    vis[j]=false;
                }
                j++;
            }
            if(f && vis[i]) cnt++;
            i=idx;
        }
        return cnt;
    }
};