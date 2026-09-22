class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        for(auto it:mp){
            vector<string>v;
            for(int i=0;i<it.second.size();i++){
                v.push_back(strs[it.second[i]]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};