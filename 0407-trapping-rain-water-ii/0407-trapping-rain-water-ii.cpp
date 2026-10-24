class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        int n=heightMap.size(),m=heightMap[0].size();
        if(n<3 || m<3) return 0;
        using T=tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>>pq;
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            pq.push({heightMap[i][0],i,0}); visit[i][0]=true;
            pq.push({heightMap[i][m-1],i,m-1}); visit[i][m-1]=true;
        }
        for(int i=0;i<m;i++){
            if(!visit[0][i]) pq.push({heightMap[0][i],0,i}); visit[0][i]=true;
            if(!visit[n-1][i]) pq.push({heightMap[n-1][i],n-1,i}); visit[n-1][i]=true;
        }
        int res=0;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!pq.empty()){
            auto [h,r,c]=pq.top();
            pq.pop();
            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr<0 || nr>=n || nc<0 || nc>=m || visit[nr][nc]) continue;
                visit[nr][nc]=true;
                int nh=heightMap[nr][nc];
                if(nh<h) res+=h-nh;
                pq.push({max(nh,h),nr,nc});
            }
        }
        return res;
    }
};