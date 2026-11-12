class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt=1,mx1=0,mx2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                cnt++;
            }else{
                mx1=max(mx1,cnt);
                cnt=1;
            }
        }
        mx1=max(mx1,cnt);
        cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                cnt++;
            }else{
                mx2=max(mx2,cnt);
                cnt=1;
            }
        }
        mx2=max(mx2,cnt);
        return max(mx1,mx2);
    }
};