class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<long long>pref(n+1);
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+nums[i-1];
        int i=0,ans=INT_MAX;
        for(int i=0;i<=n;i++){
            while(!dq.empty() && pref[i]-pref[dq.front()]>=k){
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && pref[i]<=pref[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans==INT_MAX?-1:ans;
    }
};