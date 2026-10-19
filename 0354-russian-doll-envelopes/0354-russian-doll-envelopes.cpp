class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int>v;
        for(auto &e:env) v.push_back(e[1]);
        int n=v.size();
        vector<int>ans;
        ans.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]>ans.back()){
                ans.push_back(v[i]);
            }else{
                int idx=lower_bound(ans.begin(),ans.end(),v[i])-ans.begin();
                ans[idx]=v[i];
            }
        }
        return ans.size();
    }
};