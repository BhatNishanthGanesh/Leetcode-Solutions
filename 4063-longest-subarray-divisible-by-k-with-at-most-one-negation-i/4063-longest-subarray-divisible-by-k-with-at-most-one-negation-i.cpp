class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++){
            int sum=0;
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                int rem=(sum%k+k)%k;
                if(rem==0) mx=max(mx,j-i+1);
                int x=(2*nums[j]%k+k)%k;
                st.insert(x);
                if(st.count(rem)) mx=max(mx,j-i+1);
            }
        }
        return mx;
    }
};