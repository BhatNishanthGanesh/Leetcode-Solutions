class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;
        int n=profits.size();
        vector<pair<int,int>>projects;
        for(int i=0;i<n;i++) projects.push_back({capital[i],profits[i]});
        sort(projects.begin(),projects.end());
        int i=0;
        while(k>0){
            while(i<n && projects[i].first<=w){
                pq.push(projects[i].second);
                i++;
            }
            if(pq.empty()) break;
            int p=pq.top();
            pq.pop();
            w+=p;
            k--;
        }
        return w;
    }
};