class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        int mx=(n+1)/2;
        int mn=n-mx;
        for(int &ele:nums){
            if(ele<0) ele=-ele;
        }
        vector<int>max_ele=nums;
        sort(max_ele.rbegin(),max_ele.rend());
        long long sum=0;
        for(int i=0;i<mx;i++){
            sum+=1ll*max_ele[i]*max_ele[i];
        }
        vector<int>min_ele=nums;
        sort(min_ele.begin(),min_ele.end());
        for(int i=0;i<mn;i++){
            sum-=1ll*min_ele[i]*min_ele[i];
        }
        return sum;
    }
};