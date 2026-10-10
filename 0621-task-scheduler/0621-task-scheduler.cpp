class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>freq(26);
        for(char c:tasks) freq[c-'A']++;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        int ans=0,time=0;
        queue<pair<int,int>>q;
        while(!pq.empty() || !q.empty()){
            while(!q.empty() && q.front().second<=time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int cnt=pq.top();
                cnt--;
                pq.pop();
                if(cnt>0)q.push({cnt,time+n+1});
            }
            time++;
        }
        return time;
    }
};