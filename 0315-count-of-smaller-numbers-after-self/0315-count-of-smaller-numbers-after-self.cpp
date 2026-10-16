class Solution {
public:
    void mergeSort(int low,int mid,int high,vector<int>&nums,vector<int>&v,vector<int>&ans){
        int l=0,r=0;
        int rightCount=0;
        vector<int>L(mid-low+1),R(high-mid);
        for(int i=low;i<=mid;i++) L[l++]=v[i];
        for(int i=mid+1;i<=high;i++) R[r++]=v[i];
        l=0,r=0;
        int k=low;
        while(l<L.size() && r<R.size()){
            if(nums[L[l]]<=nums[R[r]]){
                ans[L[l]]+=rightCount;
                v[k++]=L[l++];
            }else{
                v[k++]=R[r++];
                rightCount++;
            }
        }
        while(l<L.size()){
            ans[L[l]]+=rightCount;
            v[k++]=L[l++];
        }
        while(r<R.size()){
            v[k++]=R[r++];
            rightCount++;
        }
        
    }
    void merge(int low,int high,vector<int>&nums,vector<int>&v,vector<int>&ans){
        if(low>=high) return;
        int mid=low+(high-low)/2;
        merge(low,mid,nums,v,ans);
        merge(mid+1,high,nums,v,ans);
        mergeSort(low,mid,high,nums,v,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>v;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++) v.push_back(i);
        merge(0,nums.size()-1,nums,v,ans);
        return ans;
    }
};