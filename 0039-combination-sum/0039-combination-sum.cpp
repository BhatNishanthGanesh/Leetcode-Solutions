class Solution {
public:
    void solve(int i,vector<vector<int>>&v,vector<int>&temp,vector<int>&candidates,int target){
        if(i>=candidates.size() || target<0) return;
        if(target==0){
            v.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        solve(i,v,temp,candidates,target-candidates[i]);
        temp.pop_back();
        solve(i+1,v,temp,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,v,temp,candidates,target);
        return v;
    }
};