class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>window(128),target(128);
        for(char c:t) target[c]++;
        int req=0;
        for(int i=0;i<128;i++){
            if(target[i]>0) req++;
        }
        int l=0,start=-1,len=INT_MAX,curr=0;
        for(int r=0;r<s.length();r++){
            window[s[r]]++;
            if(target[s[r]]>0 && target[s[r]]==window[s[r]]){
                curr++;
            }
            while(l<=r && curr==req){
                if(len>r-l+1){
                    len=r-l+1;
                    start=l;
                }
                if(target[s[l]]>0 && target[s[l]]==window[s[l]]){
                    curr--;
                }
                window[s[l]]--;
                l++;
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};