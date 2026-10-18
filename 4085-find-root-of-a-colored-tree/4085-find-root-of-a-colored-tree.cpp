class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        unordered_map<char,char>mp={{'R','B'},{'B','W'},{'W','R'}};
        vector<int>indeg(n),outdeg(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int u_colors=colors[u];
            int v_colors=colors[v];
            if(u_colors==v_colors) return -1;
            if(mp[u_colors]==v_colors){
                outdeg[u]++;
                indeg[v]++;
            }else{
                outdeg[v]++;
                indeg[u]++;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(indeg[i]>1) return -1;
            if(outdeg[i]>2) return -1;
            if(indeg[i]==0) root=i;
        }
        return root;
    }
};