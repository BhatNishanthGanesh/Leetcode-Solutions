class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int num=nums1[0];
        if((num&1)!=1){
            for(int ele:nums1){
                if(ele&1) return false;
            }
        }
        return true;
    }
};