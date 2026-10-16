class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>sum;
        int l=0,curr=0;
        for(int r=0;r<nums.size();r++){
            curr+=nums[r];
            if(r-l+1==k){
                sum.push_back(curr);
                curr-=nums[l];
                l++;
            }
        }
        int n=sum.size();
        vector<int>left(n),right(n);
        left[0]=0;
        for(int i=1;i<n;i++){
            left[i]=(sum[i]>sum[left[i-1]])?i:left[i-1];
        }
        right[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            right[i]=(sum[i]>=sum[right[i+1]])?i:right[i+1];
        }
        vector<int>ans(3);
        int best=0;
        for(int i=k;i+k<n;i++){
            int l=left[i-k];
            int r=right[i+k];
            int tot=sum[l]+sum[i]+sum[r];
            if(tot>best){
                best=tot;
                ans={l,i,r};
            }
        }
        return ans;
    }
};