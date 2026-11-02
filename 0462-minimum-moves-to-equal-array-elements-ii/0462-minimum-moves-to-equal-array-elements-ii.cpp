class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int med=0;
        if(n&1) med=nums[n/2];
        else med=(nums[(n/2)-1]+(nums[n/2]))/2;
        int sum=0;
        for(int ele:nums) sum+=abs(med-ele);
        return sum;
    }
};