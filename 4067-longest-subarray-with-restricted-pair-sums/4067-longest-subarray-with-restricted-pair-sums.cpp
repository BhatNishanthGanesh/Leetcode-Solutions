class Solution {
public:
    bool check(int k,vector<int>&freq){
        for(int a=1;a<=k;a++){
            if((a==k-a && freq[a]>=2) || (a!=k-a && freq[a]>0 && freq[k-a]>0)) return 1;
        }
        for(int a=k+1;a<=500;a++){
            if((k==a-k && freq[k]>=2 && freq[a]>0) || (k!=a-k && freq[a]>0 && freq[a-k]>0)) return 1;
        }
        return 0;
    }
    int maxSubarray(vector<int>& nums) {
        int mx=0,n=nums.size();
        vector<int>freq(501);
        int l=0;
        for(int r=0;r<n;r++){
            freq[nums[r]]++;
            while(l<=r && check(nums[r],freq)){
                freq[nums[l]]--;
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};