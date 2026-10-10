class Solution {
public:
    const int mod=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n+1);
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+nums[i-1];
        stack<long long>st;
        vector<long long>pse,nse;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()) pse.push_back(-1);
            else{
                pse.push_back(st.top());
            }
            st.push(i);
        }
        stack<long long>().swap(st);
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()) nse.push_back(nums.size());
            else{
                nse.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nse.begin(),nse.end());
        long long mx=0;
        for(int i=0;i<nums.size();i++){
            long long L=pse[i]+1;
            long long R=nse[i]-1;
            long long sum=pref[R+1]-pref[L];
            mx=max(mx,nums[i]*sum);
        }
        return mx%mod;
    }
};