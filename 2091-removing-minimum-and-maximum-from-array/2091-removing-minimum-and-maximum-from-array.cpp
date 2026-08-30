class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());

        auto mn_it=find(nums.begin(),nums.end(),mn);
        auto mx_it=find(nums.begin(),nums.end(),mx);

        int mn_idx=distance(nums.begin(),mn_it);
        int mx_idx=distance(nums.begin(),mx_it);

        int mini=INT_MAX;
        // both start from front
        mini=min(mini,max(mn_idx+1,mx_idx+1));
        // both start from end
        mini=min(mini,max(n-mn_idx,n-mx_idx));
        // from opp ends
        mini=min(mini,min(mn_idx+1,n-mn_idx)+min(mx_idx+1,n-mx_idx));

        return mini;
    }
};