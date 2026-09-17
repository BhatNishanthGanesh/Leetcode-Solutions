class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>mini(n,INT_MAX);
        int l=0,sum=0,len=INT_MAX,ans=INT_MAX;
        for(int r=0;r<n;r++){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l++];
            }
            if(sum==target){
                int curr=r-l+1;
                if(l>0 && mini[l-1]!=INT_MAX){
                    ans=min(ans,curr+mini[l-1]);
                }
                len=min(len,curr);
            }
            mini[r]=len;
        }
        return ans==INT_MAX?-1:ans;
    }
};