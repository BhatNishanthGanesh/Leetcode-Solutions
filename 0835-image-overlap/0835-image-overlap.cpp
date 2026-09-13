class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>>v;
        int cnt=0;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1.size();j++){
                if(img1[i][j]==1) v.push_back({i,j});
                if(img1[i][j]==1 && img2[i][j]==1) cnt++;
            }
        }
        int mx=cnt;
        if(v.empty()) return 0;
        int n=img1.size();
        for(int diff_x=-(n-1);diff_x<n;diff_x++){
            for(int diff_y=-(n-1);diff_y<n;diff_y++){
                int cnt=0;
                for(int k=0;k<v.size();k++){
                    int x=v[k][0]+diff_x;
                    int y=v[k][1]+diff_y;
                    if(x<0 || x>=img2.size() || y<0 || y>=img2[0].size()) continue;
                    if(img2[x][y]==1) cnt++;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};