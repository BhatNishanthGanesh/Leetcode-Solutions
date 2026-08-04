class Solution {
public:
    void expand(int l,int r,string s,int &start,int &maxlen){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            if(r-l+1>maxlen){
                maxlen=r-l+1;
                start=l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        int start=0,maxlen=1;
        for(int i=0;i<s.length();i++){
            expand(i,i,s,start,maxlen);
            expand(i,i+1,s,start,maxlen);
        }
        return s.substr(start,maxlen);
    }
};