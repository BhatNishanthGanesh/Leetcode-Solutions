class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int len=0,l=0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            while(l<=r && mp[s[r]]>2){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};