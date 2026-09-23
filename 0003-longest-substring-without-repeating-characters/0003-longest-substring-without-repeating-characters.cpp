class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0;
        int l=0;
        unordered_map<char,int>mp;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            while(l<=r && mp[s[r]]>1){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};