class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool inc=true,dec=true;
        for(int i=0;i<n;i++){
            int next=nums[(i+1)%n];
            if(next!=(nums[i]+1)%n) inc=false;
            if(next!=(nums[i]-1+n)%n) dec=false;
        }
        if(!inc && !dec) return -1;
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                idx=i;
                break;
            }
        }
        int ans=INT_MAX;
        if(inc) ans=min(ans,min(idx,2+(n-idx)));
        if(dec) ans=min(ans,1+min((idx+1)%n,n-1-idx));
        return ans;
    }
};