class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum=0;
        for(string word:words){
            unordered_map<char,int>mp;
            for(char c:chars) mp[c]++;
            bool f=true;
            for(char c:word){
                if(mp.count(c)){
                    mp[c]--;
                    if(mp[c]==0) mp.erase(c);
                }
                else{
                    f=false;
                    break;
                }
            }
            if(f) sum+=word.length();
        }
        return sum;
    }
};