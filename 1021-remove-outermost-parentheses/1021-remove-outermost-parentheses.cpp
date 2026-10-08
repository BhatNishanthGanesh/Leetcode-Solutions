class Solution {
public:
    string removeOuterParentheses(string s) {
        int dep=0;
        string ans="";
        for(char c:s){
            if(c=='('){
                if(dep>0) ans+='(';
                dep++;
            }else{
                dep--;
                if(dep>0) ans+=')';
            }
        }
        return ans;
    }
};