class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>f1(128),f2(128);
        for(char c:t) f1[c]++;
        int req=0;
        for(int i=0;i<128;i++){
            if(f1[i]>0) req++;
        }
        int l=0,curr=0,start=-1,len=INT_MAX;
        for(int r=0;r<s.length();r++){
            char c=s[r];
            f2[c]++;
            if(f1[c]>0 && f1[c]==f2[c]) curr++;
            while(l<=r && curr==req){
                if(len>r-l+1){
                    len=r-l+1;
                    start=l;
                }
                f2[s[l]]--;
                if(f1[s[l]]>0 && f2[s[l]]<f1[s[l]]) curr--;
                l++;
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};