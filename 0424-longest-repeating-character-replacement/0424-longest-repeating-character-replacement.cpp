class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi=0;
        for(int i=0;i<26;i++){
            int l=0;
            char ch='A'+i;
            bool f=false;
            for(char c:s){
                if(c==ch){
                    f=true;
                    break;
                }
            }
            if(!f) continue;
            unordered_map<char,int>mp;
            int temp=k;
            for(int r=0;r<s.length();r++){
                mp[s[r]]++;
                if(s[r]!=ch) temp--;
                if(temp==-1){
                    while(l<=r && temp<0){
                        mp[s[l]]--;
                        if(s[l]!=ch) temp++;
                        if(mp[s[l]]==0) mp.erase(s[l]);
                        l++;
                    }
                }
                if(temp>=0)maxi=max(maxi,r-l+1);
            }
        }
        return maxi;
    }
};