class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>v;
        int n=tasks.size();
        for(int i=0;i<n;i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
        long long time=0;
        while(i<n || !pq.empty()){
            if(pq.empty()){
                time=max(time,1ll*tasks[i][0]);
            }
            while(i<n && tasks[i][0]<=time){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            auto [ptime,idx]=pq.top();
            pq.pop();
            time+=ptime;
            v.push_back(idx);
        }
        return v;
    }
};