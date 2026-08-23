class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int>st(nums.begin(),nums.end());
        vector<int>missing;
        for(int i=lower;i<=upper;i++){
            if(!st.count(i)) missing.push_back(i);
        }
        vector<vector<int>>ans;
        if(missing.empty()) return ans;
        int start=missing[0],end=missing[0];
        for(int i=1;i<missing.size();i++){
            if(missing[i]-missing[i-1]!=1){
                ans.push_back({start,end});
                start=missing[i];
            }
            end=missing[i];
        }
        ans.push_back({start,end});
        return ans;
    }
};