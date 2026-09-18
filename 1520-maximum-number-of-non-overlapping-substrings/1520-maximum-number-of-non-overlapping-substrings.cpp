class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();
        vector<int>first(26,n);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            first[c]=min(first[c],i);
            last[c]=i;
        }
        vector<pair<int,int>>intervals;
        for(int c=0;c<26;c++){
            if(last[c]==-1) continue;
            int l=first[c];
            int r=last[c];
            bool f=true;
            for(int i=l;i<=r;i++){
                int x=s[i]-'a';
                if(first[x]<l){
                    f=false;
                    break;
                }
                r=max(r,last[x]);
            }
            if(f) intervals.push_back({r,l});
        }
        sort(intervals.begin(),intervals.end());
        int prev=-1;
        vector<string>ans;
        for(auto[r,l]:intervals){
            if(l>prev){
                ans.push_back(s.substr(l,r-l+1));
                prev=l;
            }
        }
        return ans;
    }
};