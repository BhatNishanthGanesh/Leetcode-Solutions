class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int cnt=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                cnt&=nums[i];
                if(cnt==0) return 0;
            }
        }
        return max(cnt,0);
    }
};