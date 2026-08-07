class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int left=0,ans=0;
        for(int right=0;right<s.length();right++){
            while(left<=right && mp.count(s[right])){
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
            }
            mp[s[right]]++;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};