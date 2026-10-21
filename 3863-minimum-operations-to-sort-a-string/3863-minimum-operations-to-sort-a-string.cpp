class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        if(is_sorted(s.begin(),s.end())) return 0;
        if(n==2) return -1;
        char mx=s[0],mn=s[0];
        for(char c:s){
            if(c>=mx){
                mx=c;
            }
            if(c<=mn){
                mn=c;
            }
        }
        int mxcnt=0,mncnt=0;
        for(char c:s){
            if(c==mx) mxcnt++;
            if(c==mn) mncnt++;
        }
        if(s[0]==mn || s[n-1]==mx) return 1;
        if(s[0]!=mx && s[n-1]!=mn) return 2;
        if(s[0]==mx && s[n-1]==mn){
            if(mxcnt==1 && mncnt==1) return 3;
            return 2;
        }
        return 2;
    }
};