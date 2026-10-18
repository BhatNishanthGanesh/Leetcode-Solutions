class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int x=0,y=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            int nx=x;
            int ny=y;
            if(grid[nx][ny]=='R') ny++;
            else if(grid[nx][ny]=='D') nx++;
            else if(grid[nx][ny]=='L') ny--;
            else if(grid[nx][ny]=='U') nx--;
            if(nx<0 || nx>=n || ny<0 || ny>=m) return {x,y};
            if(vis[nx][ny]) return {x,y};
            vis[nx][ny]=true;
            q.push({nx,ny});
        }
        return {};
    }
};