class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        for(int ele:nums){
            if(ele==val) continue;
            nums[left++]=ele;
        }
        return left;
    }
};