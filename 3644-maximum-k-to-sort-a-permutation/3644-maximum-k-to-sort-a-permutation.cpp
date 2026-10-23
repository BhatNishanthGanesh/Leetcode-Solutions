class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int i=0,n=nums.size();
        int idx=-1;
        while(i<n){
            if(nums[i]==v[i]) i++;
            else{
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        int cnt=nums[idx];
        for(int j=idx;j<n;j++){
            if(nums[j]!=v[j]){
                cnt&=nums[j];
            }
        }
        return cnt;
    }
};