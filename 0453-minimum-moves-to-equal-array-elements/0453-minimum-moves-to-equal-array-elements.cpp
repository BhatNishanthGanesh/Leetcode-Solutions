class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int sum=0;
        for(int ele:nums) sum+=(ele-mn);
        return sum;
    }
};