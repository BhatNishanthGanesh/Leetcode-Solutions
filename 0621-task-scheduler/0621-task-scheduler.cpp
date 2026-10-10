class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>pq;
        vector<int>freq(26);
        for(char c:tasks) freq[c-'A']++;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push({freq[i],'A'+i});
        }
        int ans=0,time=0;
        queue<tuple<int,char,int>>q;
        while(!pq.empty() || !q.empty()){
            while(!q.empty() && get<2>(q.front())<=time){
                pq.push({get<0>(q.front()),get<1>(q.front())});
                q.pop();
            }
            if(!pq.empty()){
                auto [cnt,ch]=pq.top();
                cnt--;
                pq.pop();
                if(cnt>0)q.push({cnt,ch,time+n+1});
            }
            time++;
        }
        return time;
    }
};