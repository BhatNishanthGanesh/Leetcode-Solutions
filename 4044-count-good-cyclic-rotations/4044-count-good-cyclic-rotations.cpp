class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int ls=0;
        int rs=n/2;
        long long tot=accumulate(nums.begin(),nums.end(),0ll);
        long long leftSum=0;
        for(int i=0;i<n/2;i++) leftSum+=nums[i];
        long long rightSum=tot-leftSum;
        int cnt=(leftSum>rightSum)?1:0;
        for(int i=1;i<n;i++){
            rightSum+=nums[ls];
            leftSum-=nums[ls];
            rightSum-=nums[rs];
            leftSum+=nums[rs];
            if(leftSum>rightSum) cnt++;
            ls=(ls+1)%n;
            rs=(rs+1)%n;
        }
        return cnt;
    }
};