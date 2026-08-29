class DSU{
    public:
        vector<int>size,parent;
        DSU(int n){
            size.assign(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int UltParent(int node){
            if(node==parent[node]) return node;
            return parent[node]=UltParent(parent[node]);
        }
        void RBC(int a,int b){
            int ult_a=UltParent(a);
            int ult_b=UltParent(b);
            if(ult_a==ult_b) return;
            if(size[ult_a]<=size[ult_b]){
                parent[ult_a]=ult_b;
                size[ult_b]+=size[ult_a];
            }else{
                parent[ult_b]=ult_a;
                size[ult_a]+=size[ult_b];
            }
        }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        DSU ds(nums.size());
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            int v1=v[i-1].first;
            int idx1=v[i-1].second;
            int v2=v[i].first;
            int idx2=v[i].second;
            if(v2-v1<=limit){
                ds.RBC(idx1,idx2);
            }
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<v.size();i++){
            int idx=v[i].second;
            int parent=ds.UltParent(idx);
            mp[parent].push_back(idx);
        }
        for(auto &it:mp) sort(it.second.begin(),it.second.end());
        unordered_map<int,int>pos;
        vector<int>ans=nums;
        for(int i=0;i<v.size();i++){
            int parent=ds.UltParent(v[i].second);
            int idx=mp[parent][pos[parent]];
            ans[idx]=v[i].first;
            pos[parent]++;
        }
        return ans;
    }
};