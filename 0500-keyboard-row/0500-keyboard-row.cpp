class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int>freq={1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
        vector<string>ans;
        for(string word:words){
            bool poss=true;
            int num=freq[tolower(word[0])-'a'];
            for(char c:word){
                if(freq[tolower(c)-'a']!=num){
                    poss=false;
                    break;
                }
            }
            if(poss) ans.push_back(word);
        }
        return ans;
    }
};