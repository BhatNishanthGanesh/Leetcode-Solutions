class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        string res="";
        string curr="";
        bool f=false;
        for(char c:s){
            if(c=='('){
                f=true;
                continue;
            }
            if(c==')'){
                if(mp.count(curr)){
                    res+=mp[curr];
                }else{
                    res+='?';
                }
                curr="";
                f=false;
                continue;
            }
            if(f){
                curr+=c;
            }else{
                res+=c;
            }
        }
        return res;
    }
};