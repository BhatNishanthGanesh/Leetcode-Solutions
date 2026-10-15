class Solution {
public:
    bool func(vector<vector<int>>&heights,int effort){
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            if(x==n-1 && y==m-1) return true;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(vis[nx][ny]) continue;
                int diff=abs(heights[nx][ny]-heights[x][y]);
                if(diff<=effort){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        return vis[n-1][m-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=0,high=1e6;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(heights,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};